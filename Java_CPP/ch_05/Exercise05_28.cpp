#include <iostream>
#include <exception>

/**
 * 5.28 (Display leap years with total count) Displays all leap years 
 * from 101 to 2100, ten per line, and prints the total count.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    constexpr int START_YEAR = 101;
    constexpr int END_YEAR = 2100;
    constexpr int YEARS_PER_LINE = 10;
    try {
        std::cout << "Leap Years between 101 and 2100:\n\n";

        int total = 0;
        int lineIdx = 0;

        for (int year = START_YEAR; year <= END_YEAR; ++year) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                std::cout << year << ' ';
                ++lineIdx;
                ++total;

                if (lineIdx == YEARS_PER_LINE) {
                    std::cout << '\n';
                    lineIdx = 0;
                }
            }
        }
        if (lineIdx != 0) {
            std::cout << '\n';
        }
        std::cout << "\nTotal leap years is " << total << '\n';
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }
    return 0;
}