#include <iostream>
#include <stdexcept>
#include <limits>
#include <exception>


class FactorialCalculator {
private:
    static unsigned long long factorialHelper(unsigned long long n, unsigned long long current, unsigned long long result) {
        if (current <= n) {
            // Check for potential multiplication overflow
            if (result > 0 && current > std::numeric_limits<unsigned long long>::max() / result) {
                throw std::overflow_error("Factorial calculation resulted in integer overflow.");
            }
            return factorialHelper(n, current + 1, result * current);
        }
        return result;
    }

public:
    static unsigned long long findFactorial(unsigned long long n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return factorialHelper(n, 1, 1);
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter an integer to find its factorial: ";
        long long inputVal = 0;

        if (!(std::cin >> inputVal)) {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        if (inputVal < 0) {
            throw std::invalid_argument("Factorial is not defined for negative numbers.");
        }

        auto numToFactor = static_cast<unsigned long long>(inputVal);
        unsigned long long result = FactorialCalculator::findFactorial(numToFactor);

        std::cout << numToFactor << "! is " << result << '\n';
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