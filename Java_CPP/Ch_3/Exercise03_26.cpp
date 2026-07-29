#include <iostream>
#include <stdexcept>
#include <ios>
/**
 * 3.26 (Use the &&, || and ^ operators)
 * Write a program that prompts the user to enter
 * an integer and determines whether it is divisible by 5 and 6, whether it is divisible
 * by 5 or 6, and whether it is divisible by 5 or 6, but not both.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        int userInt = 0;
        std::cout << "Enter an integer: ";
        if (!(std::cin >> userInt)) {
            throw std::runtime_error("Please enter a valid integer.");
        }
        bool fiveAndSix = (userInt % 5 == 0) && (userInt % 6 == 0);
        bool fiveOrSix = (userInt % 5 == 0) || (userInt % 6 == 0);
        bool fiveSixNotBoth = (userInt % 5 == 0) ^ (userInt % 6 == 0);
        std::cout << std::boolalpha;
        std::cout << "Is " << userInt << " divisible by 5 and 6? " << fiveAndSix << "\n";
        std::cout << "Is " << userInt << " divisible by 5 or 6? " << fiveOrSix << "\n";
        std::cout << "Is " << userInt << " divisible by 5 or 6, but not both? " << fiveSixNotBoth << "\n";

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}