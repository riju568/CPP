#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <exception>

class FractionalSeriesCalculator {
private:
    static double calculateSeries(double sum, int numerator, int target) {
        if (numerator > target) {
            return sum;
        }
        sum += static_cast<double>(numerator) / (2.0 * numerator + 1.0);
        return calculateSeries(sum, numerator + 1, target);
    }

public:
    static double m(int target) {
        if (target < 1) {
            throw std::invalid_argument("Target term index must be greater than or equal to 1.");
        }
        return calculateSeries(0.0, 1, target);
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        for (int i = 1; i <= 10; ++i) {
            std::cout << "m(" << i << ") = " 
                      << std::fixed << std::setprecision(4) 
                      << FractionalSeriesCalculator::m(i) << '\n';
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}