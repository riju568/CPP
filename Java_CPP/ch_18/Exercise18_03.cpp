#include <iostream>
#include <cmath>
#include <stdexcept>
#include <exception>


int gcd(int m, int n) {
    m = std::abs(m);
    n = std::abs(n);

    if (n == 0) {
        if (m == 0) {
            throw std::invalid_argument("GCD(0, 0) is undefined.");
        }
        return m;
    }

    if (m % n == 0) {
        return n;
    }

    return gcd(n, m % n);
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter two integers: ";
        int m = 0;
        int n = 0;

        if (!(std::cin >> m >> n)) {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        std::cout << "The GCD of " << m << " and " << n << " is " << gcd(m, n) << '\n';
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