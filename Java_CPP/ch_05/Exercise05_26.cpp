#include <iostream>
#include <iomanip>
#include <exception>

/**
 * 5.26 (Compute e) Approximates e using the series:
 * e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + ... + 1/i!
 * Displays the calculated value of e for i from 10,000 to 100,000 in steps of 10,000.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    try {
        for (int targetI = 10000; targetI <= 100000; targetI += 10000) {
            double e = 1.0;
            double currentItem = 1.0;

            for (int i = 1; i <= targetI; ++i) {
                currentItem /= i;
                e += currentItem;
            }
            std::cout << std::fixed << std::setprecision(15);
            std::cout << "e is " << e << " when i is " << targetI << '\n';
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