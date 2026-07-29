#include <iostream>
#include <iomanip>
#include <exception>

/**
 * 5.6 (Conversion from miles to kilometers) Displays two conversion tables 
 * side by side: Miles to Kilometers and Kilometers to Miles.
 */
int main() {

    std::ios_base::sync_with_stdio(true);
    constexpr double KILOMETERS_PER_MILE = 1.609;
    try {
        std::cout << std::left << std::setw(11) << "Miles"
                  << std::right << std::setw(10) << "Kilometers"
                  << "   |   "
                  << std::left << std::setw(15) << "Kilometers"
                  << std::setw(10) << "Miles" << '\n';
        for (int i = 1, j = 20; i <= 10 && j <= 65; ++i, j += 5) {
            double milesToKm = i * KILOMETERS_PER_MILE;
            double kmToMiles = j / KILOMETERS_PER_MILE;

            std::cout << std::left << std::setw(11) << i
                      << std::right << std::setw(10) << std::fixed << std::setprecision(3) << milesToKm
                      << "   |   "
                      << std::left << std::setw(15) << j
                      << std::setw(10) << kmToMiles << '\n';
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred during program execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during program execution.\n";
        return 1;
    }

    return 0;
}