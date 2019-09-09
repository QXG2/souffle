// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hh"

// User implementation prologue.

#line 51 "parser.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 85 "./parser.yy" // lalr1.cc:413

    #include "ParserDriver.h"

#line 57 "parser.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 143 "parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (ParserDriver &driver_yyarg, yyscan_t yyscanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg),
      yyscanner (yyscanner_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 114: // arg
        value.move< AstArgument * > (that.value);
        break;

      case 118: // non_empty_arg_list
      case 119: // arg_list
      case 120: // atom
        value.move< AstAtom * > (that.value);
        break;

      case 122: // fact
        value.move< AstClause * > (that.value);
        break;

      case 137: // component_head
      case 138: // component_body
      case 139: // component
        value.move< AstComponent * > (that.value);
        break;

      case 140: // comp_init
        value.move< AstComponentInit * > (that.value);
        break;

      case 136: // comp_type
        value.move< AstComponentType * > (that.value);
        break;

      case 6: // "number"
        value.move< AstDomain > (that.value);
        break;

      case 93: // enumtype
        value.move< AstEnumType * > (that.value);
        break;

      case 128: // exec_order_list
      case 129: // exec_order
        value.move< AstExecutionOrder * > (that.value);
        break;

      case 130: // exec_plan_list
      case 131: // exec_plan
        value.move< AstExecutionPlan * > (that.value);
        break;

      case 98: // functor_decl
        value.move< AstFunctorDeclaration * > (that.value);
        break;

      case 108: // non_empty_key_value_pairs
      case 109: // key_value_pairs
      case 113: // iodirective_body
        value.move< AstIO * > (that.value);
        break;

      case 105: // lattice_asscoiation
        value.move< AstLatticeAssociation * > (that.value);
        break;

      case 106: // lattice_def
      case 107: // lattice_def_type
        value.move< AstLatticeBinaryFunction * > (that.value);
        break;

      case 88: // pragma
        value.move< AstPragma * > (that.value);
        break;

      case 117: // recordlist
        value.move< AstRecordInit * > (that.value);
        break;

      case 91: // recordtype
        value.move< AstRecordType * > (that.value);
        break;

      case 95: // non_empty_attributes
      case 96: // attributes
      case 103: // relation_body
        value.move< AstRelation * > (that.value);
        break;

      case 94: // rel_id
        value.move< AstRelationIdentifier * > (that.value);
        break;

      case 90: // type
        value.move< AstType * > (that.value);
        break;

      case 89: // type_id
        value.move< AstTypeIdentifier * > (that.value);
        break;

      case 92: // uniontype
        value.move< AstUnionType * > (that.value);
        break;

      case 115: // functor_list
      case 116: // functor_args
        value.move< AstUserDefinedFunctor * > (that.value);
        break;

      case 121: // literal
      case 124: // term
      case 125: // conjunction
      case 126: // disjunction
      case 127: // body
        value.move< RuleBody * > (that.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 99: // functor_type
      case 100: // functor_typeargs
      case 141: // comp_override
        value.move< std::string > (that.value);
        break;

      case 123: // head
        value.move< std::vector<AstAtom*> > (that.value);
        break;

      case 132: // rule_def
      case 133: // rule
        value.move< std::vector<AstClause*> > (that.value);
        break;

      case 112: // iodirective_list
        value.move< std::vector<AstIO *> > (that.value);
        break;

      case 110: // load_head
        value.move< std::vector<AstLoad *> > (that.value);
        break;

      case 101: // relation_decl
      case 102: // relation_list
      case 104: // lattice_decl
        value.move< std::vector<AstRelation *> > (that.value);
        break;

      case 111: // store_head
        value.move< std::vector<AstStore *> > (that.value);
        break;

      case 134: // type_param_list
      case 135: // type_params
        value.move< std::vector<AstTypeIdentifier> > (that.value);
        break;

      case 97: // qualifiers
        value.move< uint32_t > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 114: // arg
        value.copy< AstArgument * > (that.value);
        break;

      case 118: // non_empty_arg_list
      case 119: // arg_list
      case 120: // atom
        value.copy< AstAtom * > (that.value);
        break;

      case 122: // fact
        value.copy< AstClause * > (that.value);
        break;

      case 137: // component_head
      case 138: // component_body
      case 139: // component
        value.copy< AstComponent * > (that.value);
        break;

      case 140: // comp_init
        value.copy< AstComponentInit * > (that.value);
        break;

      case 136: // comp_type
        value.copy< AstComponentType * > (that.value);
        break;

      case 6: // "number"
        value.copy< AstDomain > (that.value);
        break;

      case 93: // enumtype
        value.copy< AstEnumType * > (that.value);
        break;

      case 128: // exec_order_list
      case 129: // exec_order
        value.copy< AstExecutionOrder * > (that.value);
        break;

      case 130: // exec_plan_list
      case 131: // exec_plan
        value.copy< AstExecutionPlan * > (that.value);
        break;

      case 98: // functor_decl
        value.copy< AstFunctorDeclaration * > (that.value);
        break;

      case 108: // non_empty_key_value_pairs
      case 109: // key_value_pairs
      case 113: // iodirective_body
        value.copy< AstIO * > (that.value);
        break;

      case 105: // lattice_asscoiation
        value.copy< AstLatticeAssociation * > (that.value);
        break;

      case 106: // lattice_def
      case 107: // lattice_def_type
        value.copy< AstLatticeBinaryFunction * > (that.value);
        break;

      case 88: // pragma
        value.copy< AstPragma * > (that.value);
        break;

      case 117: // recordlist
        value.copy< AstRecordInit * > (that.value);
        break;

      case 91: // recordtype
        value.copy< AstRecordType * > (that.value);
        break;

      case 95: // non_empty_attributes
      case 96: // attributes
      case 103: // relation_body
        value.copy< AstRelation * > (that.value);
        break;

      case 94: // rel_id
        value.copy< AstRelationIdentifier * > (that.value);
        break;

      case 90: // type
        value.copy< AstType * > (that.value);
        break;

      case 89: // type_id
        value.copy< AstTypeIdentifier * > (that.value);
        break;

      case 92: // uniontype
        value.copy< AstUnionType * > (that.value);
        break;

      case 115: // functor_list
      case 116: // functor_args
        value.copy< AstUserDefinedFunctor * > (that.value);
        break;

      case 121: // literal
      case 124: // term
      case 125: // conjunction
      case 126: // disjunction
      case 127: // body
        value.copy< RuleBody * > (that.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 99: // functor_type
      case 100: // functor_typeargs
      case 141: // comp_override
        value.copy< std::string > (that.value);
        break;

      case 123: // head
        value.copy< std::vector<AstAtom*> > (that.value);
        break;

      case 132: // rule_def
      case 133: // rule
        value.copy< std::vector<AstClause*> > (that.value);
        break;

      case 112: // iodirective_list
        value.copy< std::vector<AstIO *> > (that.value);
        break;

      case 110: // load_head
        value.copy< std::vector<AstLoad *> > (that.value);
        break;

      case 101: // relation_decl
      case 102: // relation_list
      case 104: // lattice_decl
        value.copy< std::vector<AstRelation *> > (that.value);
        break;

      case 111: // store_head
        value.copy< std::vector<AstStore *> > (that.value);
        break;

      case 134: // type_param_list
      case 135: // type_params
        value.copy< std::vector<AstTypeIdentifier> > (that.value);
        break;

      case 97: // qualifiers
        value.copy< uint32_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 3: // "reserved keyword"

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 627 "parser.cc" // lalr1.cc:636
        break;

      case 4: // "symbol"

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 634 "parser.cc" // lalr1.cc:636
        break;

      case 5: // "identifier"

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 641 "parser.cc" // lalr1.cc:636
        break;

      case 6: // "number"

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstDomain > (); }
#line 648 "parser.cc" // lalr1.cc:636
        break;

      case 7: // "relational operator"

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 655 "parser.cc" // lalr1.cc:636
        break;

      case 88: // pragma

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstPragma * > (); }
#line 662 "parser.cc" // lalr1.cc:636
        break;

      case 89: // type_id

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstTypeIdentifier * > (); }
#line 669 "parser.cc" // lalr1.cc:636
        break;

      case 90: // type

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstType * > (); }
#line 676 "parser.cc" // lalr1.cc:636
        break;

      case 91: // recordtype

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRecordType * > (); }
#line 683 "parser.cc" // lalr1.cc:636
        break;

      case 92: // uniontype

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUnionType * > (); }
#line 690 "parser.cc" // lalr1.cc:636
        break;

      case 93: // enumtype

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstEnumType * > (); }
#line 697 "parser.cc" // lalr1.cc:636
        break;

      case 94: // rel_id

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelationIdentifier * > (); }
#line 704 "parser.cc" // lalr1.cc:636
        break;

      case 95: // non_empty_attributes

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 711 "parser.cc" // lalr1.cc:636
        break;

      case 96: // attributes

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 718 "parser.cc" // lalr1.cc:636
        break;

      case 97: // qualifiers

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< uint32_t > (); }
#line 725 "parser.cc" // lalr1.cc:636
        break;

      case 98: // functor_decl

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstFunctorDeclaration * > (); }
#line 732 "parser.cc" // lalr1.cc:636
        break;

      case 99: // functor_type

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 739 "parser.cc" // lalr1.cc:636
        break;

      case 100: // functor_typeargs

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 746 "parser.cc" // lalr1.cc:636
        break;

      case 101: // relation_decl

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 753 "parser.cc" // lalr1.cc:636
        break;

      case 102: // relation_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 760 "parser.cc" // lalr1.cc:636
        break;

      case 103: // relation_body

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 767 "parser.cc" // lalr1.cc:636
        break;

      case 104: // lattice_decl

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 774 "parser.cc" // lalr1.cc:636
        break;

      case 105: // lattice_asscoiation

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeAssociation * > (); }
#line 781 "parser.cc" // lalr1.cc:636
        break;

      case 106: // lattice_def

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeBinaryFunction * > (); }
#line 788 "parser.cc" // lalr1.cc:636
        break;

      case 107: // lattice_def_type

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeBinaryFunction * > (); }
#line 795 "parser.cc" // lalr1.cc:636
        break;

      case 108: // non_empty_key_value_pairs

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 802 "parser.cc" // lalr1.cc:636
        break;

      case 109: // key_value_pairs

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 809 "parser.cc" // lalr1.cc:636
        break;

      case 110: // load_head

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstLoad *> > (); }
#line 816 "parser.cc" // lalr1.cc:636
        break;

      case 111: // store_head

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstStore *> > (); }
#line 823 "parser.cc" // lalr1.cc:636
        break;

      case 112: // iodirective_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstIO *> > (); }
#line 830 "parser.cc" // lalr1.cc:636
        break;

      case 113: // iodirective_body

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 837 "parser.cc" // lalr1.cc:636
        break;

      case 114: // arg

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstArgument * > (); }
#line 844 "parser.cc" // lalr1.cc:636
        break;

      case 115: // functor_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUserDefinedFunctor * > (); }
#line 851 "parser.cc" // lalr1.cc:636
        break;

      case 116: // functor_args

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUserDefinedFunctor * > (); }
#line 858 "parser.cc" // lalr1.cc:636
        break;

      case 117: // recordlist

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRecordInit * > (); }
#line 865 "parser.cc" // lalr1.cc:636
        break;

      case 118: // non_empty_arg_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 872 "parser.cc" // lalr1.cc:636
        break;

      case 119: // arg_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 879 "parser.cc" // lalr1.cc:636
        break;

      case 120: // atom

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 886 "parser.cc" // lalr1.cc:636
        break;

      case 121: // literal

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 893 "parser.cc" // lalr1.cc:636
        break;

      case 122: // fact

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstClause * > (); }
#line 900 "parser.cc" // lalr1.cc:636
        break;

      case 123: // head

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstAtom*> > (); }
#line 907 "parser.cc" // lalr1.cc:636
        break;

      case 124: // term

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 914 "parser.cc" // lalr1.cc:636
        break;

      case 125: // conjunction

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 921 "parser.cc" // lalr1.cc:636
        break;

      case 126: // disjunction

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 928 "parser.cc" // lalr1.cc:636
        break;

      case 127: // body

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 935 "parser.cc" // lalr1.cc:636
        break;

      case 128: // exec_order_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionOrder * > (); }
#line 942 "parser.cc" // lalr1.cc:636
        break;

      case 129: // exec_order

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionOrder * > (); }
#line 949 "parser.cc" // lalr1.cc:636
        break;

      case 130: // exec_plan_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionPlan * > (); }
#line 956 "parser.cc" // lalr1.cc:636
        break;

      case 131: // exec_plan

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionPlan * > (); }
#line 963 "parser.cc" // lalr1.cc:636
        break;

      case 132: // rule_def

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstClause*> > (); }
#line 970 "parser.cc" // lalr1.cc:636
        break;

      case 133: // rule

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstClause*> > (); }
#line 977 "parser.cc" // lalr1.cc:636
        break;

      case 134: // type_param_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstTypeIdentifier> > (); }
#line 984 "parser.cc" // lalr1.cc:636
        break;

      case 135: // type_params

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstTypeIdentifier> > (); }
#line 991 "parser.cc" // lalr1.cc:636
        break;

      case 136: // comp_type

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponentType * > (); }
#line 998 "parser.cc" // lalr1.cc:636
        break;

      case 137: // component_head

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1005 "parser.cc" // lalr1.cc:636
        break;

      case 138: // component_body

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1012 "parser.cc" // lalr1.cc:636
        break;

      case 139: // component

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1019 "parser.cc" // lalr1.cc:636
        break;

      case 140: // comp_init

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponentInit * > (); }
#line 1026 "parser.cc" // lalr1.cc:636
        break;

      case 141: // comp_override

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 1033 "parser.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver, yyscanner));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 114: // arg
        yylhs.value.build< AstArgument * > ();
        break;

      case 118: // non_empty_arg_list
      case 119: // arg_list
      case 120: // atom
        yylhs.value.build< AstAtom * > ();
        break;

      case 122: // fact
        yylhs.value.build< AstClause * > ();
        break;

      case 137: // component_head
      case 138: // component_body
      case 139: // component
        yylhs.value.build< AstComponent * > ();
        break;

      case 140: // comp_init
        yylhs.value.build< AstComponentInit * > ();
        break;

      case 136: // comp_type
        yylhs.value.build< AstComponentType * > ();
        break;

      case 6: // "number"
        yylhs.value.build< AstDomain > ();
        break;

      case 93: // enumtype
        yylhs.value.build< AstEnumType * > ();
        break;

      case 128: // exec_order_list
      case 129: // exec_order
        yylhs.value.build< AstExecutionOrder * > ();
        break;

      case 130: // exec_plan_list
      case 131: // exec_plan
        yylhs.value.build< AstExecutionPlan * > ();
        break;

      case 98: // functor_decl
        yylhs.value.build< AstFunctorDeclaration * > ();
        break;

      case 108: // non_empty_key_value_pairs
      case 109: // key_value_pairs
      case 113: // iodirective_body
        yylhs.value.build< AstIO * > ();
        break;

      case 105: // lattice_asscoiation
        yylhs.value.build< AstLatticeAssociation * > ();
        break;

      case 106: // lattice_def
      case 107: // lattice_def_type
        yylhs.value.build< AstLatticeBinaryFunction * > ();
        break;

      case 88: // pragma
        yylhs.value.build< AstPragma * > ();
        break;

      case 117: // recordlist
        yylhs.value.build< AstRecordInit * > ();
        break;

      case 91: // recordtype
        yylhs.value.build< AstRecordType * > ();
        break;

      case 95: // non_empty_attributes
      case 96: // attributes
      case 103: // relation_body
        yylhs.value.build< AstRelation * > ();
        break;

      case 94: // rel_id
        yylhs.value.build< AstRelationIdentifier * > ();
        break;

      case 90: // type
        yylhs.value.build< AstType * > ();
        break;

      case 89: // type_id
        yylhs.value.build< AstTypeIdentifier * > ();
        break;

      case 92: // uniontype
        yylhs.value.build< AstUnionType * > ();
        break;

      case 115: // functor_list
      case 116: // functor_args
        yylhs.value.build< AstUserDefinedFunctor * > ();
        break;

      case 121: // literal
      case 124: // term
      case 125: // conjunction
      case 126: // disjunction
      case 127: // body
        yylhs.value.build< RuleBody * > ();
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 99: // functor_type
      case 100: // functor_typeargs
      case 141: // comp_override
        yylhs.value.build< std::string > ();
        break;

      case 123: // head
        yylhs.value.build< std::vector<AstAtom*> > ();
        break;

      case 132: // rule_def
      case 133: // rule
        yylhs.value.build< std::vector<AstClause*> > ();
        break;

      case 112: // iodirective_list
        yylhs.value.build< std::vector<AstIO *> > ();
        break;

      case 110: // load_head
        yylhs.value.build< std::vector<AstLoad *> > ();
        break;

      case 101: // relation_decl
      case 102: // relation_list
      case 104: // lattice_decl
        yylhs.value.build< std::vector<AstRelation *> > ();
        break;

      case 111: // store_head
        yylhs.value.build< std::vector<AstStore *> > ();
        break;

      case 134: // type_param_list
      case 135: // type_params
        yylhs.value.build< std::vector<AstTypeIdentifier> > ();
        break;

      case 97: // qualifiers
        yylhs.value.build< uint32_t > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 3:
#line 235 "./parser.yy" // lalr1.cc:859
    {
        driver.addType(std::unique_ptr<AstType>(yystack_[0].value.as< AstType * > ()));
    }
#line 1413 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 238 "./parser.yy" // lalr1.cc:859
    {
        driver.addFunctorDeclaration(std::unique_ptr<AstFunctorDeclaration>(yystack_[0].value.as< AstFunctorDeclaration * > ()));
    }
#line 1421 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 241 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) driver.addRelation(std::unique_ptr<AstRelation>(cur));
    }
#line 1429 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 244 "./parser.yy" // lalr1.cc:859
    {
    	std::cout << ".lat Lattice declaration here!\n";
    	for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) driver.addRelation(std::unique_ptr<AstRelation>(cur));
  	}
#line 1438 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 248 "./parser.yy" // lalr1.cc:859
    {
    	std::cout << ".let Lattice Asscoiation here!\n";
    	driver.addLatticeAssociation(std::unique_ptr<AstLatticeAssociation>(yystack_[0].value.as< AstLatticeAssociation * > ()));
  	}
#line 1447 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 252 "./parser.yy" // lalr1.cc:859
    {
  		std::cout << ".def Lattice binary function definition here!\n";
  		driver.addLatticeBinaryFunction(std::unique_ptr<AstLatticeBinaryFunction>(yystack_[0].value.as< AstLatticeBinaryFunction * > ()));
  	}
#line 1456 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 256 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstLoad *> > ()) driver.addLoad(std::unique_ptr<AstLoad>(cur));
    }
#line 1464 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 259 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstStore *> > ()) driver.addStore(std::unique_ptr<AstStore>(cur));
    }
#line 1472 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 262 "./parser.yy" // lalr1.cc:859
    {
        driver.addClause(std::unique_ptr<AstClause>(yystack_[0].value.as< AstClause * > ()));
    }
#line 1480 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 265 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstClause*> > ()) driver.addClause(std::unique_ptr<AstClause>(cur));
    }
#line 1488 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 268 "./parser.yy" // lalr1.cc:859
    {
        driver.addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as< AstComponent * > ()));
    }
#line 1496 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 271 "./parser.yy" // lalr1.cc:859
    {
        driver.addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as< AstComponentInit * > ()));
    }
#line 1504 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 274 "./parser.yy" // lalr1.cc:859
    {
        driver.addPragma(std::unique_ptr<AstPragma>(yystack_[0].value.as< AstPragma * > ()));
    }
#line 1512 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 277 "./parser.yy" // lalr1.cc:859
    {
    }
#line 1519 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 282 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstPragma * > () = new AstPragma(yystack_[1].value.as< std::string > (),yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 1528 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 287 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstPragma * > () = new AstPragma(yystack_[0].value.as< std::string > (), "");
        yylhs.value.as< AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 1537 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 296 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstTypeIdentifier * > () = new AstTypeIdentifier(yystack_[0].value.as< std::string > ());
    }
#line 1545 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 299 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstTypeIdentifier * > () = yystack_[2].value.as< AstTypeIdentifier * > ();
        yylhs.value.as< AstTypeIdentifier * > ()->append(yystack_[0].value.as< std::string > ());
    }
#line 1554 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 306 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > (), true);
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1563 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 310 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > (), false);
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1572 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 314 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1581 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 318 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = yystack_[0].value.as< AstUnionType * > ();
        yylhs.value.as< AstType * > ()->setName(yystack_[2].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1591 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 323 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = yystack_[1].value.as< AstRecordType * > ();
        yylhs.value.as< AstType * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1601 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 328 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstRecordType();
        yylhs.value.as< AstType * > ()->setName(yystack_[3].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1611 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 333 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstType * > () = yystack_[1].value.as< AstEnumType * > ();
  		yylhs.value.as< AstType * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
        std::cout<<"Enum type declaration here!\n";
  	}
#line 1622 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 341 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordType * > () = new AstRecordType();
        yylhs.value.as< AstRecordType * > ()->add(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1631 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 345 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordType * > () = yystack_[4].value.as< AstRecordType * > ();
        yystack_[4].value.as< AstRecordType * > ()->add(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1640 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 351 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUnionType * > () = new AstUnionType();
        yylhs.value.as< AstUnionType * > ()->add(*yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1649 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 355 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUnionType * > () = yystack_[2].value.as< AstUnionType * > ();
        yystack_[2].value.as< AstUnionType * > ()->add(*yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1658 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 361 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstEnumType * > () = new AstEnumType();
  		yylhs.value.as< AstEnumType * > ()->add(yystack_[0].value.as< std::string > ());
  		// regard lattice enum as symbol
  		driver.getSymbolTable().lookup(yystack_[0].value.as< std::string > ());
  	}
#line 1669 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 367 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstEnumType * > () = yystack_[3].value.as< AstEnumType * > ();
  		yystack_[3].value.as< AstEnumType * > ()->add(yystack_[0].value.as< std::string > ());
  		// regard lattice enum as symbol
  		driver.getSymbolTable().lookup(yystack_[0].value.as< std::string > ());
  	}
#line 1680 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 378 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelationIdentifier * > () = new AstRelationIdentifier(yystack_[0].value.as< std::string > ());
    }
#line 1688 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 381 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelationIdentifier * > () = yystack_[2].value.as< AstRelationIdentifier * > ();
        yylhs.value.as< AstRelationIdentifier * > ()->append(yystack_[0].value.as< std::string > ());
    }
#line 1697 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 389 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = new AstRelation();
        AstAttribute *a = new AstAttribute(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ());
        a->setSrcLoc(yystack_[0].location);
        yylhs.value.as< AstRelation * > ()->addAttribute(std::unique_ptr<AstAttribute>(a));
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1709 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 396 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[4].value.as< AstRelation * > ();
        AstAttribute *a = new AstAttribute(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ());
        a->setSrcLoc(yystack_[0].location);
        yylhs.value.as< AstRelation * > ()->addAttribute(std::unique_ptr<AstAttribute>(a));
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1721 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 405 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[0].value.as< AstRelation * > ();
    }
#line 1729 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 408 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = new AstRelation();
    }
#line 1737 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 413 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & OUTPUT_RELATION) driver.error(yystack_[0].location, "output qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | OUTPUT_RELATION;
    }
#line 1746 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 417 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & INPUT_RELATION) driver.error(yystack_[0].location, "input qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | INPUT_RELATION;
    }
#line 1755 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 421 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & PRINTSIZE_RELATION) driver.error(yystack_[0].location, "printsize qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | PRINTSIZE_RELATION;
    }
#line 1764 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 425 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & OVERRIDABLE_RELATION) driver.error(yystack_[0].location, "overridable qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | OVERRIDABLE_RELATION;
    }
#line 1773 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 429 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & INLINE_RELATION) driver.error(yystack_[0].location, "inline qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | INLINE_RELATION;
    }
#line 1782 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 433 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | BRIE_RELATION;
    }
#line 1791 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 437 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | BTREE_RELATION;
    }
#line 1800 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 441 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | EQREL_RELATION;
    }
#line 1809 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 445 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< uint32_t > () = 0;
    }
#line 1817 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 450 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > ()+yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 1826 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 454 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[4].value.as< std::string > (), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 1835 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 461 "./parser.yy" // lalr1.cc:859
    {
      if (yystack_[0].value.as< std::string > () == "number") {
          yylhs.value.as< std::string > () = "N";
      } else if (yystack_[0].value.as< std::string > () == "symbol") {
          yylhs.value.as< std::string > () = "S";
      } else driver.error(yystack_[0].location, "number or symbol identifier expected");
    }
#line 1847 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 471 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + yystack_[0].value.as< std::string > (); }
#line 1853 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 472 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();  }
#line 1859 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 476 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
    }
#line 1867 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 481 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().push_back(yystack_[0].value.as< AstRelation * > ());
    }
#line 1875 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 484 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
      auto tmp = yylhs.value.as< std::vector<AstRelation *> > ().back()->clone();
      tmp->setName(yystack_[2].value.as< std::string > ());
      tmp->setSrcLoc(yylhs.location);
      yylhs.value.as< std::vector<AstRelation *> > ().push_back(tmp);
    }
#line 1887 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 493 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[2].value.as< AstRelation * > ();
        yylhs.value.as< AstRelation * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstRelation * > ()->setQualifier(yystack_[0].value.as< uint32_t > ());
        yylhs.value.as< AstRelation * > ()->setSrcLoc(yylhs.location);
    }
#line 1898 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 501 "./parser.yy" // lalr1.cc:859
    {
    	yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
    	for (auto* cur : yylhs.value.as< std::vector<AstRelation *> > ()) {
          cur->setLattice();
      	}
  	}
#line 1909 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 509 "./parser.yy" // lalr1.cc:859
    {
    	yylhs.value.as< AstLatticeAssociation * > () = new AstLatticeAssociation(yystack_[14].value.as< std::string > ());
    	yylhs.value.as< AstLatticeAssociation * > ()->setALL(yystack_[9].value.as< std::string > (), yystack_[7].value.as< std::string > (), yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > (), yystack_[1].value.as< std::string > ());
  	}
#line 1918 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 515 "./parser.yy" // lalr1.cc:859
    {
  // TODO
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[1].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setSrcLoc(yylhs.location);
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setName(yystack_[10].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addArg(yystack_[8].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addArg(yystack_[6].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setOutput(yystack_[3].value.as< std::string > ());
  	}
#line 1932 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 526 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = new AstLatticeBinaryFunction();	
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > (), yystack_[0].value.as< std::string > ());
  	}
#line 1941 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 530 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[9].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > (), yystack_[0].value.as< std::string > ());
  	}
#line 1950 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 534 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[5].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap("", "", yystack_[0].value.as< std::string > ());
  	}
#line 1959 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 541 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1968 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 545 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1977 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 549 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1986 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 553 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1995 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 557 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "true");
    }
#line 2004 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 561 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "true");
    }
#line 2013 "parser.cc" // lalr1.cc:859
    break;

  case 70:
#line 565 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "false");
    }
#line 2022 "parser.cc" // lalr1.cc:859
    break;

  case 71:
#line 569 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "false");
    }
#line 2031 "parser.cc" // lalr1.cc:859
    break;

  case 72:
#line 575 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[0].value.as< AstIO * > ();
    }
#line 2039 "parser.cc" // lalr1.cc:859
    break;

  case 73:
#line 578 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->setSrcLoc(yylhs.location);
    }
#line 2048 "parser.cc" // lalr1.cc:859
    break;

  case 74:
#line 584 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstLoad *> > ().push_back(new AstLoad(*cur));
          delete cur;
      }
    }
#line 2059 "parser.cc" // lalr1.cc:859
    break;

  case 75:
#line 591 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstStore *> > ().push_back(new AstStore(*cur));
          delete cur;
      }
    }
#line 2070 "parser.cc" // lalr1.cc:859
    break;

  case 76:
#line 597 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstStore *> > ().push_back(new AstPrintSize(*cur));
          delete cur;
      }
    }
#line 2081 "parser.cc" // lalr1.cc:859
    break;

  case 77:
#line 605 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstIO *> > ().push_back(yystack_[0].value.as< AstIO * > ());
    }
#line 2089 "parser.cc" // lalr1.cc:859
    break;

  case 78:
#line 608 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstIO *> > ().swap(yystack_[0].value.as< std::vector<AstIO *> > ());
      auto tmp = yylhs.value.as< std::vector<AstIO *> > ().back()->clone();
      tmp->setName(yystack_[2].value.as< std::string > ());
      tmp->setSrcLoc(yystack_[2].location);
      yylhs.value.as< std::vector<AstIO *> > ().push_back(tmp);
    }
#line 2101 "parser.cc" // lalr1.cc:859
    break;

  case 79:
#line 617 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[1].value.as< AstIO * > ();
        yystack_[1].value.as< AstIO * > ()->addName(*yystack_[3].value.as< AstRelationIdentifier * > ());
        yystack_[1].value.as< AstIO * > ()->setSrcLoc(yystack_[3].location);
        delete yystack_[3].value.as< AstRelationIdentifier * > ();
    }
#line 2112 "parser.cc" // lalr1.cc:859
    break;

  case 80:
#line 623 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->setName(*yystack_[0].value.as< AstRelationIdentifier * > ());
        yylhs.value.as< AstIO * > ()->setSrcLoc(yystack_[0].location);
        delete yystack_[0].value.as< AstRelationIdentifier * > ();
    }
#line 2123 "parser.cc" // lalr1.cc:859
    break;

  case 81:
#line 632 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstStringConstant(driver.getSymbolTable(), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2132 "parser.cc" // lalr1.cc:859
    break;

  case 82:
#line 636 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstUnnamedVariable();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2141 "parser.cc" // lalr1.cc:859
    break;

  case 83:
#line 640 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstCounter();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2150 "parser.cc" // lalr1.cc:859
    break;

  case 84:
#line 644 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[0].value.as< AstUserDefinedFunctor * > ();
        yystack_[0].value.as< AstUserDefinedFunctor * > ()->setName(yystack_[1].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2160 "parser.cc" // lalr1.cc:859
    break;

  case 85:
#line 649 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstVariable(yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2169 "parser.cc" // lalr1.cc:859
    break;

  case 86:
#line 653 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstNumberConstant(yystack_[0].value.as< AstDomain > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2178 "parser.cc" // lalr1.cc:859
    break;

  case 87:
#line 657 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[1].value.as< AstArgument * > ();
    }
#line 2186 "parser.cc" // lalr1.cc:859
    break;

  case 88:
#line 660 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2195 "parser.cc" // lalr1.cc:859
    break;

  case 89:
#line 664 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BXOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2204 "parser.cc" // lalr1.cc:859
    break;

  case 90:
#line 668 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BAND, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2213 "parser.cc" // lalr1.cc:859
    break;

  case 91:
#line 672 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2222 "parser.cc" // lalr1.cc:859
    break;

  case 92:
#line 676 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LAND, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2231 "parser.cc" // lalr1.cc:859
    break;

  case 93:
#line 680 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ADD, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2240 "parser.cc" // lalr1.cc:859
    break;

  case 94:
#line 684 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUB, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2249 "parser.cc" // lalr1.cc:859
    break;

  case 95:
#line 688 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MUL, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2258 "parser.cc" // lalr1.cc:859
    break;

  case 96:
#line 692 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::DIV, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2267 "parser.cc" // lalr1.cc:859
    break;

  case 97:
#line 696 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MOD, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2276 "parser.cc" // lalr1.cc:859
    break;

  case 98:
#line 700 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::EXP, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2285 "parser.cc" // lalr1.cc:859
    break;

  case 99:
#line 704 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MAX, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2294 "parser.cc" // lalr1.cc:859
    break;

  case 100:
#line 708 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MIN, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2303 "parser.cc" // lalr1.cc:859
    break;

  case 101:
#line 712 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::CAT, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2312 "parser.cc" // lalr1.cc:859
    break;

  case 102:
#line 716 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ORD, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2321 "parser.cc" // lalr1.cc:859
    break;

  case 103:
#line 720 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::STRLEN, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2330 "parser.cc" // lalr1.cc:859
    break;

  case 104:
#line 724 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TONUMBER, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2339 "parser.cc" // lalr1.cc:859
    break;

  case 105:
#line 728 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TOSTRING, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2348 "parser.cc" // lalr1.cc:859
    break;

  case 106:
#line 732 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUBSTR,
                std::unique_ptr<AstArgument>(yystack_[5].value.as< AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2360 "parser.cc" // lalr1.cc:859
    break;

  case 107:
#line 739 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstTypeCast(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2369 "parser.cc" // lalr1.cc:859
    break;

  case 108:
#line 743 "./parser.yy" // lalr1.cc:859
    {
        std::unique_ptr<AstArgument> arg;
        if (const AstNumberConstant* original = dynamic_cast<const AstNumberConstant*>(yystack_[0].value.as< AstArgument * > ())) {
            yylhs.value.as< AstArgument * > () = new AstNumberConstant(-1*original->getIndex());
            yylhs.value.as< AstArgument * > ()->setSrcLoc(yystack_[0].value.as< AstArgument * > ()->getSrcLoc());
            delete yystack_[0].value.as< AstArgument * > ();
        } else {
            yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::NEG, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
            yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
        }
    }
#line 2385 "parser.cc" // lalr1.cc:859
    break;

  case 109:
#line 754 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BNOT, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2394 "parser.cc" // lalr1.cc:859
    break;

  case 110:
#line 758 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LNOT, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2403 "parser.cc" // lalr1.cc:859
    break;

  case 111:
#line 762 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstRecordInit();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2412 "parser.cc" // lalr1.cc:859
    break;

  case 112:
#line 766 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[1].value.as< AstRecordInit * > ();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2421 "parser.cc" // lalr1.cc:859
    break;

  case 113:
#line 770 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstNullConstant();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2430 "parser.cc" // lalr1.cc:859
    break;

  case 114:
#line 774 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::count);
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2441 "parser.cc" // lalr1.cc:859
    break;

  case 115:
#line 780 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::count);
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
            res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2461 "parser.cc" // lalr1.cc:859
    break;

  case 116:
#line 795 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::sum);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2473 "parser.cc" // lalr1.cc:859
    break;

  case 117:
#line 802 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::sum);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as< AstArgument * > ()));
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
	    res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2494 "parser.cc" // lalr1.cc:859
    break;

  case 118:
#line 818 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::min);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2506 "parser.cc" // lalr1.cc:859
    break;

  case 119:
#line 825 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::min);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as< AstArgument * > ()));
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
            res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2527 "parser.cc" // lalr1.cc:859
    break;

  case 120:
#line 841 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::max);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2539 "parser.cc" // lalr1.cc:859
    break;

  case 121:
#line 848 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::max);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as< AstArgument * > ()));
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
            res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2560 "parser.cc" // lalr1.cc:859
    break;

  case 122:
#line 864 "./parser.yy" // lalr1.cc:859
    {
        std::cerr << "ERROR: '" << yystack_[3].value.as< std::string > () << "' is a keyword reserved for future implementation!" << std::endl;
        exit(1);
    }
#line 2569 "parser.cc" // lalr1.cc:859
    break;

  case 123:
#line 870 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = new AstUserDefinedFunctor();
    }
#line 2577 "parser.cc" // lalr1.cc:859
    break;

  case 124:
#line 873 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = yystack_[1].value.as< AstUserDefinedFunctor * > ();
    }
#line 2585 "parser.cc" // lalr1.cc:859
    break;

  case 125:
#line 879 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = new AstUserDefinedFunctor();
        yylhs.value.as< AstUserDefinedFunctor * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2594 "parser.cc" // lalr1.cc:859
    break;

  case 126:
#line 883 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = yystack_[2].value.as< AstUserDefinedFunctor * > ();
        yylhs.value.as< AstUserDefinedFunctor * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2603 "parser.cc" // lalr1.cc:859
    break;

  case 127:
#line 890 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordInit * > () = new AstRecordInit();
        yylhs.value.as< AstRecordInit * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2612 "parser.cc" // lalr1.cc:859
    break;

  case 128:
#line 894 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordInit * > () = yystack_[2].value.as< AstRecordInit * > ();
        yylhs.value.as< AstRecordInit * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2621 "parser.cc" // lalr1.cc:859
    break;

  case 129:
#line 900 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = new AstAtom();
        yylhs.value.as< AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2630 "parser.cc" // lalr1.cc:859
    break;

  case 130:
#line 904 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[2].value.as< AstAtom * > ();
        yylhs.value.as< AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2639 "parser.cc" // lalr1.cc:859
    break;

  case 131:
#line 910 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[0].value.as< AstAtom * > ();
    }
#line 2647 "parser.cc" // lalr1.cc:859
    break;

  case 132:
#line 913 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = new AstAtom();
    }
#line 2655 "parser.cc" // lalr1.cc:859
    break;

  case 133:
#line 918 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[1].value.as< AstAtom * > ();
        yystack_[1].value.as< AstAtom * > ()->setName(*yystack_[3].value.as< AstRelationIdentifier * > ());
        delete yystack_[3].value.as< AstRelationIdentifier * > ();
        yylhs.value.as< AstAtom * > ()->setSrcLoc(yylhs.location);
    }
#line 2666 "parser.cc" // lalr1.cc:859
    break;

  case 134:
#line 927 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(yystack_[1].value.as< std::string > (), std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2676 "parser.cc" // lalr1.cc:859
    break;

  case 135:
#line 932 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::LT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2686 "parser.cc" // lalr1.cc:859
    break;

  case 136:
#line 937 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::GT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2696 "parser.cc" // lalr1.cc:859
    break;

  case 137:
#line 942 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::EQ, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2706 "parser.cc" // lalr1.cc:859
    break;

  case 138:
#line 947 "./parser.yy" // lalr1.cc:859
    {
        yystack_[0].value.as< AstAtom * > ()->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::atom(yystack_[0].value.as< AstAtom * > ()));
    }
#line 2715 "parser.cc" // lalr1.cc:859
    break;

  case 139:
#line 951 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::MATCH, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2725 "parser.cc" // lalr1.cc:859
    break;

  case 140:
#line 956 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::CONTAINS, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2735 "parser.cc" // lalr1.cc:859
    break;

  case 141:
#line 961 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBooleanConstraint(true);
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2745 "parser.cc" // lalr1.cc:859
    break;

  case 142:
#line 966 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBooleanConstraint(false);
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2755 "parser.cc" // lalr1.cc:859
    break;

  case 143:
#line 974 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstClause * > () = new AstClause();
        yylhs.value.as< AstClause * > ()->setHead(std::unique_ptr<AstAtom>(yystack_[1].value.as< AstAtom * > ()));
        yylhs.value.as< AstClause * > ()->setSrcLoc(yylhs.location);
    }
#line 2765 "parser.cc" // lalr1.cc:859
    break;

  case 144:
#line 982 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstAtom*> > ().push_back(yystack_[0].value.as< AstAtom * > ());
    }
#line 2773 "parser.cc" // lalr1.cc:859
    break;

  case 145:
#line 985 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstAtom*> > ().swap(yystack_[2].value.as< std::vector<AstAtom*> > ());
        yylhs.value.as< std::vector<AstAtom*> > ().push_back(yystack_[0].value.as< AstAtom * > ());
    }
#line 2782 "parser.cc" // lalr1.cc:859
    break;

  case 146:
#line 992 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2790 "parser.cc" // lalr1.cc:859
    break;

  case 147:
#line 995 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->negate();
    }
#line 2799 "parser.cc" // lalr1.cc:859
    break;

  case 148:
#line 999 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[1].value.as< RuleBody * > ();
    }
#line 2807 "parser.cc" // lalr1.cc:859
    break;

  case 149:
#line 1005 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2815 "parser.cc" // lalr1.cc:859
    break;

  case 150:
#line 1008 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[2].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->conjunct(std::move(*yystack_[0].value.as< RuleBody * > ()));
        delete yystack_[0].value.as< RuleBody * > ();
    }
#line 2825 "parser.cc" // lalr1.cc:859
    break;

  case 151:
#line 1016 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2833 "parser.cc" // lalr1.cc:859
    break;

  case 152:
#line 1019 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[2].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->disjunct(std::move(*yystack_[0].value.as< RuleBody * > ()));
        delete yystack_[0].value.as< RuleBody * > ();
    }
#line 2843 "parser.cc" // lalr1.cc:859
    break;

  case 153:
#line 1027 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2850 "parser.cc" // lalr1.cc:859
    break;

  case 154:
#line 1032 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = new AstExecutionOrder();
        yylhs.value.as< AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as< AstDomain > ());
    }
#line 2859 "parser.cc" // lalr1.cc:859
    break;

  case 155:
#line 1036 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = yystack_[2].value.as< AstExecutionOrder * > ();
        yylhs.value.as< AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as< AstDomain > ());
    }
#line 2868 "parser.cc" // lalr1.cc:859
    break;

  case 156:
#line 1043 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = yystack_[1].value.as< AstExecutionOrder * > ();
        yylhs.value.as< AstExecutionOrder * > ()->setSrcLoc(yylhs.location);
    }
#line 2877 "parser.cc" // lalr1.cc:859
    break;

  case 157:
#line 1050 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = new AstExecutionPlan();
        yylhs.value.as< AstExecutionPlan * > ()->setOrderFor(yystack_[2].value.as< AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[0].value.as< AstExecutionOrder * > ()));
    }
#line 2886 "parser.cc" // lalr1.cc:859
    break;

  case 158:
#line 1054 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = yystack_[4].value.as< AstExecutionPlan * > ();
        yylhs.value.as< AstExecutionPlan * > ()->setOrderFor(yystack_[2].value.as< AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[0].value.as< AstExecutionOrder * > ()));
    }
#line 2895 "parser.cc" // lalr1.cc:859
    break;

  case 159:
#line 1061 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = yystack_[0].value.as< AstExecutionPlan * > ();
        yylhs.value.as< AstExecutionPlan * > ()->setSrcLoc(yylhs.location);
    }
#line 2904 "parser.cc" // lalr1.cc:859
    break;

  case 160:
#line 1068 "./parser.yy" // lalr1.cc:859
    {
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        for(const auto& head : yystack_[3].value.as< std::vector<AstAtom*> > ()) {
            for(AstClause* body : bodies) {
                AstClause* cur = body->clone();
                cur->setHead(std::unique_ptr<AstAtom>(head->clone()));
                cur->setSrcLoc(yylhs.location);
                cur->setGenerated(yystack_[3].value.as< std::vector<AstAtom*> > ().size() != 1 || bodies.size() != 1);
                yylhs.value.as< std::vector<AstClause*> > ().push_back(cur);
            }
        }
        for(auto& head : yystack_[3].value.as< std::vector<AstAtom*> > ()) {
            delete head;
        }
        for(AstClause* body : bodies) {
            delete body;
        }
        delete yystack_[1].value.as< RuleBody * > ();
    }
#line 2928 "parser.cc" // lalr1.cc:859
    break;

  case 161:
#line 1090 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[0].value.as< std::vector<AstClause*> > ();
    }
#line 2936 "parser.cc" // lalr1.cc:859
    break;

  case 162:
#line 1093 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[1].value.as< std::vector<AstClause*> > ();
        for(const auto& cur : yylhs.value.as< std::vector<AstClause*> > ()) cur->setFixedExecutionPlan();
    }
#line 2945 "parser.cc" // lalr1.cc:859
    break;

  case 163:
#line 1097 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[1].value.as< std::vector<AstClause*> > ();
        for(const auto& cur : yylhs.value.as< std::vector<AstClause*> > ()) cur->setExecutionPlan(std::unique_ptr<AstExecutionPlan>(yystack_[0].value.as< AstExecutionPlan * > ()->clone()));
    }
#line 2954 "parser.cc" // lalr1.cc:859
    break;

  case 164:
#line 1105 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 2962 "parser.cc" // lalr1.cc:859
    break;

  case 165:
#line 1108 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > () = yystack_[2].value.as< std::vector<AstTypeIdentifier> > ();
        yylhs.value.as< std::vector<AstTypeIdentifier> > ().push_back(*yystack_[0].value.as< AstTypeIdentifier * > ());
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 2972 "parser.cc" // lalr1.cc:859
    break;

  case 166:
#line 1115 "./parser.yy" // lalr1.cc:859
    {
    }
#line 2979 "parser.cc" // lalr1.cc:859
    break;

  case 167:
#line 1117 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > () = yystack_[1].value.as< std::vector<AstTypeIdentifier> > ();
    }
#line 2987 "parser.cc" // lalr1.cc:859
    break;

  case 168:
#line 1124 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponentType * > () = new AstComponentType(yystack_[1].value.as< std::string > (),yystack_[0].value.as< std::vector<AstTypeIdentifier> > ());
    }
#line 2995 "parser.cc" // lalr1.cc:859
    break;

  case 169:
#line 1131 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = new AstComponent();
        yylhs.value.as< AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3004 "parser.cc" // lalr1.cc:859
    break;

  case 170:
#line 1135 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[2].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3013 "parser.cc" // lalr1.cc:859
    break;

  case 171:
#line 1139 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[2].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3022 "parser.cc" // lalr1.cc:859
    break;

  case 172:
#line 1145 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addType(std::unique_ptr<AstType>(yystack_[0].value.as< AstType * > ()));
    }
#line 3031 "parser.cc" // lalr1.cc:859
    break;

  case 173:
#line 1149 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) yylhs.value.as< AstComponent * > ()->addRelation(std::unique_ptr<AstRelation>(cur));
    }
#line 3040 "parser.cc" // lalr1.cc:859
    break;

  case 174:
#line 1153 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstLoad *> > ()) yylhs.value.as< AstComponent * > ()->addLoad(std::unique_ptr<AstLoad>(cur));
    }
#line 3049 "parser.cc" // lalr1.cc:859
    break;

  case 175:
#line 1157 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstStore *> > ()) yylhs.value.as< AstComponent * > ()->addStore(std::unique_ptr<AstStore>(cur));
    }
#line 3058 "parser.cc" // lalr1.cc:859
    break;

  case 176:
#line 1161 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addClause(std::unique_ptr<AstClause>(yystack_[0].value.as< AstClause * > ()));
    }
#line 3067 "parser.cc" // lalr1.cc:859
    break;

  case 177:
#line 1165 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstClause*> > ()) {
            yylhs.value.as< AstComponent * > ()->addClause(std::unique_ptr<AstClause>(cur));
        }
    }
#line 3078 "parser.cc" // lalr1.cc:859
    break;

  case 178:
#line 1171 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addOverride(yystack_[0].value.as< std::string > ());
    }
#line 3087 "parser.cc" // lalr1.cc:859
    break;

  case 179:
#line 1175 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as< AstComponent * > ()));
    }
#line 3096 "parser.cc" // lalr1.cc:859
    break;

  case 180:
#line 1179 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as< AstComponentInit * > ()));
    }
#line 3105 "parser.cc" // lalr1.cc:859
    break;

  case 181:
#line 1183 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = new AstComponent();
    }
#line 3113 "parser.cc" // lalr1.cc:859
    break;

  case 182:
#line 1188 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[3].value.as< AstComponent * > ()->getComponentType()->clone()));
        yylhs.value.as< AstComponent * > ()->copyBaseComponents(yystack_[3].value.as< AstComponent * > ());
        delete yystack_[3].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->setSrcLoc(yylhs.location);
    }
#line 3125 "parser.cc" // lalr1.cc:859
    break;

  case 183:
#line 1198 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponentInit * > () = new AstComponentInit();
        yylhs.value.as< AstComponentInit * > ()->setInstanceName(yystack_[2].value.as< std::string > ());
        yylhs.value.as< AstComponentInit * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
        yylhs.value.as< AstComponentInit * > ()->setSrcLoc(yylhs.location);
    }
#line 3136 "parser.cc" // lalr1.cc:859
    break;

  case 184:
#line 1207 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
}
#line 3144 "parser.cc" // lalr1.cc:859
    break;


#line 3148 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int parser::yypact_ninf_ = -239;

  const signed char parser::yytable_ninf_ = -35;

  const short int
  parser::yypact_[] =
  {
    -239,    62,   584,  -239,  -239,    61,    63,    63,    87,   109,
     132,   137,   137,   137,   158,   160,   164,   180,   181,   182,
    -239,  -239,   -28,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
      15,  -239,   -21,  -239,    57,    -9,  -239,  -239,   128,    52,
    -239,  -239,  -239,    17,    96,   130,   131,    -5,  -239,  -239,
    -239,  -239,   129,   133,   119,  -239,   134,  -239,  -239,   382,
     202,  -239,   154,   205,  -239,   208,  -239,   164,   164,  -239,
    -239,   211,    63,   140,   229,     0,   137,   230,    14,   165,
     233,  -239,   164,   183,  -239,  -239,  -239,   184,   187,   191,
     192,   448,   514,   177,   382,   198,   199,  -239,   250,  -239,
    -239,   382,   382,   235,   382,   382,   343,  -239,    46,  -239,
      19,   203,   204,  -239,  -239,   154,   154,   277,  -239,  -239,
    -239,   207,   201,   214,  -239,   220,   222,  -239,  -239,   186,
     223,  -239,    79,  -239,   221,   227,  -239,   231,   228,   232,
    -239,   225,  -239,    86,  -239,    11,   237,   243,   212,  -239,
     -41,  -239,   382,   382,   382,   382,   382,   382,   618,   382,
     635,    -3,   652,   382,   382,  -239,   343,   -23,   195,   678,
     240,   195,   195,   291,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,  -239,   382,   382,   382,  -239,
     534,    -2,   382,   382,   382,   382,   154,   154,  -239,   249,
     317,   319,  -239,  -239,  -239,  -239,  -239,  -239,    57,  -239,
    -239,  -239,   320,  -239,   322,   269,   325,   326,   326,   283,
      21,  -239,   344,   288,  -239,    -6,   351,   320,   354,   -32,
     320,  -239,   704,   730,   756,   782,   808,   575,    -1,   601,
       2,   154,  -239,     3,   834,   860,  -239,   382,  -239,   316,
    -239,  -239,   150,   150,   195,   195,   195,   195,    97,   127,
     210,    74,    32,   343,   886,   912,  -239,   343,   343,   343,
     343,  -239,   207,   355,  -239,   298,  -239,   237,   301,   300,
     360,   307,  -239,  -239,   326,  -239,  -239,  -239,  -239,   303,
     320,  -239,   367,  -239,   237,  -239,   294,  -239,   237,  -239,
     382,  -239,  -239,   382,   382,   154,  -239,   382,   154,  -239,
     305,   154,  -239,  -239,  -239,   343,  -239,   343,    88,   382,
     382,  -239,   101,   249,  -239,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,   320,   313,   318,  -239,    23,   237,   321,   374,
     938,   964,   990,   308,  1016,   309,  -239,   323,  -239,   382,
    1042,  1068,  -239,   383,  -239,   237,   385,   386,  -239,  -239,
    -239,  -239,   320,  -239,  -239,   382,  -239,  -239,  -239,  -239,
    -239,   343,  -239,  -239,  -239,   332,   337,   237,  1094,   389,
     314,  -239,   350,   356,   -17,   411,   412,   335,  -239,   361,
     364,    31,   421,   422,   363,   426,   373,   375,   433,   379,
    -239,   377,  -239,   438,   439,   387,  -239,   380,   441,  -239
  };

  const unsigned char
  parser::yydefact_[] =
  {
      16,     0,     2,     1,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     3,     0,     4,     5,     6,     7,     8,     9,    10,
     144,    11,     0,   161,    12,     0,    13,    14,    18,     0,
      54,    55,    58,     0,     0,     0,    34,    80,    74,    77,
      75,    76,    23,     0,   166,   169,     0,    21,    22,   132,
       0,   143,     0,     0,   162,     0,   163,     0,     0,   181,
      17,    39,     0,     0,     0,     0,     0,    73,     0,     0,
       0,   168,     0,     0,    81,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,    82,
      83,     0,     0,     0,     0,     0,   129,   131,     0,    35,
      85,     0,     0,   141,   142,     0,     0,     0,   138,   146,
     149,   151,   153,     0,   145,     0,   159,   171,   170,     0,
       0,    38,     0,    56,     0,     0,    51,     0,    53,     0,
      78,     0,    72,     0,    19,     0,    30,    24,     0,   164,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   127,     0,   108,     0,
       0,   109,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,     0,   147,
       0,     0,     0,     0,     0,     0,     0,     0,   160,     0,
       0,     0,   182,   172,   173,   174,   175,   176,   177,   179,
     180,   178,     0,    48,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,    26,     0,     0,     0,     0,     0,
       0,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,     0,     0,   112,     0,    87,     0,
      84,   107,    93,    94,    95,    96,    98,    97,    90,    88,
      89,    92,    91,   130,     0,     0,   148,   134,   137,   135,
     136,   150,   152,     0,   157,     0,   184,    36,    57,     0,
       0,     0,    50,    52,     0,    64,    66,    68,    70,     0,
       0,    25,     0,    20,    31,    32,     0,    27,   165,   122,
       0,   102,   103,     0,     0,     0,   118,     0,     0,   120,
       0,     0,   116,   104,   105,   128,   123,   125,     0,     0,
       0,   154,     0,     0,    40,    41,    42,    45,    46,    47,
      43,    44,     0,     0,     0,    49,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,   115,     0,   124,     0,
       0,     0,   156,     0,   158,    37,     0,     0,    65,    67,
      69,    71,     0,    33,   101,     0,   100,   119,    99,   121,
     117,   126,   139,   140,   155,     0,     0,    29,     0,     0,
       0,   106,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,    63,     0,     0,     0,    61,     0,     0,    62
  };

  const short int
  parser::yypgoto_[] =
  {
    -239,  -239,  -239,  -239,  -206,   327,  -239,  -239,  -239,     1,
    -239,  -239,  -239,  -239,  -208,   239,   329,     8,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,   330,   331,     5,  -239,   -59,
    -239,  -239,  -239,  -239,  -239,     9,  -239,   333,  -239,  -114,
     251,   339,  -238,  -239,   126,  -239,  -239,  -239,   334,  -239,
    -239,   -45,  -239,  -239,   336,   346,  -239
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,     2,    20,   146,    21,   225,   147,   229,    22,
     131,   132,   278,    23,   138,   139,    24,    40,    41,    25,
      26,    27,   384,   142,   143,    28,    29,    48,    49,   117,
     250,   318,   167,   107,   108,   118,   119,    31,    32,   120,
     121,   122,   123,   322,   274,   126,    66,    33,    34,   150,
      81,    55,    35,   129,    36,    37,   211
  };

  const short int
  parser::yytable_[] =
  {
     106,   189,     4,   310,     4,   136,   277,     4,     4,   282,
      62,    30,    47,    47,    47,    42,   223,    50,    51,   144,
     230,   294,   127,   128,   298,   285,   286,   358,   359,   296,
     246,    59,   158,   160,   231,   162,    60,   151,   247,   166,
      63,   297,   168,   169,   387,   171,   172,   291,   287,   288,
     360,   361,    67,    68,    77,   292,   388,   190,   266,    60,
     137,   197,     3,    69,   224,    38,   145,   343,    39,   241,
     345,   305,   124,   347,   308,   311,   335,    47,   -34,    61,
     133,   140,   271,   -34,   337,   394,    64,    65,   174,   175,
     395,    73,    43,   232,   233,   234,   235,   236,   237,   176,
     239,   177,   178,   179,   244,   245,   185,   186,   180,   181,
     182,    71,   183,    72,    44,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   355,   263,   264,   265,
     174,   175,    70,   267,   268,   269,   270,    45,    30,   213,
     214,   176,    46,   177,   178,   179,   221,   222,   348,   349,
     180,   181,   182,   174,   175,    74,   377,    83,    84,   110,
      86,   352,   353,    52,   176,    53,   177,   178,   179,    54,
     242,   111,   112,    87,    88,    89,    90,    91,    92,    93,
      94,   113,   114,   174,   175,    56,    57,    58,   315,    75,
     317,     4,    76,    80,   176,    78,   177,   178,   179,    79,
      82,    95,    96,   180,    97,   182,    98,   109,    99,   100,
       4,   101,   115,   116,   125,   134,   130,   176,     6,   177,
     178,   179,   103,    11,    12,    13,   201,    14,    15,    16,
      17,    18,    19,   104,   135,   141,   105,   148,   149,   161,
     170,   340,   152,   153,   341,   342,   154,   306,   344,   309,
     155,   156,   312,    83,    84,    85,    86,   163,   164,   202,
     350,   351,   187,   188,   197,   178,   174,   175,   196,    87,
      88,    89,    90,    91,    92,    93,    94,   176,   198,   177,
     178,   179,   199,   200,   192,   212,   180,   215,   216,   218,
     371,   220,   219,   217,   227,   228,   251,    95,    96,   249,
      97,   226,    98,   165,    99,   100,   378,   101,   273,   102,
     324,   325,   326,   327,   328,   329,   330,   331,   103,    83,
      84,    85,    86,   275,   276,   144,   173,   279,   280,   104,
     281,   136,   105,   174,   175,    87,    88,    89,    90,    91,
      92,    93,    94,   193,   176,   284,   177,   178,   179,   289,
     290,   194,   195,   180,   181,   182,   293,   183,   184,   295,
     323,   321,   332,    95,    96,   333,    97,   334,    98,   336,
      99,   100,   338,   101,   356,   102,   316,   339,   346,   363,
     357,   367,   369,   362,   103,    83,    84,    85,    86,   374,
     375,   376,   173,   379,   382,   104,   370,   383,   105,   174,
     175,    87,    88,    89,    90,    91,    92,    93,    94,   380,
     176,   385,   177,   178,   179,   386,   389,   390,   391,   180,
     181,   182,   392,   183,   184,   393,   396,   397,   398,    95,
      96,   399,    97,   400,    98,   401,    99,   100,   402,   101,
     403,   102,   404,   405,   406,   408,   409,   407,   272,   354,
     103,    83,    84,    85,    86,   191,   203,   283,   204,   205,
     206,   104,   207,   208,   105,   209,     0,    87,    88,    89,
      90,    91,    92,    93,    94,   210,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,     0,    97,     0,
      98,     0,    99,   100,     0,   101,     0,   157,     0,     0,
       0,     0,     0,     0,     0,     0,   103,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,   104,     0,     0,
     105,     0,     0,    87,    88,    89,    90,    91,    92,    93,
      94,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,    97,     0,    98,     0,    99,   100,
       0,   101,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   173,     0,     0,     0,     0,     0,     4,
     174,   175,     5,   104,   248,     0,   105,     0,     0,     0,
     193,   176,     0,   177,   178,   179,     0,     0,   194,   195,
     180,   181,   182,     0,   183,   184,     6,     7,     8,     9,
      10,    11,    12,    13,   173,    14,    15,    16,    17,    18,
      19,   174,   175,     0,     0,   248,   304,     0,     0,     0,
       0,     0,   176,     0,   177,   178,   179,     0,     0,     0,
     173,   180,   181,   182,     0,   183,   184,   174,   175,     0,
       0,   248,   307,     0,     0,     0,     0,   173,   176,     0,
     177,   178,   179,     0,   174,   175,     0,   180,   181,   182,
     238,   183,   184,     0,   173,   176,     0,   177,   178,   179,
       0,   174,   175,     0,   180,   181,   182,   240,   183,   184,
       0,   173,   176,     0,   177,   178,   179,     0,   174,   175,
       0,   180,   181,   182,   243,   183,   184,     0,     0,   176,
       0,   177,   178,   179,     0,     0,     0,   173,   180,   181,
     182,     0,   183,   184,   174,   175,     0,     0,   248,     0,
       0,     0,     0,     0,     0,   176,     0,   177,   178,   179,
       0,     0,     0,   173,   180,   181,   182,     0,   183,   184,
     174,   175,     0,     0,   299,     0,     0,     0,     0,     0,
       0,   176,     0,   177,   178,   179,     0,     0,     0,   173,
     180,   181,   182,     0,   183,   184,   174,   175,     0,     0,
       0,   300,     0,     0,     0,     0,     0,   176,     0,   177,
     178,   179,     0,     0,     0,   173,   180,   181,   182,     0,
     183,   184,   174,   175,     0,     0,   301,     0,     0,     0,
       0,     0,     0,   176,     0,   177,   178,   179,     0,     0,
       0,   173,   180,   181,   182,     0,   183,   184,   174,   175,
       0,     0,   302,     0,     0,     0,     0,     0,     0,   176,
       0,   177,   178,   179,     0,     0,     0,   173,   180,   181,
     182,     0,   183,   184,   174,   175,     0,     0,     0,   303,
       0,     0,     0,     0,     0,   176,     0,   177,   178,   179,
       0,     0,     0,   173,   180,   181,   182,     0,   183,   184,
     174,   175,     0,     0,   313,     0,     0,     0,     0,     0,
       0,   176,     0,   177,   178,   179,     0,     0,     0,   173,
     180,   181,   182,     0,   183,   184,   174,   175,     0,     0,
     314,     0,     0,     0,     0,     0,     0,   176,     0,   177,
     178,   179,     0,     0,     0,   173,   180,   181,   182,     0,
     183,   184,   174,   175,     0,     0,     0,   319,     0,     0,
       0,     0,     0,   176,     0,   177,   178,   179,     0,     0,
       0,   173,   180,   181,   182,     0,   183,   184,   174,   175,
       0,     0,     0,   320,     0,     0,     0,     0,     0,   176,
       0,   177,   178,   179,     0,     0,     0,   173,   180,   181,
     182,     0,   183,   184,   174,   175,     0,     0,   364,     0,
       0,     0,     0,     0,     0,   176,     0,   177,   178,   179,
       0,     0,     0,   173,   180,   181,   182,     0,   183,   184,
     174,   175,     0,     0,     0,   365,     0,     0,     0,     0,
       0,   176,     0,   177,   178,   179,     0,     0,     0,   173,
     180,   181,   182,     0,   183,   184,   174,   175,     0,     0,
     366,     0,     0,     0,     0,     0,     0,   176,     0,   177,
     178,   179,     0,     0,     0,   173,   180,   181,   182,     0,
     183,   184,   174,   175,     0,     0,   368,     0,     0,     0,
       0,     0,     0,   176,     0,   177,   178,   179,     0,     0,
       0,   173,   180,   181,   182,     0,   183,   184,   174,   175,
       0,     0,   372,     0,     0,     0,     0,     0,     0,   176,
       0,   177,   178,   179,     0,     0,     0,   173,   180,   181,
     182,     0,   183,   184,   174,   175,     0,     0,   373,     0,
       0,     0,     0,     0,     0,   176,     0,   177,   178,   179,
       0,     0,     0,   173,   180,   181,   182,     0,   183,   184,
     174,   175,     0,     0,   381,     0,     0,     0,     0,     0,
       0,   176,     0,   177,   178,   179,     0,     0,     0,     0,
     180,   181,   182,     0,   183,   184
  };

  const short int
  parser::yycheck_[] =
  {
      59,   115,     5,   241,     5,     5,   212,     5,     5,   217,
      31,     2,    11,    12,    13,     7,     5,    12,    13,     5,
      61,   227,    67,    68,   230,     4,     5,     4,     5,    61,
      53,    59,    91,    92,    75,    94,    64,    82,    61,    98,
      61,    73,   101,   102,    61,   104,   105,    53,    27,    28,
      27,    28,    61,    62,    59,    61,    73,   116,    60,    64,
      60,    63,     0,    72,    53,     4,    52,   305,     5,    72,
     308,    72,    63,   311,    72,    72,   284,    76,    59,    64,
      72,    76,   196,    64,   290,    54,    29,    30,    56,    57,
      59,    74,     5,   152,   153,   154,   155,   156,   157,    67,
     159,    69,    70,    71,   163,   164,    60,    61,    76,    77,
      78,    59,    80,    61,     5,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   332,   186,   187,   188,
      56,    57,     4,   192,   193,   194,   195,     5,   129,    60,
      61,    67,     5,    69,    70,    71,    60,    61,    60,    61,
      76,    77,    78,    56,    57,    59,   362,     3,     4,     5,
       6,    60,    61,     5,    67,     5,    69,    70,    71,     5,
     161,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    56,    57,     5,     5,     5,   247,    59,
     249,     5,    61,    74,    67,    66,    69,    70,    71,    66,
      66,    47,    48,    76,    50,    78,    52,     5,    54,    55,
       5,    57,    58,    59,     6,    75,     5,    67,    32,    69,
      70,    71,    68,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    79,     5,     5,    82,    72,     5,    62,
       5,   300,    59,    59,   303,   304,    59,   238,   307,   240,
      59,    59,   243,     3,     4,     5,     6,    59,    59,    73,
     319,   320,    59,    59,    63,    70,    56,    57,    61,    19,
      20,    21,    22,    23,    24,    25,    26,    67,    64,    69,
      70,    71,    62,    61,     7,    62,    76,    66,    61,    61,
     349,    66,    60,    62,    51,    83,     5,    47,    48,    59,
      50,    64,    52,    53,    54,    55,   365,    57,    59,    59,
       9,    10,    11,    12,    13,    14,    15,    16,    68,     3,
       4,     5,     6,     6,     5,     5,    49,     5,    59,    79,
       5,     5,    82,    56,    57,    19,    20,    21,    22,    23,
      24,    25,    26,    66,    67,    62,    69,    70,    71,     5,
      62,    74,    75,    76,    77,    78,     5,    80,    81,     5,
      62,     6,    62,    47,    48,     5,    50,    60,    52,    66,
      54,    55,     5,    57,    61,    59,    60,    83,    73,     5,
      62,    73,    73,    62,    68,     3,     4,     5,     6,     6,
       5,     5,    49,    61,     5,    79,    73,    83,    82,    56,
      57,    19,    20,    21,    22,    23,    24,    25,    26,    72,
      67,    61,    69,    70,    71,    59,     5,     5,    83,    76,
      77,    78,    61,    80,    81,    61,     5,     5,    65,    47,
      48,     5,    50,    60,    52,    60,    54,    55,     5,    57,
      61,    59,    65,     5,     5,    65,     5,    60,   197,   323,
      68,     3,     4,     5,     6,   116,   129,   218,   129,   129,
     129,    79,   129,   129,    82,   129,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,    -1,
      52,    -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      82,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    50,    -1,    52,    -1,    54,    55,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    49,    -1,    -1,    -1,    -1,    -1,     5,
      56,    57,     8,    79,    60,    -1,    82,    -1,    -1,    -1,
      66,    67,    -1,    69,    70,    71,    -1,    -1,    74,    75,
      76,    77,    78,    -1,    80,    81,    32,    33,    34,    35,
      36,    37,    38,    39,    49,    41,    42,    43,    44,    45,
      46,    56,    57,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      49,    76,    77,    78,    -1,    80,    81,    56,    57,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    49,    67,    -1,
      69,    70,    71,    -1,    56,    57,    -1,    76,    77,    78,
      62,    80,    81,    -1,    49,    67,    -1,    69,    70,    71,
      -1,    56,    57,    -1,    76,    77,    78,    62,    80,    81,
      -1,    49,    67,    -1,    69,    70,    71,    -1,    56,    57,
      -1,    76,    77,    78,    62,    80,    81,    -1,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    49,    76,    77,
      78,    -1,    80,    81,    56,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,    71,
      -1,    -1,    -1,    49,    76,    77,    78,    -1,    80,    81,
      56,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,    49,
      76,    77,    78,    -1,    80,    81,    56,    57,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,
      70,    71,    -1,    -1,    -1,    49,    76,    77,    78,    -1,
      80,    81,    56,    57,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    69,    70,    71,    -1,    -1,
      -1,    49,    76,    77,    78,    -1,    80,    81,    56,    57,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    49,    76,    77,
      78,    -1,    80,    81,    56,    57,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,    71,
      -1,    -1,    -1,    49,    76,    77,    78,    -1,    80,    81,
      56,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,    49,
      76,    77,    78,    -1,    80,    81,    56,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,
      70,    71,    -1,    -1,    -1,    49,    76,    77,    78,    -1,
      80,    81,    56,    57,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    69,    70,    71,    -1,    -1,
      -1,    49,    76,    77,    78,    -1,    80,    81,    56,    57,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    49,    76,    77,
      78,    -1,    80,    81,    56,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,    71,
      -1,    -1,    -1,    49,    76,    77,    78,    -1,    80,    81,
      56,    57,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,    49,
      76,    77,    78,    -1,    80,    81,    56,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,
      70,    71,    -1,    -1,    -1,    49,    76,    77,    78,    -1,
      80,    81,    56,    57,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    69,    70,    71,    -1,    -1,
      -1,    49,    76,    77,    78,    -1,    80,    81,    56,    57,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    49,    76,    77,
      78,    -1,    80,    81,    56,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,    71,
      -1,    -1,    -1,    49,    76,    77,    78,    -1,    80,    81,
      56,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,
      76,    77,    78,    -1,    80,    81
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    86,    87,     0,     5,     8,    32,    33,    34,    35,
      36,    37,    38,    39,    41,    42,    43,    44,    45,    46,
      88,    90,    94,    98,   101,   104,   105,   106,   110,   111,
     120,   122,   123,   132,   133,   137,   139,   140,     4,     5,
     102,   103,   102,     5,     5,     5,     5,    94,   112,   113,
     112,   112,     5,     5,     5,   136,     5,     5,     5,    59,
      64,    64,    31,    61,    29,    30,   131,    61,    62,    72,
       4,    59,    61,    74,    59,    59,    61,    59,    66,    66,
      74,   135,    66,     3,     4,     5,     6,    19,    20,    21,
      22,    23,    24,    25,    26,    47,    48,    50,    52,    54,
      55,    57,    59,    68,    79,    82,   114,   118,   119,     5,
       5,    17,    18,    27,    28,    58,    59,   114,   120,   121,
     124,   125,   126,   127,   120,     6,   130,   136,   136,   138,
       5,    95,    96,   102,    75,     5,     5,    60,    99,   100,
     112,     5,   108,   109,     5,    52,    89,    92,    72,     5,
     134,   136,    59,    59,    59,    59,    59,    59,   114,    59,
     114,    62,   114,    59,    59,    53,   114,   117,   114,   114,
       5,   114,   114,    49,    56,    57,    67,    69,    70,    71,
      76,    77,    78,    80,    81,    60,    61,    59,    59,   124,
     114,   126,     7,    66,    74,    75,    61,    63,    64,    62,
      61,    40,    73,    90,   101,   110,   111,   122,   133,   139,
     140,   141,    62,    60,    61,    66,    61,    62,    61,    60,
      66,    60,    61,     5,    53,    91,    64,    51,    83,    93,
      61,    75,   114,   114,   114,   114,   114,   114,    62,   114,
      62,    72,   120,    62,   114,   114,    53,    61,    60,    59,
     115,     5,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,    60,   114,   114,   114,
     114,   124,   125,    59,   129,     6,     5,    89,    97,     5,
      59,     5,    99,   100,    62,     4,     5,    27,    28,     5,
      62,    53,    61,     5,    89,     5,    61,    73,    89,    60,
      61,    60,    60,    61,    61,    72,   120,    61,    72,   120,
     127,    72,   120,    60,    60,   114,    60,   114,   116,    61,
      61,     6,   128,    62,     9,    10,    11,    12,    13,    14,
      15,    16,    62,     5,    60,    99,    66,    89,     5,    83,
     114,   114,   114,   127,   114,   127,    73,   127,    60,    61,
     114,   114,    60,    61,   129,    89,    61,    62,     4,     5,
      27,    28,    62,     5,    60,    61,    60,    73,    60,    73,
      73,   114,    60,    60,     6,     5,     5,    89,   114,    61,
      72,    60,     5,    83,   107,    61,    59,    61,    73,     5,
       5,    83,    61,    61,    54,    59,     5,     5,    65,     5,
      60,    60,     5,    61,    65,     5,     5,    60,    65,     5
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    85,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    99,   100,   100,   101,   102,   102,   103,   104,   105,
     106,   107,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   109,   109,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   123,   123,   124,   124,   124,   125,
     125,   126,   126,   127,   128,   128,   129,   130,   130,   131,
     132,   133,   133,   133,   134,   134,   135,   135,   136,   137,
     137,   137,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   139,   140,   141
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     3,     2,     1,
       3,     2,     2,     2,     4,     6,     5,     6,     3,     5,
       1,     3,     2,     4,     1,     3,     3,     5,     1,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     7,
       6,     1,     3,     1,     2,     1,     3,     5,     2,    16,
      12,     8,    10,     6,     3,     5,     3,     5,     3,     5,
       3,     5,     1,     0,     2,     2,     2,     1,     3,     4,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     6,
       6,     6,     4,     4,     4,     4,     8,     3,     2,     2,
       2,     2,     3,     1,     3,     5,     4,     6,     4,     6,
       4,     6,     4,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     0,     4,     3,     3,     3,     3,     1,     6,
       6,     1,     1,     2,     1,     3,     1,     2,     3,     1,
       3,     1,     3,     1,     1,     3,     3,     3,     5,     2,
       4,     1,     2,     2,     1,     3,     0,     3,     2,     2,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     4,     4,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"reserved keyword\"",
  "\"symbol\"", "\"identifier\"", "\"number\"", "\"relational operator\"",
  "\"pragma directive\"", "\"relation qualifier output\"",
  "\"relation qualifier input\"", "\"relation qualifier printsize\"",
  "\"BRIE datastructure qualifier\"", "\"BTREE datastructure qualifier\"",
  "\"equivalence relation qualifier\"",
  "\"relation qualifier overidable\"", "\"relation qualifier inline\"",
  "\"match predicate\"",
  "\"checks whether substring is contained in a string\"",
  "\"concatenation of two strings\"", "\"ordinal number of a string\"",
  "\"length of a string\"", "\"sub-string of a string\"",
  "\"min aggregator\"", "\"max aggregator\"", "\"count aggregator\"",
  "\"sum aggregator\"", "\"true literal constraint\"",
  "\"false literal constraint\"", "\"strict marker\"", "\"plan keyword\"",
  "\":-\"", "\"relation declaration\"", "\"lattice declaration\"",
  "\"lattice components type declaration\"",
  "\"lattice binary function definition\"", "\"functor declaration\"",
  "\"input directives declaration\"", "\"output directives declaration\"",
  "\"printsize directives declaration\"",
  "\"override rules of super-component\"", "\"type declaration\"",
  "\"enum declaration\"", "\"component declaration\"",
  "\"component instantiation\"", "\"numeric type declaration\"",
  "\"symbolic type declaration\"", "\"convert string to number\"",
  "\"convert number to string\"", "\"type cast\"", "\"nil reference\"",
  "\"|\"", "\"[\"", "\"]\"", "\"_\"", "\"$\"", "\"+\"", "\"-\"", "\"!\"",
  "\"(\"", "\")\"", "\",\"", "\":\"", "\";\"", "\".\"", "\"=>\"", "\"=\"",
  "\"*\"", "\"@\"", "\"/\"", "\"^\"", "\"%\"", "\"{\"", "\"}\"", "\"<\"",
  "\">\"", "\"band\"", "\"bor\"", "\"bxor\"", "\"bnot\"", "\"land\"",
  "\"lor\"", "\"lnot\"", "\"case\"", "NEG", "$accept", "program", "unit",
  "pragma", "type_id", "type", "recordtype", "uniontype", "enumtype",
  "rel_id", "non_empty_attributes", "attributes", "qualifiers",
  "functor_decl", "functor_type", "functor_typeargs", "relation_decl",
  "relation_list", "relation_body", "lattice_decl", "lattice_asscoiation",
  "lattice_def", "lattice_def_type", "non_empty_key_value_pairs",
  "key_value_pairs", "load_head", "store_head", "iodirective_list",
  "iodirective_body", "arg", "functor_list", "functor_args", "recordlist",
  "non_empty_arg_list", "arg_list", "atom", "literal", "fact", "head",
  "term", "conjunction", "disjunction", "body", "exec_order_list",
  "exec_order", "exec_plan_list", "exec_plan", "rule_def", "rule",
  "type_param_list", "type_params", "comp_type", "component_head",
  "component_body", "component", "comp_init", "comp_override", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   231,   231,   235,   238,   241,   244,   248,   252,   256,
     259,   262,   265,   268,   271,   274,   277,   282,   287,   296,
     299,   306,   310,   314,   318,   323,   328,   333,   341,   345,
     351,   355,   361,   367,   378,   381,   389,   396,   405,   408,
     413,   417,   421,   425,   429,   433,   437,   441,   445,   450,
     454,   461,   471,   472,   476,   481,   484,   493,   501,   509,
     515,   526,   530,   534,   541,   545,   549,   553,   557,   561,
     565,   569,   575,   578,   584,   591,   597,   605,   608,   617,
     623,   632,   636,   640,   644,   649,   653,   657,   660,   664,
     668,   672,   676,   680,   684,   688,   692,   696,   700,   704,
     708,   712,   716,   720,   724,   728,   732,   739,   743,   754,
     758,   762,   766,   770,   774,   780,   795,   802,   818,   825,
     841,   848,   864,   870,   873,   879,   883,   890,   894,   900,
     904,   910,   913,   918,   927,   932,   937,   942,   947,   951,
     956,   961,   966,   974,   982,   985,   992,   995,   999,  1005,
    1008,  1016,  1019,  1027,  1032,  1036,  1043,  1050,  1054,  1061,
    1068,  1090,  1093,  1097,  1105,  1108,  1115,  1117,  1124,  1131,
    1135,  1139,  1145,  1149,  1153,  1157,  1161,  1165,  1171,  1175,
    1179,  1183,  1188,  1198,  1207
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 3968 "parser.cc" // lalr1.cc:1167
#line 1211 "./parser.yy" // lalr1.cc:1168

void yy::parser::error(const location_type &l, const std::string &m) {
    driver.error(l, m);
}
