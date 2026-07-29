#include <iostream>
#include <iomanip>
#include <exception>

/**
 * 5.7 (Financial application: compute future tuition) Computes tuition in ten years 
 * and the total cost of four years' worth of tuition after the tenth year.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    constexpr double RATE = 0.05; // 5% annual increase rate
    try {
        double tuition = 10000.0; // Initial tuition
        double tuitionInTenYears = 0.0;
        double totalFourYearCost = 0.0;

        for (int year = 1; year <= 14; ++year) {
            tuition += tuition * RATE;

            if (year == 10) {
                tuitionInTenYears = tuition;
            }
            if (year > 10) {
                totalFourYearCost += tuition;
            }
        }
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Tuition in ten years: $" << tuitionInTenYears << '\n';
        std::cout << "Total cost of four years' tuition after the tenth year: $" << totalFourYearCost << '\n';
    } catch (const std::exception& e) {
        std::cerr << "An error occurred during program execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during program execution.\n";
        return 1;
    }

    return 0;
}