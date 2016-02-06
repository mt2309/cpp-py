

namespace Types {
    // small_stmt: (expr_stmt | del_stmt | pass_stmt | flow_stmt |
    // import_stmt | global_stmt | nonlocal_stmt | assert_stmt)
    class SmallStatement {
    public:
        virtual ~SmallStatement() = 0;
    };

    class ExpressionStatement : public SmallStatement {
    public:
        ~ExpressionStatement() {}
    };

    class DeleteStatement : public SmallStatement {
    public:
        ~DeleteStatement() {}
    };

    class PassStatement : public SmallStatement {
    public:
        ~PassStatement() {}
    };

    class FlowStatement : public SmallStatement {
    public:
        ~FlowStatement() {}
    };

    class ImportStatement : public SmallStatement {
    public:
        ~ImportStatement() {}
    };

    class GlobalStatement : public SmallStatement {
    public:
        ~GlobalStatement() {}
    };

    class NonLocalStatement : public SmallStatement {
    public:
        ~NonLocalStatement() {}
    };

    class AssertStatement : public SmallStatement {
    public:
        ~AssertStatement() {}
    };
}