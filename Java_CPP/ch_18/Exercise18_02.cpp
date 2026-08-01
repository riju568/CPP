#include <iostream>
#include <stdexcept>
#include <exception>

long long fib(int idx) {
    if (idx < 0) {
        throw std::invalid_argument("Fibonacci sequence index cannot be negative.");
    }
    if (idx == 0) return 0;
    if (idx == 1) return 1;

    long long f0 = 0;
    long long f1 = 1;
    long long currentFib = 0;

    for (int i = 2; i <= idx; ++i) {
        currentFib = f0 + f1;
        f0 = f1;
        f1 = currentFib;
    }

    return currentFib;
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter an index in the Fibonacci sequence: ";
        int idx = 0;

        if (!(std::cin >> idx)) {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        std::cout << "Fibonacci num at " << idx << " is " << fib(idx) << '\n';
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