#include <math.h>

#include <ios>
#include <iostream>
#include <string>

#include "lexer.h"
#include "parser.h"
#include "tokenizer.h"
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif

bool is_whole_number(double x) { return x == std::floor(x); }

int main(int argc, char **argv) {
    // Clear the screen
    if (system("CLS")) system("clear");
    std::cout << "Math Expression Evaluator"
              << "\n";
    std::cout << "Enter quit or exit or q to close the program"
              << "\n";

    std::string expression;
    while (true) {
        // prompt for math expression
        std::cout << ">> ";
        std::getline(std::cin, expression);

        // check for exit commands
        if (expression == "exit" || expression == "quit" || expression == "q") break;

        // tkenize the expression
        Tokenizer tokenizer;
        auto tokens = tokenizer.tokenize(expression);

        // Lex the tokens
        Lexer lexer;
        auto lexedTokens = lexer.lex(tokens);

        // Parse the tokens
        Parser parser;
        double result = parser.parse(lexedTokens);
        if (!is_whole_number(result)) {
            std::cout.precision(10);
            std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        }

        // Print the answer
        std::cout << result << std::endl;
    }

    return 0;
}
