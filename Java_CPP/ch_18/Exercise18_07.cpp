#include <iostream>
#include <stdexcept>
#include <exception>

class FibonacciTracker {
private:
    static unsigned long long fibCalls;

public:
    static void resetCalls() noexcept {
        fibCalls = 0;
    }

    [[nodiscard]] static unsigned long long getCalls() noexcept {
        return fibCalls;
    }

    static long long fib(long long n) {
        ++fibCalls;
        if (n <= 0) return 0;
        if (n == 1) return 1;

        return fib(n - 1) + fib(n - 2);
    }
};

unsigned long long FibonacciTracker::fibCalls = 0;

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter an index in the Fibonacci sequence: ";
        long long targetIndex = 0;

        if (!(std::cin >> targetIndex)) {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        if (targetIndex < 0) {
            throw std::invalid_argument("Fibonacci index cannot be negative.");
        }

        FibonacciTracker::resetCalls();
        long long result = FibonacciTracker::fib(targetIndex);

        std::cout << "Fibonacci num at " << targetIndex << " is " << result << '\n';
        std::cout << "Fib method called " << FibonacciTracker::getCalls() << " times.\n";
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