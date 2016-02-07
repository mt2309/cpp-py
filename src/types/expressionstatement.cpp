#include <vector>

namespace Types {
    // ('+=' | '-=' | '*=' | '@=' | '/=' | '%=' | '&=' | '|=' | '^=' | '<<=' | '>>=' | '**=' | '//=')
    enum class AugmentedAssign {
        PLUS_EQUAL,    // +=
        MINUS_EQUAL,   // -=
        MULT_EQUAL,    // *=
        AT_EQUAL,      // @=
        DIV_EQUAL,     // /=
        MOD_EQUAL,     // %=
        AND_EQUAL,     // &=
        OR_EQUAL,      // |=
        XOR_EQUAL,     // ^=
        LSHIFT_EQUAL,  // <<=
        RSHIFT_EQUAL,  // >>=
        POW_EQUAL,     // **=
        FLOORDIV_EQUAL // //=
    };


    class TestStar {};

    // testlist_star_expr (augassign (yield_expr|testlist) | ('=' (yield_expr|testlist_star_expr))*)
    class ExpressionStmt {
    private:
        std::vector<TestStar> d_testStar;
    };
}