#include <iostream>
#include <exception>
/**
 * 5.12 (Find the smallest n such that n^2 > 12,000) Uses a while loop to find 
 * the smallest integer n such that n^2 is greater than 12,000 with zero heap 
 * allocations and exception handling.
 */

int main() {

    std::ios_base::sync_with_stdio(true);
    constexpr int THRESHOLD = 12000;
    try {
        int n = 1;
        while (n * n <= THRESHOLD) {
            ++n;
        }
        int square = n * n;
        int previousSquare = (n - 1) * (n - 1);
        std::cout << "The smallest integer n where n^2 > 12,000 is " << n << ".\n";
        std::cout << "Because " << n << "^2 = " << square << " (> 12,000)\n";
        std::cout << "And " << (n - 1) << "^2 = " << previousSquare << " (<= 12,000)\n";
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }
    return 0;
}