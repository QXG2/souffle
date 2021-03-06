/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2013, 2015, Oracle and/or its affiliates. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file AstProgram.cpp
 *
 * Implement methods for class Program that represents a Datalog
 * program consisting of types, relations, and clauses.
 *
 ***********************************************************************/

#include "AstProgram.h"
#include "AstClause.h"
#include "AstComponent.h"
#include "AstFunctorDeclaration.h"
#include "AstLiteral.h"
#include "AstRelation.h"
#include "ErrorReport.h"
#include "Util.h"
#include <sstream>

namespace souffle {

/*
 * Program
 */

AstProgram::AstProgram(AstProgram&& other) noexcept {
	types.swap(other.types);
	relations.swap(other.relations);
	clauses.swap(other.clauses);
	loads.swap(other.loads);
	stores.swap(other.stores);
	components.swap(other.components);
	instantiations.swap(other.instantiations);
}

/* Add a new type to the program */
void AstProgram::addType(std::unique_ptr<AstType> type) {
	auto& cur = types[type->getName()];
	assert(!cur && "Redefinition of type!");
	cur = std::move(type);
}

const AstType* AstProgram::getType(const AstTypeIdentifier& name) const {
	auto pos = types.find(name);
	return (pos == types.end()) ? nullptr : pos->second.get();
}

std::vector<const AstType*> AstProgram::getTypes() const {
	std::vector<const AstType*> res;
	for (const auto& cur : types) {
		res.push_back(cur.second.get());
	}
	return res;
}

/* Add a relation to the program */
void AstProgram::addRelation(std::unique_ptr<AstRelation> r) {
	const auto& name = r->getName();
	assert(relations.find(name) == relations.end() && "Redefinition of relation!");
	relations[name] = std::move(r);
}

void AstProgram::appendRelation(std::unique_ptr<AstRelation> r) {
	// get relation
	std::unique_ptr<AstRelation>& rel = relations[r->getName()];
	assert(!rel && "Adding pre-existing relation!");

	// add relation
	rel = std::move(r);
}

void AstProgram::addLatticeFunction(std::unique_ptr<souffle::AstLatticeFunction> f) {
	const auto& name = f->getName();
	assert(latticeFunctions.find(name) == latticeFunctions.end() && "Redefinition of Lattice Function!");
	latticeFunctions[name] = std::move(f);
}


///** Add a Lattice Binary Function to the program */
//void AstProgram::addLatticeBinaryFunction(std::unique_ptr<souffle::AstLatticeBinaryFunction> f) {
//	const auto& name = f->getName();
//	assert(latticeBinary.find(name) == latticeBinary.end() && "Redefinition of Lattice Binary function!");
//	latticeBinary[name] = std::move(f);
//}

/** Set a Lattice Association to the program */
void AstProgram::addLatticeAssociation(std::unique_ptr<souffle::AstLatticeAssociation> f) {
	assert(latticeAssociation.get()==nullptr && "Dual definition of Lattice Association!");
	latticeAssociation = std::move(f);
}

/* Add a functor declaration to the program */
void AstProgram::addFunctorDeclaration(std::unique_ptr<AstFunctorDeclaration> f) {
	const auto& name = f->getName();
	assert(functors.find(name) == functors.end() && "Redefinition of functor!");
	functors[name] = std::move(f);
}

/* Remove a relation from the program */
void AstProgram::removeRelation(const AstRelationIdentifier& name) {
	/* Remove relation from map */
	relations.erase(relations.find(name));
}

void AstProgram::appendClause(std::unique_ptr<AstClause> clause) {
	// get relation
	std::unique_ptr<AstRelation>& r = relations[clause->getHead()->getName()];
	assert(r && "Trying to append to unknown relation!");

	// delegate call
	r->addClause(std::move(clause));
}

void AstProgram::removeClause(const AstClause* clause) {
	// get relation
	auto pos = relations.find(clause->getHead()->getName());
	if (pos == relations.end()) {
		return;
	}

	// delegate call
	pos->second->removeClause(clause);
}

AstRelation* AstProgram::getRelation(const AstRelationIdentifier& name) const {
	auto pos = relations.find(name);
	return (pos == relations.end()) ? nullptr : pos->second.get();
}

AstLatticeFunction* AstProgram::getLatticeFunction(const std::string& name) const {
	auto pos = latticeFunctions.find(name);
//	assert(pos != latticeBinary.end());
	return pos==latticeFunctions.end() ? nullptr : pos->second.get();
}

const std::map<std::string, std::unique_ptr<AstLatticeFunction>>& AstProgram::GetMapLatticeFunction() const {
	return latticeFunctions;
}

AstLatticeAssociation* AstProgram::getLatticeAssociation() const {
	return latticeAssociation.get();
}

AstFunctorDeclaration* AstProgram::getFunctorDeclaration(const std::string& name) const {
	auto pos = functors.find(name);
	return (pos == functors.end()) ? nullptr : pos->second.get();
}

/* Add a clause to the program */
void AstProgram::addClause(std::unique_ptr<AstClause> clause) {
	assert(clause && "NULL clause");
	clauses.push_back(std::move(clause));
}

void AstProgram::addLoad(std::unique_ptr<AstLoad> directive) {
	assert(directive && "NULL IO directive");
	loads.push_back(std::move(directive));
}

void AstProgram::addStore(std::unique_ptr<AstStore> directive) {
	assert(directive && "NULL IO directive");
	stores.push_back(std::move(directive));
}

/* Add a pragma to the program */
void AstProgram::addPragma(std::unique_ptr<AstPragma> pragma) {
	assert(pragma && "NULL IO directive");
	pragmaDirectives.push_back(std::move(pragma));
}

/* Put all pragma directives of the program into a list */
const std::vector<std::unique_ptr<AstPragma>>& AstProgram::getPragmaDirectives() const {
	return pragmaDirectives;
}

/* Put all relations of the program into a list */
std::vector<AstRelation*> AstProgram::getRelations() const {
	std::vector<AstRelation*> res;
	for (const auto& rel : relations) {
		res.push_back(rel.second.get());
	}
	return res;
}

/* Put all loads of the program into a list */
const std::vector<std::unique_ptr<AstLoad>>& AstProgram::getLoads() const {
	return loads;
}

/* Put all stores of the program into a list */
const std::vector<std::unique_ptr<AstStore>>& AstProgram::getStores() const {
	return stores;
}

/* Print program in textual format */
void AstProgram::print(std::ostream& os) const {
	/* Print types */
	os << "// ----- Types -----\n";
	for (const auto& cur : types) {
		os << *cur.second << "\n";
	}

	/* Print components */
	if (!components.empty()) {
		os << "\n// ----- Components -----\n";
		for (const auto& cur : components) {
			os << *cur << "\n";
		}
	}

	/* Print instantiations */
	if (!instantiations.empty()) {
		os << "\n";
		for (const auto& cur : instantiations) {
			os << *cur << "\n";
		}
	}

	os << "\n// ----- Lattice -----\n";
	if (getLatticeAssociation()!=nullptr) {
		latticeAssociation->print(os);
		os << "\n";
		for (const auto& cur : latticeFunctions) {
			const std::unique_ptr<AstLatticeFunction>& f = cur.second;
			os << "\n\n// -- " << f->getName() << " --\n";
			f->print(os);
			os << "\n";
		}
	}

	/* Print functors */
	os << "\n// ----- Functors -----\n";
	for (const auto& cur : functors) {
		const std::unique_ptr<AstFunctorDeclaration>& f = cur.second;
		os << "\n\n// -- " << f->getName() << " --\n";
		f->print(os);
		os << "\n";
	}

	/* Print relations */
	os << "\n// ----- Relations -----\n";
	for (const auto& cur : relations) {
		const std::unique_ptr<AstRelation>& rel = cur.second;
		os << "\n\n// -- " << rel->getName() << " --\n";
		os << *rel << "\n\n";
		for (const auto clause : rel->getClauses()) {
			os << *clause << "\n\n";
		}
		for (const auto ioDirective : rel->getLoads()) {
			os << *ioDirective << "\n\n";
		}
		for (const auto ioDirective : rel->getStores()) {
			os << *ioDirective << "\n\n";
		}
	}

	if (!clauses.empty()) {
		os << "\n// ----- Orphan Clauses -----\n";
		os << join(clauses, "\n\n", print_deref<std::unique_ptr<AstClause>>()) << "\n";
	}

	if (!loads.empty()) {
		os << "\n// ----- Orphan Load directives -----\n";
		os << join(loads, "\n\n", print_deref<std::unique_ptr<AstLoad>>()) << "\n";
	}
	if (!stores.empty()) {
		os << "\n// ----- Orphan Store directives -----\n";
		os << join(stores, "\n\n", print_deref<std::unique_ptr<AstStore>>()) << "\n";
	}

	if (!pragmaDirectives.empty()) {
		os << "\n// ----- Pragma -----\n";
		for (const auto& cur : pragmaDirectives) {
			os << *cur << "\n";
		}
	}
}

AstProgram* AstProgram::clone() const {
	// create copy
	auto res = new AstProgram();

	// move types
	for (const auto& cur : types) {
		res->types.insert(std::make_pair(cur.first, std::unique_ptr<AstType>(cur.second->clone())));
	}

	// move relations
	for (const auto& cur : relations) {
		res->relations.insert(std::make_pair(cur.first, std::unique_ptr<AstRelation>(cur.second->clone())));
	}

	// move components
	for (const auto& cur : components) {
		res->components.emplace_back(cur->clone());
	}

	// move component instantiations
	for (const auto& cur : instantiations) {
		res->instantiations.emplace_back(cur->clone());
	}

	// move ioDirectives
	for (const auto& cur : loads) {
		res->loads.emplace_back(cur->clone());
	}
	for (const auto& cur : stores) {
		res->stores.emplace_back(cur->clone());
	}

	ErrorReport errors;

	res->finishParsing();

	// done
	return res;
}

/** Mutates this node */
void AstProgram::apply(const AstNodeMapper& map) {
	for (auto& cur : types) {
		cur.second = map(std::move(cur.second));
	}
	for (auto& cur : relations) {
		cur.second = map(std::move(cur.second));
	}
	for (auto& cur : components) {
		cur = map(std::move(cur));
	}
	for (auto& cur : instantiations) {
		cur = map(std::move(cur));
	}
	for (auto& cur : pragmaDirectives) {
		cur = map(std::move(cur));
	}
	for (auto& cur : loads) {
		cur = map(std::move(cur));
	}
	for (auto& cur : stores) {
		cur = map(std::move(cur));
	}
}

void AstProgram::finishParsing() {
	// unbound clauses with no relation defined
	std::vector<std::unique_ptr<AstClause>> unbound;

	// add clauses
	for (auto& cur : clauses) {
		auto pos = relations.find(cur->getHead()->getName());
		if (pos != relations.end()) {
			pos->second->addClause(std::move(cur));
		} else {
			unbound.push_back(std::move(cur));
		}
	}
	// remember the remaining orphan clauses
	clauses.clear();
	clauses.swap(unbound);

	// unbound directives with no relation defined
	std::vector<std::unique_ptr<AstLoad>> unboundLoads;
	std::vector<std::unique_ptr<AstStore>> unboundStores;

	// add IO directives
	for (auto& cur : loads) {
		auto pos = relations.find(cur->getName());
		if (pos != relations.end()) {
			pos->second->addLoad(std::move(cur));
		} else {
			unboundLoads.push_back(std::move(cur));
		}
	}
	// remember the remaining orphan directives
	loads.clear();
	loads.swap(unboundLoads);

	for (auto& cur : stores) {
		auto pos = relations.find(cur->getName());
		if (pos != relations.end()) {
			pos->second->addStore(std::move(cur));
		} else {
			unboundStores.push_back(std::move(cur));
		}
	}
	// remember the remaining orphan directives
	stores.clear();
	stores.swap(unboundStores);
}

}  // end of namespace souffle
