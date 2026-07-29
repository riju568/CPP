#include <iostream>
#include <exception>
#include <cstdlib>

/**
 * *5.43 (Math: combinations) Write a program that displays all possible combinations
 * for picking two numbers from integers 1 to 7. Also display the total number of
 * all combinations.
 */
int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        int count = 0;
        for (int n = 1; n < 7; ++n) {
            for (int j = n + 1; j <= 7; ++j) {
                std::cout << n << " " << j << '\n';
                ++count;
            }
        }
        std::cout << "Total combinations -> " << count << '\n';
        return EXIT_SUCCESS;
    } 
    catch (const std::exception& e) {
        std::cerr << "Execution error (standard exception): " << e.what() << '\n';
        return EXIT_FAILURE;
    } 
    catch (...) {
        std::cerr << "An unexpected unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}