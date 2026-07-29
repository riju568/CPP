#include <iostream>
#include <iomanip>
#include <exception>

/**
 * 5.25 (Compute pi)
 * Approximates pi using the Leibniz series:
 * pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ... + (-1)^(i+1)/(2i - 1))
 * Displays the value of pi for i = 10000, 20000, ..., 100000.
 */
int main() {

    std::ios_base::sync_with_stdio(true);
    try {
        double sum = 0.0;
        for (int i = 1; i <= 100000; ++i) {
            double term = 1.0 / (2.0 * i - 1.0);
            if (i % 2 == 1) {
                sum += term;
            } else {
                sum -= term;
            }
            if (i % 10000 == 0) {
                double pi = 4.0 * sum;
                std::cout << "For i = " << std::left << std::setw(6) << i
                          << " -> PI = " << std::fixed << std::setprecision(11) << pi << '\n';
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}