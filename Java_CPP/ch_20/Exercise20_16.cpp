#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <exception>
#include <stdexcept>

class ExpressionConverter {
private:
    static int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/' || op == '%') return 2;
        return 0;
    }

    static bool is_operator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
    }

public:
    static std::string infix_to_postfix(const std::string& expression) {
        std::string result;
        std::stack<char> operator_stack;
        std::string formatted;
        for (char c : expression) {
            if (is_operator(c) || c == '(' || c == ')') {
                formatted += ' ';
                formatted += c;
                formatted += ' ';
            } else {
                formatted += c;
            }
        }

        std::istringstream tokens(formatted);
        std::string token;

        while (tokens >> token) {
            if (token.empty()) continue;

            if (std::isalnum(token[0])) {
                result += token + " ";
            } else if (token[0] == '(') {
                operator_stack.push('(');
            } else if (token[0] == ')') {
                while (!operator_stack.empty() && operator_stack.top() != '(') {
                    result += operator_stack.top();
                    result += " ";
                    operator_stack.pop();
                }
                if (operator_stack.empty()) {
                    throw std::invalid_argument("Mismatched parentheses detected.");
                }
                operator_stack.pop(); // Pop '('
            } else if (is_operator(token[0])) {
                char current_op = token[0];
                while (!operator_stack.empty() && 
                       precedence(operator_stack.top()) >= precedence(current_op)) {
                    result += operator_stack.top();
                    result += " ";
                    operator_stack.pop();
                }
                operator_stack.push(current_op);
            }
        }

        while (!operator_stack.empty()) {
            if (operator_stack.top() == '(' || operator_stack.top() == ')') {
                throw std::invalid_argument("Mismatched parentheses detected.");
            }
            result += operator_stack.top();
            result += " ";
            operator_stack.pop();
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::string expression;
        if (argc > 1) {
            for (int i = 1; i < argc; ++i) {
                expression += argv[i];
            }
        } else {
            std::cout << "Enter an infix expression (e.g. '(1 + 2) * 3'): ";
            std::getline(std::cin, expression);
        }

        std::string postfix = ExpressionConverter::infix_to_postfix(expression);
        std::cout << "Postfix expression: " << postfix << '\n';
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