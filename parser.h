#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <vector>

#include "lexer.h"

class Parser {
   public:
    double parse(std::vector<Token> tokens);
};

#endif  // PARSER_H