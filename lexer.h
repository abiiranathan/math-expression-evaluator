#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {
    INTEGER,
    OPERATOR,
    LEFT_PAREN,
    RIGHT_PAREN,
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
   public:
    std::vector<Token> lex(std::vector<std::string> tokens);
};

#endif  // LEXER_H