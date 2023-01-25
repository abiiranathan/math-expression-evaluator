#include "parser.h"

#include <cmath>
#include <cstdlib>
#include <map>

// pops last 2 numbers from the numberStack and evaluates them based on the operator token
// on top of the operatorStack.
void calculate(std::stack<Token>& operatorStack, std::stack<double>& numberStack) {
    Token operatorToken = operatorStack.top();
    operatorStack.pop();

    double value2 = numberStack.top();
    numberStack.pop();
    double value1 = numberStack.top();
    numberStack.pop();

    if (operatorToken.value == "+") {
        numberStack.push(value1 + value2);
    } else if (operatorToken.value == "-") {
        numberStack.push(value1 - value2);
    } else if (operatorToken.value == "*") {
        numberStack.push(value1 * value2);
    } else if (operatorToken.value == "/") {
        numberStack.push(value1 / value2);
    } else if (operatorToken.value == "^") {
        numberStack.push(std::pow(value1, value2));
    } else if (operatorToken.value == "%") {
        numberStack.push((int)value1 % (int)value2);
    }
}

double Parser::parse(std::vector<Token> tokens) {
    std::stack<double> numberStack;
    std::stack<Token> operatorStack;

    std::map<std::string, int> precedence{{"+", 1}, {"-", 1}, {"%", 1},
                                          {"^", 3}, {"*", 2}, {"/", 2}};

    for (const auto& token : tokens) {
        if (token.type == TokenType::INTEGER) {
            numberStack.push(std::stold(token.value));
        } else if (token.type == TokenType::OPERATOR) {
            while (!operatorStack.empty() && operatorStack.top().type == TokenType::OPERATOR &&
                   (precedence[operatorStack.top().value] >= precedence[token.value])) {
                calculate(operatorStack, numberStack);
            }
            operatorStack.push(token);
        } else if (token.type == TokenType::LEFT_PAREN) {
            operatorStack.push(token);
        } else if (token.type == TokenType::RIGHT_PAREN) {
            while (operatorStack.top().type != TokenType::LEFT_PAREN) {
                calculate(operatorStack, numberStack);
            }
            operatorStack.pop();
        }
    }

    while (!operatorStack.empty()) {
        calculate(operatorStack, numberStack);
    }

    return numberStack.top();
}
