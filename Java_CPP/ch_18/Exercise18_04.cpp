#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <exception>


class SeriesCalculator {
private:
    static double calculateSeries(double sum, int denominator, int target) {
        if (denominator > target) {
            return sum;
        }
        sum += 1.0 / denominator;
        return calculateSeries(sum, denominator + 1, target);
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
                      << SeriesCalculator::m(i) << '\n';
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