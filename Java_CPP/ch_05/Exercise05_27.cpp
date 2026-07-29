#include <iostream>
#include <exception>

/**
 * 5.27 (Display leap years) Displays all leap years from 2001 to 2100,
 * formatted 10 per line with space separation.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    constexpr int START_YEAR = 2001;
    constexpr int END_YEAR = 2100;
    constexpr int YEARS_PER_LINE = 10;
    try {
        int count = 0;
        for (int year = START_YEAR; year <= END_YEAR; ++year) {
            if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
                std::cout << year << ' ';
                ++count;

                if (count % YEARS_PER_LINE == 0) {
                    std::cout << '\n';
                }
            }
        }
        if (count % YEARS_PER_LINE != 0) {
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