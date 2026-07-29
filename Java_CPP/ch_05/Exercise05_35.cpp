#include <iostream>
#include <cmath>
#include <exception>
/**
 * 5.35 (Summation) Computes the mathematical summation:
 * 1 / (1 + sqrt(2)) + 1 / (sqrt(2) + sqrt(3)) + ... + 1 / (sqrt(624) + sqrt(625))
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    try {
        double result = 0.0;
        for (int i = 1; i <= 624; ++i) {
            result += 1.0 / (std::sqrt(i) + std::sqrt(i + 1));
        }
        std::cout << "Summation result: " << result << '\n';
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}