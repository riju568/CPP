#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 10.26 (Calculator) Revise Listing 7.9, Calculator.java, to accept an expression as
 * a string in which the operands and operator are separated by zero or more
 * spaces. For example, 3+4 and 3 + 4 are acceptable expressions.
 */
int main(int argc, char* argv[])
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        if (argc < 2)
        {
            std::cout << "Usage: ./Exercise10_26 <expression>\n";
            std::cout << "Examples: ./Exercise10_26 \"3+4\" or ./Exercise10_26 3 + 4\n";
            return EXIT_SUCCESS;
        }
        std::string expression;
        for (int i = 1; i < argc; ++i)
        {
            expression += argv[i];
        }
        expression.erase(
            std::remove_if(expression.begin(), expression.end(), ::isspace),
            expression.end()
        );
        std::regex expr_regex(R"(^(-?\d+)([\+\-\*\/\.])(-?\d+)$)");
        std::smatch match;
        if (!std::regex_match(expression, match, expr_regex))
        {
            std::cerr << "Invalid expression format: " << expression << '\n';
            return EXIT_FAILURE;
        }
        int op1 = std::stoi(match[1].str());
        char op = match[2].str()[0];
        int op2 = std::stoi(match[3].str());
        int result = 0;
        switch (op)
        {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
            case '.':
                result = op1 * op2;
                op = '*'; 
                break;
            case '/':
                if (op2 == 0)
                {
                    std::cerr << "Error: Division by zero.\n";
                    return EXIT_FAILURE;
                }
                result = op1 / op2;
                break;
            default:
                std::cerr << "Unknown operator.\n";
                return EXIT_FAILURE;
        }
        std::cout << op1 << " " << op << " " << op2 << " = " << result << '\n';
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}