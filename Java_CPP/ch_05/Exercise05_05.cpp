#include <iostream>
#include <iomanip>
#include <exception>

/**
 * 5.5 (Conversion from kilograms to pounds and pounds to kilograms) 
 * Displays two conversion tables side-by-side with proper formatting, 
 * zero heap allocations inside the loop, and exception safety.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    constexpr double POUNDS_PER_KILOGRAM = 2.2;
    try {
        std::cout << std::left 
                  << std::setw(10) << "Kilograms" 
                  << std::setw(10) << "Pounds" 
                  << " | " 
                  << std::setw(10) << "Pounds" 
                  << std::setw(10) << "Kilograms" << '\n';
        for (int kg = 1, lb = 20; kg <= 199; kg += 2, lb += 5) {
            double kgToLb = kg * POUNDS_PER_KILOGRAM;
            double lbToKg = lb / POUNDS_PER_KILOGRAM;
            std::cout << std::left << std::fixed
                      << std::setw(10) << kg 
                      << std::setw(10) << std::setprecision(1) << kgToLb 
                      << " | " 
                      << std::setw(10) << lb 
                      << std::setw(10) << std::setprecision(2) << lbToKg 
                      << '\n';
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