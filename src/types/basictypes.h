#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H

#include <string>

namespace Types {
    class Name {
    private:
        std::string d_name;
    };

    class Number {
    private:
        union {
            int64_t d_integer;
            double d_double;
        } d_number;
    };
}

#endif