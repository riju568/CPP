#include <iostream>
#include <iomanip>
#include <exception>

/**
 * 5.4 (Conversion from miles to kilometers) Displays a conversion table 
 * from miles to kilometers for values 1 through 10 with proper precision 
 * and runtime exception safety.
 */


int main() {
    std::ios_base::sync_with_stdio(true);
    constexpr double KILOMETERS_PER_MILE = 1.609;
    try {
        std::cout << std::left << std::setw(10) << "Miles" 
                  << std::right << std::setw(10) << "Kilometers" << '\n';

        for (int i = 1; i <= 10; ++i) {
            std::cout << std::left << std::setw(10) << i 
                      << std::right << std::setw(10) << std::fixed 
                      << std::setprecision(3) << (i * KILOMETERS_PER_MILE) << '\n';
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