#ifndef EXPRESSION_STATEMENT_H
#define EXPRESSION_STATEMENT_H

#include <vector>
#include <memory>
#include <experimental/optional>

#include "basictypes.h"
#include "operators.h"

namespace Types {

    class ArgList;
    class CompFor;
    class CompIter;
    class Expression;
    class Factor;
    class OrTest;
    class SubscriptList;
    class Test;
    class Trailer;
    class TestNoCondition;
    class VarArgsList;


    class Argument {
    public:
        virtual ~Argument() = 0;
    };

    class ArgumentCompFor : public Argument {
    public:
        ~ArgumentCompFor() {}
    private:
        std::unique_ptr<Test> d_test;
        std::unique_ptr<CompFor> d_compFor;
    };

    class ArgumentTest : public Argument {
    public:
        ~ArgumentTest() {}
    private:
        std::unique_ptr<Test> d_testLhs;
        std::unique_ptr<Test> d_testRhs;
    };

    class ArgumentKwargs : public Argument {
    public:
        ~ArgumentKwargs() {}
    private:
        std::unique_ptr<Test> d_test;
    };

    class ArgumentStarArgs : public Argument {
    public:
        ~ArgumentStarArgs() {}
    private:
        std::unique_ptr<Test> d_test;
    };

    class ArgList {
    private:
        std::vector<Argument> d_arguments;
    };

    class SliceOp {
    private:
        std::unique_ptr<Test> d_test;
    };

    class Subscript {
    public:
        virtual ~Subscript() {}
    };

    class SubscriptTest : public Subscript {
    public:
        ~SubscriptTest() {}
    private:
        std::unique_ptr<Test> d_test;
    };

    class SubscriptSlice : public Subscript {
    public:
        ~SubscriptSlice() {}
    private:
        std::unique_ptr<Test> d_testLhs;
        std::unique_ptr<Test> d_testRhs;
        SliceOp d_slice;
    };

    class SubscriptList {
    private:
        std::vector<Subscript> d_subscript;
    };

    class VfpDef {
    private:
        Name d_name;
    };

    class VfpDefTest {
    private:
        VfpDef d_def;
        std::unique_ptr<Test> d_test;
    };

    // Rule 1: vfpdef ['=' test] (',' vfpdef ['=' test])*
    //         [',' ['*' [vfpdef] (',' vfpdef ['=' test])* [',' '**' vfpdef] | '**' vfpdef]]
    //
    // Rule 2: '*' [vfpdef] (',' vfpdef ['=' test])* [',' '**' vfpdef] | '**' vfpdef
    class VarArgsList {
    public:
        virtual ~VarArgsList() = 0;
    };

    class VarArgsList1 {
    public:
        ~VarArgsList1() {}
    private:
        std::vector<VfpDefTest> d_defTests;
        std::experimental::optional<VfpDef> d_def;
        std::vector<VfpDefTest> d_argDefs;
        std::experimental::optional<VfpDef> d_args;
        std::experimental::optional<VfpDef> d_kwargs;
    };

    class VarArgsList2 {
    public:
        ~VarArgsList2() {}
    private:
        VfpDef d_def;
        std::vector<VfpDefTest> d_defTests;
        std::experimental::optional<VfpDef> d_args;
        std::experimental::optional<VfpDef> d_kwargs;
    };

    class Trailer {
    public:
        virtual ~Trailer() = 0;
    };

    class FunctionTrailer : public Trailer {
    public:
        ~FunctionTrailer() {}
    private:
        ArgList d_argList;
    };

    class SubscriptTrailer : public Trailer {
    public:
        ~SubscriptTrailer() {}
    private:
        SubscriptList d_subscriptList;
    };

    class CallTrailer : public Trailer {
    public:
        ~CallTrailer() {}
    private:
        Name d_name;
    };

    class YieldArg {
    private:
        std::vector<Test> d_tests;
    };

    class YieldExpr {
    private:
        std::experimental::optional<YieldArg> d_arg;
    };

    class StarExpr {
    private:
        std::unique_ptr<Expression> d_expr;
    };

    class TestStarExpr {
    private:
        std::unique_ptr<Test> d_test;
        std::experimental::optional<StarExpr> d_star;
    };

    class CompIf {
    private:
        std::unique_ptr<TestNoCondition> d_testNoCondition;
        std::unique_ptr<CompIter> d_compIter;
    };

    class CompIter {
    private:
        std::unique_ptr<CompFor> d_compFor;
        std::unique_ptr<CompIf> d_compIf;
    };

    class ExprStarExpr {
        std::unique_ptr<Expression> d_expr;
        std::unique_ptr<StarExpr> d_starExpr;
    };

    class CompFor {
    private:
        std::vector<ExprStarExpr> d_testStarExprs;
        std::unique_ptr<OrTest> d_orTest;
        CompIter d_compIter;
    };

    // (test|star_expr) ( comp_for | (',' (test|star_expr))* [','] )
    class TestListComp {
    private:
        TestStarExpr d_testStarExpr;
        std::experimental::optional<CompFor> d_compFor;
        std::vector<TestStarExpr> d_testStars;
    };

    // Rule 1: (test ':' test | '**' expr) (comp_for | (',' (test ':' test | '**' expr))* [','])
    //
    // Rule 2: (test | star_expr) (comp_for | (',' (test | star_expr))* [','])
    class DictOrSetMaker {
    public:
        virtual ~DictOrSetMaker() = 0;
    };

    class TestExpr {
    private:
        typedef std::unique_ptr<Test> TestPtr;
        std::unique_ptr<std::tuple<TestPtr ,TestPtr>> d_test;
        std::unique_ptr<Expression> d_kwargs;
    };

    class DictOrSetMaker1 {
    public:
        ~DictOrSetMaker1() {}
    private:
        typedef std::unique_ptr<Test> TestPtr;
        std::unique_ptr<std::tuple<TestPtr, TestPtr>> d_test;
        std::unique_ptr<Expression> d_kwargs;

        std::unique_ptr<CompFor> d_compFor;
        std::vector<TestExpr> d_exprs;
    };

    class DictOrSetMaker2 {
    public:
        ~DictOrSetMaker2() {}
    private:
        TestStarExpr d_testStar;

        std::unique_ptr<CompFor> d_compFor;
        std::vector<TestStarExpr> d_exprs;
    };

    class Atom {
    public:
        virtual ~Atom() = 0;
    };

    class BracketAtom : public Atom {
    public:
        ~BracketAtom() {}
    private:
        std::experimental::optional<YieldExpr> d_yieldExpr;
        std::experimental::optional<TestListComp> d_testListComp;
    };

    class SubscriptAtom : public Atom {
    public:
        ~SubscriptAtom() {}
    private:
        std::experimental::optional<TestListComp> d_testListComp;
    };

    class BraceAtom : public Atom {
    public:
        ~BraceAtom() {}
    private:
        std::unique_ptr<DictOrSetMaker> d_dictOrSet;
    };

    class NameAtom : public Atom {
    public:
        ~NameAtom() {}
    private:
        Name d_name;
    };

    class NumberAtom : public Atom {
    public:
        ~NumberAtom() {}
    private:
        Number d_number;
    };

    class StringAtom : public Atom {
    public:
        ~StringAtom() {}
    private:
        std::vector<std::string> d_strings;
    };

    class EllipsisAtom : public Atom {
    public:
        ~EllipsisAtom() {}
    };

    class NoneAtom : public Atom {
    public:
        ~NoneAtom() {}
    };

    class TrueAtom : public Atom {
    public:
        ~TrueAtom() {}
    };

    class FalseAtom : public Atom {
    public:
        ~FalseAtom() {}
    };

    // Not sure what this actually means:
    // [AWAIT] atom trailer*
    // assuming it should be:
    // "await" atom trailer*
    class AtomExpression {
    private:
        bool d_isAwait;
        std::unique_ptr<Atom> d_Atom;
        std::vector<Trailer> d_trailers;
    };

    class Power {
        AtomExpression d_atomExpr;
        std::unique_ptr<Factor> d_factor;
    };

    class Factor {
    private:
        std::vector<UnaryPrefix> d_prefixes;
        Power d_power;
    };

    class SubFactor {
    private:
        SimpleOperator d_operator;
        Factor d_factor;
    };

    class Term {
    private:
        Factor d_factor;
        std::vector<SubFactor> d_subFactors;
    };

    class ArithSubExpression {
    private:
        NegateOperator d_negate;
        Term d_term;
    };

    class ArithExpression {
    private:
        Term d_term;
        std::vector<ArithSubExpression> d_subTerms;
    };

    class ShiftSubExpression {
    private:
        ShiftOperator d_operator;
        ArithExpression d_arith;
    };

    class ShiftExpression {
    private:
        ArithExpression d_arith;
        std::vector<ShiftSubExpression> d_shiftExpr;
    };

    class AndExpression {
    private:
        std::vector<ShiftExpression> d_shifts;
    };

    class XorExpression {
    private:
        std::vector<AndExpression> d_andExpr;
    };

    class Expression {
    private:
        std::vector<XorExpression> d_xorExpr;
    };

    class ExprComparison {
    private:
        Expression d_expr;
        ComparisonOperator d_operator;
    };

    class Comparison {
    private:
        Expression d_expr;
        std::vector<ExprComparison> d_exprComparison;
    };

    // We do a slight optimisation here to avoid complicating the class hierarchy:
    // We fold the (potentially) nested not statements together -
    // i.e. "not not not False" gets folded into "not False"
    class NotTest {
        NotTest() : isNot(false) {}
    private:
        bool isNot;
        Comparison d_comparison;
    };

    class AndTest {
    private:
        std::vector<NotTest> d_notTest;
    };

    class OrTest {
    private:
        std::vector<AndTest> d_andTest;
    };

    class IfTest {
    private:
        OrTest d_orTest;
        std::unique_ptr<Test> d_test;
    };

    // or_test ['if' or_test 'else' test] | lambdef
    class Test {
    public:
        virtual ~Test() = 0;
    };

    // or_test ['if' or_test 'else' test]
    class ExtraTest : public Test {
    public:
        ~ExtraTest() {}

    private:
        OrTest d_orTest;
        std::experimental::optional<IfTest> d_ifTest;

    };

    class LambdaDefinition : public Test {
    public:
        ~LambdaDefinition() {}
    private:
        std::unique_ptr<VarArgsList> d_argsList;
        std::unique_ptr<Test> d_test;
    };

    class LambdaDefinitionNoCondition {
    private:
        std::unique_ptr<VarArgsList> d_argsList;
        std::unique_ptr<TestNoCondition> d_testNoCond;
    };

    class TestNoCondition {
    private:
        std::experimental::optional<OrTest> d_orTest;
        std::experimental::optional<LambdaDefinitionNoCondition> d_lambda;
    };

    class SubExpression1 {
    private:
        AugmentedAssign d_assign;
        std::experimental::optional<YieldExpr> d_yield;
        std::vector<Test> d_testList;
    };

    class SubExpression2 {
    private:
        std::experimental::optional<YieldExpr> d_yield;
        std::vector<TestStarExpr> d_tests;
    };

    // testlist_star_expr (augassign (yield_expr|testlist) | ('=' (yield_expr|testlist_star_expr))*)
    class ExpressionStmt {
    private:
        std::vector<TestStarExpr> d_testStar;

        std::experimental::optional<SubExpression1> d_augAssignExpr;

        std::vector<SubExpression2> d_assignExpr;
    };
}

#endif