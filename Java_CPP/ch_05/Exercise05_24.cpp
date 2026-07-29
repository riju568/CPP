#include <iostream>
#include <iomanip>
#include <exception>

/**
 * 5.24 (Sum a series)
 * Computes the sum of the series: 1/3 + 3/5 + 5/7 + ... + 97/99
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    try {
        double totalSum = 0.0;
        for (int numerator = 1; numerator <= 97; numerator += 2) {
            int denominator = numerator + 2;
            totalSum += static_cast<double>(numerator) / denominator;
        }
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "The sum of the series is: " << totalSum << '\n';
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}