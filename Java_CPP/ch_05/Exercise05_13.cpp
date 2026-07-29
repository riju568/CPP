#include <iostream>
#include <exception>

/**
 * 5.13 (Find the largest n such that n^3 < 12,000) Uses a while loop to find 
 * the largest integer n such that n^3 is less than 12,000 with zero heap 
 * allocations and exception handling.
 */

int main() {
    std::ios_base::sync_with_stdio(true);
    constexpr int THRESHOLD = 12000;
    try {
        int n = 1;
        while ((n + 1) * (n + 1) * (n + 1) < THRESHOLD) {
            ++n;
        }
        int cube = n * n * n;
        int nextCube = (n + 1) * (n + 1) * (n + 1);
        std::cout << "The largest integer n where n^3 < 12,000 is " << n << ".\n";
        std::cout << "Because " << n << "^3 = " << cube << " (< 12,000)\n";
        std::cout << "And " << (n + 1) << "^3 = " << nextCube << " (>= 12,000)\n";
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}