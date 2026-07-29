#include <iostream>
#include <algorithm>
#include <exception>

/**
 * 5.14 (Compute the greatest common divisor) Prompts the user for two positive 
 * integers and finds their GCD by counting down from the minimum value. 
 * Refactored with proper resource management and exception handling.
 */



int main() {
    std::ios_base::sync_with_stdio(true);
    try {
        std::cout << "Enter the first positive integer: ";
        int n1 = 0;
        if (!(std::cin >> n1)) {
            std::cerr << "Error: Invalid input. Please enter valid positive integers only.\n";
            return 1;
        }

        std::cout << "Enter the second positive integer: ";
        int n2 = 0;
        if (!(std::cin >> n2)) {
            std::cerr << "Error: Invalid input. Please enter valid positive integers only.\n";
            return 1;
        }

        if (n1 <= 0 || n2 <= 0) {
            std::cout << "Error: Both numbers must be positive integers greater than 0.\n";
            return 0;
        }

        int gcd = std::min(n1, n2);
        while (n1 % gcd != 0 || n2 % gcd != 0) {
            --gcd;
        }

        // Display results
        std::cout << "The GCD of " << n1 << " and " << n2 << " is " << gcd << '\n';

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}