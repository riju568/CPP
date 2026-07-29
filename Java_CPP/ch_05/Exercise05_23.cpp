#include <iostream>
#include <iomanip>
#include <exception>

/**
 * 5.23 (Demonstrate cancellation errors)
 * Demonstrates floating-point precision loss and cancellation errors by 
 * comparing the harmonic series sum computed from left-to-right vs. 
 * right-to-left for n = 50,000.
 */
int main() {

    std::ios_base::sync_with_stdio(true);
    constexpr int N = 50000;
    try {
        double sumLeftToRight = 0.0;
        for (int i = 1; i <= N; ++i) {
            sumLeftToRight += 1.0 / i;
        }
        double sumRightToLeft = 0.0;
        for (int i = N; i >= 1; --i) {
            sumRightToLeft += 1.0 / i;
        }
        std::cout << std::setprecision(15);
        std::cout << "Result computing from left to right:  " << sumLeftToRight << '\n';
        std::cout << "Result computing from right to left: " << sumRightToLeft << '\n';
        std::cout << "Difference: " << (sumRightToLeft - sumLeftToRight) << '\n';

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}