#ifndef SMALL_STATEMENT_H
#define SMALL_STATEMENT_H

#include "expressionstatement.h"

namespace Types {
    // small_stmt: (expr_stmt | del_stmt | pass_stmt | flow_stmt |
    // import_stmt | global_stmt | nonlocal_stmt | assert_stmt)
    class SmallStatement {
    public:
        virtual ~SmallStatement() = 0;
    };

    class ExpressionStatement final : public SmallStatement {
    public:
        ~ExpressionStatement() {}
    private:
        ExpressionStmt d_exprStmt;
    };

    class DeleteStatement final : public SmallStatement {
    public:
        ~DeleteStatement() {}
    private:
        ExprStarExpr d_expr;
    };

    class PassStatement final : public SmallStatement {
    public:
        ~PassStatement() {}
    };

    // break_stmt | continue_stmt | return_stmt | raise_stmt | yield_stmt
    class FlowStatement : public SmallStatement {
    public:
        virtual ~FlowStatement() = 0;
    };

    class BreakStatement final : public FlowStatement {
    public:
        ~BreakStatement() {};
    };

    class ContinueStatement final : public FlowStatement {
    public:
        ~ContinueStatement() {};
    };

    class ReturnStatement final : public FlowStatement {
    public:
        ~ReturnStatement() {};
    private:
        std::vector<std::unique_ptr<Test>> d_testList;
    };

    class RaiseStatement final : public FlowStatement {
    public:
        ~RaiseStatement() {};
    private:
        std::unique_ptr<Test> d_test;
        std::unique_ptr<Test> d_fromTest;
    };

    class YieldStatement final : public FlowStatement {
    public:
        ~YieldStatement() {};
    private:
        YieldExpr d_yieldExpr;
    };

    class ImportStatement : public SmallStatement {
    public:
        virtual ~ImportStatement() = 0;
    };

    class DottedName {
    private:
        std::vector<Name> d_dottedNames;
    };

    class DottedAsName {
    private:
        DottedName d_dotted;
        std::experimental::optional<Name> d_name;
    };

    class ImportName : public ImportStatement {
    public:
        ~ImportName() {}
    private:
        std::vector<DottedAsName> d_dottedNames;
    };

    class ImportAsName {
        Name d_name;
        std::experimental::optional<Name> d_asName;
    };

    // 'from' (('.' | '...')* dotted_name | ('.' | '...')+)
    // 'import' ('*' | '(' import_as_names ')' | import_as_names)
    class ImportFrom : public ImportStatement {
    public:
        ~ImportFrom() {}
    private:
        // comment line 1
        std::vector<ImportOperator> d_fromPath;
        DottedName d_name;
        std::vector<ImportOperator> d_relativePath;

        // comment line 2
        bool isStar;
        std::vector<ImportAsName> d_importNames;
    };

    class GlobalStatement final : public SmallStatement {
    public:
        ~GlobalStatement() {}
    private:
        std::vector<Name> d_globalNames;
    };

    class NonLocalStatement final : public SmallStatement {
    public:
        ~NonLocalStatement() {}
    private:
        std::vector<Name> d_nonLocalNames;
    };

    class AssertStatement final : public SmallStatement {
    public:
        ~AssertStatement() {}
    private:
        std::unique_ptr<Test> d_test;
        std::unique_ptr<Test> d_optTest;
    };
}

#endif