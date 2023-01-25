#include "lexer.h"

#include <map>

std::vector<Token> Lexer::lex(std::vector<std::string> tokens) {
    std::vector<Token> lexedTokens;
    std::map<std::string, TokenType> operatorType{
        {"+", TokenType::OPERATOR}, {"-", TokenType::OPERATOR}, {"*", TokenType::OPERATOR},
        {"/", TokenType::OPERATOR}, {"^", TokenType::OPERATOR}, {"%", TokenType::OPERATOR},
    };

    for (const auto& token : tokens) {
        if (token == "(") {
            lexedTokens.push_back({TokenType::LEFT_PAREN, token});
        } else if (token == ")") {
            lexedTokens.push_back({TokenType::RIGHT_PAREN, token});
        } else if (operatorType.count(token)) {
            lexedTokens.push_back({operatorType[token], token});
        } else {
            lexedTokens.push_back({TokenType::INTEGER, token});
        }
    }

    return lexedTokens;
}
