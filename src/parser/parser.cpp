#include "parser.h"

#include <iostream>

namespace Parser {

    Parser::Parser(std::istream& stream)
    : d_stream(stream)
    , d_currentIndent(0)
    , d_indentSize(0)
    {}


    // welcome to the horror of horrors.
    void Parser::process()
    {
        std::string line;

        std::getline(d_stream, line);

        processLine(line);
    }

    // handle whitespace later.
    // for just assume we're at the right level for
    bool Parser::processInitialWhitespace(const std::string& line)
    {
        return true;
    }

    void Parser::processLine(const std::string& line)
    {
        if (not processInitialWhitespace(line))
        {
            std::cerr << "Bad whitespace changes, skipping\n";
        }

        
    }
}