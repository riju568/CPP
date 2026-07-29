#include <iostream>
#include <iomanip>
#include <exception>

/**
 * 5.19 (Display numbers in a pyramid pattern)
 * Uses nested loops to print a formatted pyramid where each row 
 * displays powers of 2 increasing to a peak and decreasing back to 1.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    try {
        int previousMax = 0;
        int spacesCount = 7;
        for (int rowMax = 1; rowMax <= 128; rowMax *= 2) {
            for (int s = 0; s < spacesCount; ++s) {
                std::cout << "    ";
            }
            for (int j = 1; j <= rowMax; j *= 2) {
                std::cout << std::setw(4) << j;
            }
            for (int x = previousMax; x > 0; x /= 2) {
                std::cout << std::setw(4) << x;
            }

            // 4. State updates for subsequent row
            previousMax = rowMax;
            --spacesCount;
            std::cout << '\n';
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