#include "tokenizer.h"

#include <iostream>
#include <sstream>

std::vector<std::string> Tokenizer::tokenize(std::string expression) {
    std::vector<std::string> tokens;
    std::string token = "";
    std::string ops = "+-*/()^%";

    for (auto c : expression) {
        // Skip empty space
        if (c == ' ') continue;

        // handle operator
        if (ops.find(c) != std::string::npos) {
            if (!token.empty()) {
                tokens.push_back(token);  // push number into the token vector
            }

            token.clear();            // reset token
            token += c;               // Current token is the operator
            tokens.push_back(token);  // add it to tokens
            token.clear();            // reset token. Next number can resume.
        } else {
            token += c;  // Append number
        }
    }

    // Handle last token
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}
