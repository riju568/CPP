#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>
#include <exception>
#include <stdexcept>

class PostfixEvaluator {
private:
    static bool is_operator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/" || token == "%";
    }

    static void process_operator(const std::string& op, std::stack<double>& operand_stack) {
        if (operand_stack.size() < 2) {
            throw std::invalid_argument("Insufficient operands for operator: " + op);
        }
        double op1 = operand_stack.top(); operand_stack.pop();
        double op2 = operand_stack.top(); operand_stack.pop();

        if (op == "+") operand_stack.push(op2 + op1);
        else if (op == "-") operand_stack.push(op2 - op1);
        else if (op == "*") operand_stack.push(op2 * op1);
        else if (op == "/") {
            if (std::abs(op1) < 1e-7) throw std::runtime_error("Division by zero.");
            operand_stack.push(op2 / op1);
        }
        else if (op == "%") {
            if (std::abs(op1) < 1e-7) throw std::runtime_error("Modulo by zero.");
            operand_stack.push(std::fmod(op2, op1));
        }
    }

public:
    static double evaluate(const std::string& expression) {
        std::stack<double> operand_stack;
        std::istringstream tokens(expression);
        std::string token;

        while (tokens >> token) {
            if (token.empty()) continue;

            if (is_operator(token)) {
                process_operator(token, operand_stack);
            } else {
                try {
                    double val = std::stod(token);
                    operand_stack.push(val);
                } catch (...) {
                    throw std::invalid_argument("Invalid token in expression: " + token);
                }
            }
        }

        if (operand_stack.size() != 1) {
            throw std::invalid_argument("Expression formed incorrectly.");
        }

        return operand_stack.top();
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::string expression;
        if (argc > 1) {
            for (int i = 1; i < argc; ++i) {
                expression += std::string(argv[i]) + " ";
            }
        } else {
            std::cout << "Enter a postfix expression (e.g., '1 2 + 3 *'): ";
            std::getline(std::cin, expression);
        }

        if (expression.empty()) {
            std::cerr << "Error: Expression cannot be empty.\n";
            return 3;
        }

        double result = PostfixEvaluator::evaluate(expression);
        std::cout << "Result: " << result << '\n';
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}