#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <cmath>

class Point24Solver {
private:
    static bool is_operator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    static int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    static void apply_top_operator(std::stack<double>& values, std::stack<char>& ops) {
        if (values.size() < 2 || ops.empty()) {
            throw std::invalid_argument("Malformed expression.");
        }

        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();

        if (op == '+') values.push(val1 + val2);
        else if (op == '-') values.push(val1 - val2);
        else if (op == '*') values.push(val1 * val2);
        else if (op == '/') {
            if (std::abs(val2) < 1e-7) {
                throw std::runtime_error("Division by zero");
            }
            values.push(val1 / val2);
        }
    }

public:
    static double evaluate_expression(const std::string& exp) {
        std::stack<double> values;
        std::stack<char> ops;
        std::istringstream stream(exp);
        std::string token;

        while (stream >> token) {
            if (token.empty()) continue;

            if (std::isdigit(token[0])) {
                values.push(std::stod(token));
            } else if (token[0] == '(') {
                ops.push('(');
            } else if (token[0] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    apply_top_operator(values, ops);
                }
                if (!ops.empty()) ops.pop(); // Remove '('
            } else if (is_operator(token[0])) {
                while (!ops.empty() && precedence(ops.top()) >= precedence(token[0])) {
                    apply_top_operator(values, ops);
                }
                ops.push(token[0]);
            }
        }

        while (!ops.empty()) {
            apply_top_operator(values, ops);
        }

        return values.empty() ? 0.0 : values.top();
    }

    static long long calculate_combinations(int r, int n) {
        long long permutations = 1;
        long long slots = 1;
        int sample_factor = n;
        int slots_factor = r;

        while (slots_factor >= 1) {
            permutations *= sample_factor;
            slots *= slots_factor;
            sample_factor--;
            slots_factor--;
        }
        return permutations / slots;
    }

    static long long find_combinations_with_target(double target) {
        long long count = 0;
        const std::vector<std::string> operators = {"+", "-", "*", "/"};

        for (int h = 1; h <= 13; ++h) {
            for (int cl = 1; cl <= 13; ++cl) {
                for (int s = 1; s <= 13; ++s) {
                    for (int d = 1; d <= 13; ++d) {
                        for (const auto& op1 : operators) {
                            for (const auto& op2 : operators) {
                                for (const auto& op3 : operators) {
                                    std::ostringstream ss;
                                    ss << h << " " << op1 << " " << cl << " " << op2 << " "
                                       << s << " " << op3 << " " << d;
                                    try {
                                        double result = evaluate_expression(ss.str());
                                        if (std::abs(result - target) < 1e-6) {
                                            count++;
                                        }
                                    } catch (...) {
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        long long total = Point24Solver::calculate_combinations(4, 52);
        std::cout << "Number of possible picks of four cards from a 52-card deck:\n" << total << '\n';

        long long solutions = Point24Solver::find_combinations_with_target(24.0);
        std::cout << "Number of picks with a 24-point solution:\n" << solutions << '\n';

        std::cout << "Success ratio:\n" << static_cast<double>(solutions) / total << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard Exception: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}