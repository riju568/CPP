#include <iostream>
#include <exception>
/**
 * *5.16 (Find the factors of an integer) Write a program that reads an integer and displays
 * all its smallest factors in increasing order. For example, if the input integer is
 * 120, the output should be as follows: 2, 2, 2, 3, 5.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    try {
        std::cout << "Enter an integer greater than 1: ";
        int num = 0;

        if (!(std::cin >> num)) {
            std::cout << "Error: Invalid input! Please enter a whole number.\n";
            return 1;
        }
        if (num <= 1) {
            std::cout << "Factors are only calculated for integers greater than 1.\n";
            return 0;
        }
        for (int i = 2; num > 1; ) {
            if (num % i == 0) {
                std::cout << i;
                num /= i;
                if (num > 1) {
                    std::cout << ", ";
                }
            } else {
                ++i;
            }
        }
        std::cout << '\n';
    } catch (const std::exception& e) {
        std::cout << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cout << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}