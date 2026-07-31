#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <cctype>

class ExpressionEvaluator {
private:
    static int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/' || op == '%') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    static void process_operator(std::stack<long long>& operand_stack, std::stack<char>& operator_stack) {
        if (operand_stack.size() < 2 || operator_stack.empty()) {
            throw std::invalid_argument("Invalid expression structure.");
        }

        char op = operator_stack.top(); operator_stack.pop();
        long long op1 = operand_stack.top(); operand_stack.pop();
        long long op2 = operand_stack.top(); operand_stack.pop();

        if (op == '+') operand_stack.push(op2 + op1);
        else if (op == '-') operand_stack.push(op2 - op1);
        else if (op == '*') operand_stack.push(op2 * op1);
        else if (op == '/') {
            if (op1 == 0) throw std::domain_error("Division by zero");
            operand_stack.push(op2 / op1);
        }
        else if (op == '%') {
            if (op1 == 0) throw std::domain_error("Modulus by zero");
            operand_stack.push(op2 % op1);
        }
        else if (op == '^') {
            operand_stack.push(static_cast<long long>(std::pow(op2, op1)));
        }
    }

public:
    static std::string insert_blanks(const std::string& s) {
        std::string result;
        for (char c : s) {
            if (c == '(' || c == ')' || c == '+' || c == '-' ||
                c == '*' || c == '/' || c == '^' || c == '%') {
                result += " ";
                result += c;
                result += " ";
            } else {
                result += c;
            }
        }
        return result;
    }

    static long long evaluate(const std::string& expression) {
        std::stack<long long> operand_stack;
        std::stack<char> operator_stack;

        std::string formatted = insert_blanks(expression);
        std::istringstream tokens(formatted);
        std::string token;

        while (tokens >> token) {
            if (token.empty()) continue;

            if (std::isdigit(token[0])) {
                operand_stack.push(std::stoll(token));
            } else if (token[0] == '(') {
                operator_stack.push('(');
            } else if (token[0] == ')') {
                while (!operator_stack.empty() && operator_stack.top() != '(') {
                    process_operator(operand_stack, operator_stack);
                }
                if (!operator_stack.empty()) operator_stack.pop();
            } else if (token[0] == '^' || token[0] == '+' || token[0] == '-' ||
                       token[0] == '*' || token[0] == '/' || token[0] == '%') {
                char current_op = token[0];
                while (!operator_stack.empty() && operator_stack.top() != '(' &&
                       (precedence(operator_stack.top()) > precedence(current_op) ||
                       (precedence(operator_stack.top()) == precedence(current_op) && current_op != '^'))) {
                    process_operator(operand_stack, operator_stack);
                }
                operator_stack.push(current_op);
            }
        }

        while (!operator_stack.empty()) {
            process_operator(operand_stack, operator_stack);
        }

        if (operand_stack.empty()) throw std::invalid_argument("Empty expression.");
        return operand_stack.top();
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter an expression: ";
        std::string expression;
        std::getline(std::cin, expression);

        long long result = ExpressionEvaluator::evaluate(expression);
        std::cout << expression << " = " << result << '\n';
    }
    catch (const std::exception& ex) {
        std::cerr << "Evaluation Error: " << ex.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during evaluation.\n";
        return 2;
    }

    return 0;
}