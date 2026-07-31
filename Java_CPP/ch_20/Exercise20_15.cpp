#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <exception>
#include <stdexcept>

class Card24Solver {
private:
    static bool equals24(double val) {
        return std::abs(val - 24.0) < 1e-4;
    }

    static double operate(double a, double b, int op) {
        if (op == 0) return a + b;
        if (op == 1) return a - b;
        if (op == 2) return a * b;
        if (op == 3) {
            if (std::abs(b) < 1e-7) return -999999.0; // Avoid divide-by-zero crash
            return a / b;
        }
        return 0;
    }

    static std::string get_op_str(int op) {
        switch (op) {
            case 0: return " + ";
            case 1: return " - ";
            case 2: return " * ";
            case 3: return " / ";
            default: return "";
        }
    }

    static std::string build_expr(int pattern, const std::vector<int>& c, int x, int y, int z) {
        std::string a = std::to_string(c[0]);
        std::string b = std::to_string(c[1]);
        std::string d = std::to_string(c[2]);
        std::string e = std::to_string(c[3]);

        switch (pattern) {
            case 1: return a + get_op_str(z) + "(" + b + get_op_str(y) + "(" + d + get_op_str(x) + e + "))";
            case 2: return a + get_op_str(z) + "((" + b + get_op_str(x) + d + ")" + get_op_str(y) + e + ")";
            case 3: return "(" + a + get_op_str(x) + b + ")" + get_op_str(z) + "(" + d + get_op_str(y) + e + ")";
            case 4: return "((" + a + get_op_str(x) + b + ")" + get_op_str(y) + d + ")" + get_op_str(z) + e;
            case 5: return "(" + a + get_op_str(y) + "(" + b + get_op_str(x) + d + "))" + get_op_str(z) + e;
            default: return "";
        }
    }

public:
    static std::string find_solution(const std::vector<int>& cards) {
        if (cards.size() != 4) {
            throw std::invalid_argument("Exactly 4 card values required.");
        }
        std::vector<int> p = cards;
        std::sort(p.begin(), p.end());
        do {
            for (int x = 0; x < 4; ++x) {
                for (int y = 0; y < 4; ++y) {
                    for (int z = 0; z < 4; ++z) {
                        if (equals24(operate(p[0], operate(p[1], operate(p[2], p[3], x), y), z)))
                            return build_expr(1, p, x, y, z);
                        if (equals24(operate(p[0], operate(operate(p[1], p[2], x), p[3], y), z)))
                            return build_expr(2, p, x, y, z);
                        if (equals24(operate(operate(p[0], p[1], x), operate(p[2], p[3], y), z)))
                            return build_expr(3, p, x, y, z);
                        if (equals24(operate(operate(operate(p[0], p[1], x), p[2], y), p[3], z)))
                            return build_expr(4, p, x, y, z);
                        if (equals24(operate(operate(p[0], operate(p[1], p[2], x), y), p[3], z)))
                            return build_expr(5, p, x, y, z);
                    }
                }
            }
        } while (std::next_permutation(p.begin(), p.end()));

        return "No Solution";
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::vector<int> cards = {4, 1, 8, 7};
        std::cout << "Finding solution for cards: 4, 1, 8, 7\n";
        
        std::string solution = Card24Solver::find_solution(cards);
        std::cout << "Solution: " << solution << '\n';
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