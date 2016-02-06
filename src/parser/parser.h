//
//  parser.h
//  cpp-py
//
//  Created by Michael Thorpe on 06/02/2016.
//
//

#include <istream>

#include "types/statement.h"
#include "lexer/lexer.h"

#ifndef parser_h
#define parser_h


namespace Parser
{
    class Parser
    {
        public:
            Parser(std::istream& stream);

        private:
            Lexer::Lexer d_lexer;        
    };
}


#endif /* parser_h */
