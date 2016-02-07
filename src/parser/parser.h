//
//  parser.h
//  cpp-py
//
//  Created by Michael Thorpe on 06/02/2016.
//
//

#include <istream>
#include <memory>
#include <vector>

#include "types/statement.h"

#ifndef parser_h
#define parser_h


namespace Parser
{
    class Parser
    {
    public:
        typedef std::vector<std::unique_ptr<Types::Statement>> ParseTree;
        Parser(std::istream& stream);

        void process();


        const ParseTree& tree() const { return d_tree; }



    private:

        void processLine(const std::string& line);
        bool processInitialWhitespace(const std::string& line);

        std::istream& d_stream;
        std::string d_currentToken;
        size_t d_currentIndent;

        // negative values indicate number of tabs
        // positive values indicate number of spaces
        int8_t d_indentSize;

        ParseTree d_tree;
    };
}


#endif /* parser_h */
