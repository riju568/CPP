#include <iostream>
#include <exception>

/**
 * 5.20 (Display prime numbers between 2 and 1,000)
 * Displays all prime numbers between 2 and 1,000 inclusive,
 * formatted 8 prime numbers per line separated by a space.
 */


bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int divisor = 2; divisor * divisor <= number; ++divisor) {
        if (number % divisor == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(true);
    constexpr int NUMBER_OF_PRIMES_PER_LINE = 8;
    constexpr int LOWER_BOUND = 2;
    constexpr int UPPER_BOUND = 1000;
    try {
        int count = 0;
        std::cout << "Prime nums between 2 and 1000 are:\n";
        for (int number = LOWER_BOUND; number <= UPPER_BOUND; ++number) {
            if (isPrime(number)) {
                ++count;
                if (count % NUMBER_OF_PRIMES_PER_LINE == 0) {
                    std::cout << number << '\n';
                } else {
                    std::cout << number << ' ';
                }
            }
        }
        if (count % NUMBER_OF_PRIMES_PER_LINE != 0) {
            std::cout << '\n';
        }

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }
    return 0;
}