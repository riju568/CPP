#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <exception>
#include <stdexcept>

class GroupingSymbolChecker {
private:
    static bool is_opening(char c) {
        return c == '(' || c == '{' || c == '[';
    }

    static bool is_closing(char c) {
        return c == ')' || c == '}' || c == ']';
    }

    static bool is_matching_pair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

public:
    static bool check_file(const std::string& file_path) {
        std::ifstream file(file_path);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + file_path);
        }

        std::stack<char> symbol_stack;
        char ch;

        while (file.get(ch)) {
            if (is_opening(ch)) {
                symbol_stack.push(ch);
            } else if (is_closing(ch)) {
                if (symbol_stack.empty()) {
                    return false; // Unmatched closing symbol
                }
                char top_symbol = symbol_stack.top();
                symbol_stack.pop();
                if (!is_matching_pair(top_symbol, ch)) {
                    return false;                }
            }
        }
        return symbol_stack.empty();
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::string file_path;
        if (argc > 1) {
            file_path = argv[1];
        } else {
            std::cout << "Usage: Exercise20_11 <filename>\n";
            std::cout << "Enter source file path: ";
            if (!(std::cin >> file_path)) {
                std::cerr << "Error: Invalid file path input.\n";
                return 3;
            }
        }

        bool is_valid = GroupingSymbolChecker::check_file(file_path);
        if (is_valid) {
            std::cout << "The source file " << file_path << " has correct pairs of grouping symbols.\n";
        } else {
            std::cout << "The source file " << file_path << " has INCORRECT pairs of grouping symbols.\n";
        }
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