#ifndef OPERATORS_H
#define OPERATORS_H

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

    // '<'|'>'|'=='|'>='|'<='|'<>'|'!='|'in'|'not' 'in'|'is'|'is' 'not'
    enum class ComparisonOperator {
        LESS_THAN,
        GREATER_THAN,
        EQUAL,
        LESS_THAN_EQUAL,
        GREATER_THAN_EQUAL,
        DIAMOND,
        NOT_EQUAL,
        IN,
        NOT_IN,
        IS,
        IS_NOT
    };

    enum class ShiftOperator {
        LEFT_SHIFT,
        RIGHT_SHIFT
    };

    enum class NegateOperator {
        POSITIVE,
        NEGATIVE
    };

    enum class SimpleOperator {
        MUlT,
        AT,
        DIV,
        MOD,
        FLOOR_DIV
    };

    enum class UnaryPrefix {
        POSITIVE,
        NEGATIVE,
        BIT_NOT
    };

    enum class ImportOperator {
        PERIOD,
        ELLIPSIS
    };

    enum class Token {
        
    };
}

#endif
