namespace Types {
    // if_stmt | while_stmt | for_stmt | try_stmt | with_stmt | funcdef | classdef | decorated | async_stmt
    class CompoundStmt {
    public:
        virtual ~CompoundStmt() = 0;
    };

    class IfStatement : public CompoundStmt {
    public:
        ~IfStatement() {}
    };

    class ForStatement : public CompoundStmt {
    public:
        ~ForStatement() {}
    };

    class TryStatement : public CompoundStmt {
    public:
        ~TryStatement() {}
    };

    class WithStatement : public CompoundStmt {
    public:
        ~WithStatement() {}
    };

    class FunctionDefinition : public CompoundStmt {
    public:
        ~FunctionDefinition() {}
    };

    class ClassDefinition : public CompoundStmt {
    public:
        ~ClassDefinition() {}
    };

    class Decorated : public CompoundStmt {
    public:
        ~Decorated() {}
    };

    class AsyncStatement : public CompoundStmt {
    public:
        ~AsyncStatement() {}
    };
}