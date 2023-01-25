#include "parser.h"

#include <cmath>
#include <cstdlib>
#include <map>

// pops last 2 numbers from the numbers and evaluates them based on the operator token
// on top of the operatorStack.
void evaluate(std::stack<Token>& operators, std::stack<double>& numbers) {
    Token op = operators.top();
    operators.pop();

    double value2 = numbers.top();
    numbers.pop();
    double value1 = numbers.top();
    numbers.pop();

    if (op.value == "+") {
        numbers.push(value1 + value2);
    } else if (op.value == "-") {
        numbers.push(value1 - value2);
    } else if (op.value == "*") {
        numbers.push(value1 * value2);
    } else if (op.value == "/") {
        numbers.push(value1 / value2);
    } else if (op.value == "^") {
        numbers.push(std::pow(value1, value2));
    } else if (op.value == "%") {
        numbers.push((int)value1 % (int)value2);
    }
}

double Parser::parse(std::vector<Token> tokens) {
    std::stack<double> numbers;
    std::stack<Token> operators;
    std::map<std::string, int> precedence{{"+", 1}, {"-", 1}, {"%", 1},
                                          {"^", 3}, {"*", 2}, {"/", 2}};

    for (const auto& token : tokens) {
        if (token.type == TokenType::INTEGER) {
            numbers.push(std::stold(token.value));
        } else if (token.type == TokenType::OPERATOR) {
            while (!operators.empty() && operators.top().type == TokenType::OPERATOR &&
                   (precedence[operators.top().value] >= precedence[token.value])) {
                evaluate(operators, numbers);
            }
            operators.push(token);
        } else if (token.type == TokenType::LEFT_PAREN) {
            operators.push(token);
        } else if (token.type == TokenType::RIGHT_PAREN) {
            while (operators.top().type != TokenType::LEFT_PAREN) {
                evaluate(operators, numbers);
            }
            operators.pop();
        }
    }

    while (!operators.empty()) {
        evaluate(operators, numbers);
    }

    return numbers.top();
}
