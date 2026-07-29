#include <iostream>
#include <cstdint>
#include <string>
#include <exception>
#include <cstdlib>
/**
 * *5.44 (Computer architecture: bit-level operations) A short value is stored in 16 bits.
 * Write a program that prompts the user to enter a short integer and displays the 16
 * bits for the integer.
 * <p>
 * Here are sample runs:
 * <p>
 * Enter an integer: 5
 * The bits are 0000000000000101
 * Enter an integer: -5
 * The bits are 1111111111111011
 * (Hint: You need to use the bitwise right shift operator (>>) and the bitwise AND
 * operator (&), which are covered in Appendix G, Bitwise Operations.)
 */
int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter a short integer: ";
        std::int16_t number = 0;
        if (!(std::cin >> number)) {
            std::cerr << "Invalid input! Please enter a valid 16-bit integer.\n";
            return EXIT_FAILURE;
        }
        std::uint16_t u_number = static_cast<std::uint16_t>(number);
        std::string bits;
        bits.reserve(16); 
        for (int i = 15; i >= 0; --i) {
            bits += ((u_number >> i) & 1) ? '1' : '0';
        }
        std::cout << "The bits are " << bits << '\n';
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e) {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}