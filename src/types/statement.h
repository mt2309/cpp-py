#include <vector>
#include <string>
#include <memory>

#include "smallstatement.h"
#include "compoundstatement.h"

// These basically embeds the grammar from https://docs.python.org/3/reference/grammar.html
// directly. Subclassing is very heavily (and probably very inefficiently) used.

namespace Types {

    // stmt: simple_stmt | compound_stmt
    class Statement {
    public:
        virtual ~Statement() = 0;
    };

    class SimpleStatement : public Statement {
    public:
        ~SimpleStatement() {}

        void addStatement(const std::shared_ptr<SmallStatement>& stmt)
        {
            d_statements.push_back(stmt);
        }

    private:
        std::vector<std::shared_ptr<SmallStatement>> d_statements;
    };

    class CompoundStatement : public Statement {
    public:
        ~CompoundStatement() {};

    private:
        std::shared_ptr<CompoundStmt> d_compoundStatement;
    };
}