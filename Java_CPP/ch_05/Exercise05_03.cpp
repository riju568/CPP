#include <iostream>
#include <iomanip>
#include <exception>

/**
 * 5.3 (Conversion from kilograms to pounds) Displays a conversion table 
 * from kilograms to pounds for odd numbers 1 through 199.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    constexpr double POUNDS_PER_KILOGRAM = 2.2;
    try {
        std::cout << std::left << std::setw(15) << "Kilograms" 
                  << std::right << std::setw(6) << "Pounds" << '\n';
        for (int i = 1; i <= 199; i += 2) {
            std::cout << std::left << std::setw(15) << i 
                      << std::right << std::setw(6) << std::fixed 
                      << std::setprecision(1) << (i * POUNDS_PER_KILOGRAM) << '\n';
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