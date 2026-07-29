#include <iostream>
#include <exception>

/**
 * **5.33 (Perfect number) A positive integer is called a perfect number if it is equal to
 * the sum of all of its positive divisors, excluding itself. For example, 6 is the first
 * perfect number because 6 = 3 + 2 + 1. The next is 28 = 14 + 7 + 4 + 2
 * + 1. There are four perfect numbers less than 10,000. Write a program to find all
 * these four numbers
 */
int main() {

    std::ios_base::sync_with_stdio(true);
    try {
        std::cout << "The four perfect numbers less than 10,000 are:\n";
        for (int number = 6; number <= 10000; ++number) {
            int total = 0;
            for (int divisor = 1; divisor <= number / 2; ++divisor) {
                if (number % divisor == 0) {
                    total += divisor;
                }
            }
            if (number == total) {
                std::cout << number << '\n';
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}