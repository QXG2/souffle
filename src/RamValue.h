/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2013, 2014, Oracle and/or its affiliates. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file RamValue.h
 *
 * Defines a class for evaluating values in the Relational Algebra Machine
 *
 ************************************************************************/

#pragma once

#include "FunctorOps.h"
#include "RamNode.h"
#include "RamRelation.h"
#include "SymbolTable.h"
//#include "RamLatticeAssociation.h"

#include <algorithm>
#include <array>
#include <sstream>
#include <string>

#include <cstdlib>
#include <utility>

namespace souffle {

/**
 * Abstract class for describing scalar values in RAM
 */
class RamValue : public RamNode {
public:
	RamValue(RamNodeType type) : RamNode(type) {}

	/** Create clone */
	RamValue* clone() const override = 0;
};

// TODO (azreika): create a common abstract base class for RAM operators

/**
 * Operator that represents an intrinsic (built-in) functor
 */
class RamIntrinsicOperator : public RamValue {
private:
	/** Operation symbol */
	FunctorOp operation;

	/** Arguments of the function */
	std::vector<std::unique_ptr<RamValue>> arguments;

public:
	template <typename... Args>
	RamIntrinsicOperator(FunctorOp op, Args... args) : RamValue(RN_IntrinsicOperator), operation(op) {
		std::unique_ptr<RamValue> tmp[] = {std::move(args)...};
		for (auto& cur : tmp) {
			arguments.push_back(std::move(cur));
		}
	}

	RamIntrinsicOperator(FunctorOp op, std::vector<std::unique_ptr<RamValue>> args)
	: RamValue(RN_IntrinsicOperator), operation(op), arguments(std::move(args)) {}

	/** Print */
	void print(std::ostream& os) const override {
		if (isInfixFunctorOp(operation)) {
			os << "(";
			os << join(arguments, getSymbolForFunctorOp(operation), print_deref<std::unique_ptr<RamValue>>());
			os << ")";
		} else {
			os << getSymbolForFunctorOp(operation);
			os << "(";
			os << join(arguments, ",", print_deref<std::unique_ptr<RamValue>>());
			os << ")";
		}
	}

	/** Get operator symbol */
	FunctorOp getOperator() const {
		return operation;
	}

	/** Get argument values */
	std::vector<RamValue*> getArguments() const {
		return toPtrVector(arguments);
	}

	/** Get i-th argument value */
	const RamValue* getArgument(size_t i) const {
		assert(i >= 0 && i < arguments.size() && "argument index out of bounds");
		return arguments[i].get();
	}

	/** Get number of arguments */
	size_t getArgCount() const {
		return arguments.size();
	}

	/** Obtain list of child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		std::vector<const RamNode*> res;
		for (const auto& cur : arguments) {
			res.push_back(cur.get());
		}
		return res;
	}

	/* Clone */
	RamIntrinsicOperator* clone() const override {
		std::vector<std::unique_ptr<RamValue>> argsCopy;
		for (auto& arg : arguments) {
			argsCopy.emplace_back(arg->clone());
		}
		auto res = new RamIntrinsicOperator(operation, std::move(argsCopy));
		return res;
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {
		for (auto& arg : arguments) {
			arg = map(std::move(arg));
		}
	}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamIntrinsicOperator*>(&node));
		const auto& other = static_cast<const RamIntrinsicOperator&>(node);
		return getOperator() == other.getOperator() && equal_targets(arguments, other.arguments);
	}
};

/**
 * Operator that represents an extrinsic (user-defined) functor
 */
class RamUserDefinedOperator : public RamValue {
private:
	/** Arguments of user defined operator */
	std::vector<std::unique_ptr<RamValue>> arguments;

	/** Name of user-defined operator */
	const std::string name;

	/** Argument types */
	const std::string type;

public:
	RamUserDefinedOperator(std::string n, std::string t, std::vector<std::unique_ptr<RamValue>> args)
: RamValue(RN_UserDefinedOperator), arguments(std::move(args)), name(std::move(n)),
  type(std::move(t)) {}

	/** Print */
	void print(std::ostream& os) const override {
		os << "@" << name << "_" << type << "(";
		os << join(
				arguments, ",", [](std::ostream& out, const std::unique_ptr<RamValue>& arg) { out << *arg; });
		os << ")";
	}

	/** Get argument values */
	std::vector<RamValue*> getArguments() const {
		return toPtrVector(arguments);
	}

	/** Get i-th argument value */
	const RamValue* getArgument(size_t i) const {
		assert(i >= 0 && i < arguments.size() && "argument index out of bounds");
		return arguments[i].get();
	}

	/** Get number of arguments */
	size_t getArgCount() const {
		return arguments.size();
	}

	/** Get operator name */
	const std::string& getName() const {
		return name;
	}

	/** Get types of arguments */
	const std::string& getType() const {
		return type;
	}

	/** Obtain list of child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		std::vector<const RamNode*> res;
		for (const auto& cur : arguments) {
			res.push_back(cur.get());
		}
		return res;
	}

	/** Create clone */
	RamUserDefinedOperator* clone() const override {
		RamUserDefinedOperator* res = new RamUserDefinedOperator(name, type, {});
		for (auto& cur : arguments) {
			RamValue* arg = cur->clone();
			res->arguments.emplace_back(arg);
		}
		return res;
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {
		for (auto& arg : arguments) {
			arg = map(std::move(arg));
		}
	}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamUserDefinedOperator*>(&node));
		const auto& other = static_cast<const RamUserDefinedOperator&>(node);
		return name == other.name && type == other.type && equal_targets(arguments, other.arguments);
	}
};

/**
 * Access element from the current tuple in a tuple environment
 */
class RamElementAccess : public RamValue {
private:
	/** Identifier for the tuple */
	size_t identifier;

	/** Element number */
	size_t element;

	/** Relation */
	std::unique_ptr<RamRelationReference> relation;

public:
	RamElementAccess(size_t ident, size_t elem, std::unique_ptr<RamRelationReference> rel = nullptr)
: RamValue(RN_ElementAccess), identifier(ident), element(elem), relation(std::move(rel)) {}

	/** Print */
	void print(std::ostream& os) const override {
		if (nullptr == relation) {
			os << "env(t" << identifier << ", i" << element << ")";
		} else {
			os << "t" << identifier << "." << getName();
		}
	}

	/** Get identifier */
	size_t getIdentifier() const {
		return identifier;
	}

	/** Get element */
	size_t getElement() const {
		return element;
	}

	/** Get name */
	// TODO (#541): Move to a RAM analysis
	const std::string getName() const {
		return relation->getArg(element);
	}

	/** Obtain list of child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		return std::vector<const RamNode*>();  // no child nodes
	}

	/** Create clone */
	RamElementAccess* clone() const override {
		if (relation != nullptr) {
			return new RamElementAccess(
					identifier, element, std::unique_ptr<RamRelationReference>(relation->clone()));
		} else {
			return new RamElementAccess(identifier, element);
		}
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamElementAccess*>(&node));
		const auto& other = static_cast<const RamElementAccess&>(node);
		return getIdentifier() == other.getIdentifier() && getElement() == other.getElement();
	}
};

/**
 * Access greatest lower bound (glb) of lattice element from the current tuple in a tuple environment
 */
class RamLatticeGLB : public RamValue {
private:
	/*   * Identifier for the tuple
    size_t identifier;

	 * Element number
    size_t element;*/

	struct Ref_st {
		int identifier;
		int element;
		std::unique_ptr<RamRelationReference> relation{nullptr};

		Ref_st() = default;

		Ref_st(int ident, int elem, std::unique_ptr<RamRelationReference> rel = nullptr)
		: identifier(ident), element(elem), relation(std::move(rel)) {}

		Ref_st(const Ref_st& ref) : identifier(ref.identifier), element(ref.element) {
			if (ref.relation != nullptr) {
				relation = std::unique_ptr<RamRelationReference>(ref.relation->clone());
			}
		}

		Ref_st& operator=(Ref_st other) {
			identifier = other.identifier;
			element = other.element;
			relation = std::move(other.relation);
			return *this;
		}

		bool operator==(const Ref_st& ref) const {
			return identifier == ref.identifier && element == ref.element;
		}
	};
	/** pair of identifier and element number for referenced lattice elements **/
	std::vector<Ref_st> references;

	/** Lattice Definition **/
	//std::unique_ptr<RamLatticeAssociation> lattice;
	/** Relation */
	//std::unique_ptr<RamRelationReference> relation;

public:

	RamLatticeGLB(): RamValue(RN_LatticeGLB) {}
	RamLatticeGLB(const std::vector<Ref_st> refs): RamValue(RN_LatticeGLB), references(refs) {}

	/** Print */
	void print(std::ostream& os) const override {
		os << "glb( ";
		auto it = references.begin();
		os << "t" << it->identifier << "." << it->relation->getArg(it->element);
		it ++;
		while (it != references.end()) {
			os << ", t" << it->identifier << "." << it->relation->getArg(it->element);
			it ++;
		}
		os << " )";

	}

	void addRef(int identifier, int element, std::unique_ptr<RamRelationReference> relation) {
		references.push_back({identifier, element, std::move(relation)});
	}

	const std::vector<Ref_st>* getRefs() const {
		return &references;
	}

//	const RamLatticeAssociation* getLatticeAssociation() const {
//		return lattice.get();
//	}

	/** Obtain list of child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		return std::vector<const RamNode*>();  // no child nodes
	}

	/** Create clone */
	RamLatticeGLB* clone() const override {
		return new RamLatticeGLB(references);
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamLatticeGLB*>(&node));
		const auto& other = static_cast<const RamLatticeGLB&>(node);
		return getRefs() == other.getRefs();
	}
};

/**
 * Number Constant
 */
class RamNumber : public RamValue {
	/** Constant value */
	RamDomain constant;

public:
	RamNumber(RamDomain c) : RamValue(RN_Number), constant(c) {}

	/** Get constant */
	RamDomain getConstant() const {
		return constant;
	}

	/** Print */
	void print(std::ostream& os) const override {
		os << "number(" << constant << ")";
	}

	/** Obtain list of child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		return std::vector<const RamNode*>();  // no child nodes
	}

	/** Create clone */
	RamNumber* clone() const override {
		auto* res = new RamNumber(constant);
		return res;
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamNumber*>(&node));
		const auto& other = static_cast<const RamNumber&>(node);
		return getConstant() == other.getConstant();
	}
};

/**
 * Counter
 *
 * Increment a counter and return its value. Note that
 * there exists a single counter only.
 */
class RamAutoIncrement : public RamValue {
public:
	RamAutoIncrement() : RamValue(RN_AutoIncrement) {}

	/** Print */
	void print(std::ostream& os) const override {
		os << "autoinc()";
	}

	/** Obtain list of child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		return std::vector<const RamNode*>();  // no child nodes
	}

	/** Create clone */
	RamAutoIncrement* clone() const override {
		auto* res = new RamAutoIncrement();
		return res;
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamAutoIncrement*>(&node));
		return true;
	}
};

/**
 * Record pack operation
 */
class RamPack : public RamValue {
private:
	/** Arguments */
	std::vector<std::unique_ptr<RamValue>> arguments;

public:
	RamPack(std::vector<std::unique_ptr<RamValue>> args) : RamValue(RN_Pack), arguments(std::move(args)) {}

	/** Get arguments */
	std::vector<RamValue*> getArguments() const {
		return toPtrVector(arguments);
	}

	/** Print */
	void print(std::ostream& os) const override {
		os << "[" << join(arguments, ",", [](std::ostream& out, const std::unique_ptr<RamValue>& arg) {
			if (arg) {
				out << *arg;
			} else {
				out << "_";
			}
		}) << "]";
	}

	/** Obtain list of child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		std::vector<const RamNode*> res;
		for (const auto& cur : arguments) {
			if (cur) {
				res.push_back(cur.get());
			}
		}
		return res;
	}

	/** Create clone */
	RamPack* clone() const override {
		RamPack* res = new RamPack({});
		for (auto& cur : arguments) {
			RamValue* arg = nullptr;
			if (cur != nullptr) {
				arg = cur->clone();
			}
			res->arguments.emplace_back(arg);
		}
		return res;
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {
		for (auto& arg : arguments) {
			if (arg != nullptr) {
				arg = map(std::move(arg));
			}
		}
	}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamPack*>(&node));
		const auto& other = static_cast<const RamPack&>(node);
		return equal_targets(arguments, other.arguments);
	}
};

/**
 * Access argument of a subroutine
 *
 * Arguments are number from zero 0 to n-1
 * where n is the number of arguments of the
 * subroutine.
 */
class RamArgument : public RamValue {
	/** Argument number */
	size_t number;

public:
	RamArgument(size_t number) : RamValue(RN_Argument), number(number) {}

	/** Get argument number */
	size_t getArgCount() const {
		return number;
	}

	/** Print */
	void print(std::ostream& os) const override {
		os << "argument(" << number << ")";
	}

	/** Obtain list of child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		return std::vector<const RamNode*>();
	}

	/** Create clone */
	RamArgument* clone() const override {
		auto* res = new RamArgument(getArgCount());
		return res;
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamArgument*>(&node));
		const auto& other = static_cast<const RamArgument&>(node);
		return getArgCount() == other.getArgCount();
	}
};

}  // end of namespace souffle
