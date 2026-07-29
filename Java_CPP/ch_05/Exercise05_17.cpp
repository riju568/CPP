#include <iostream>
#include <iomanip>
#include <exception>

/**
 * *5.17 (Display pyramid) Write a program that prompts the user to enter an integer from
 * 1 to 15 and displays a pyramid, as shown in the following sample run:
 * Enter the number of lines: 7
 */


int main() {
    std::ios_base::sync_with_stdio(true);

    try {
        std::cout << "Enter the number of lines (1 to 15): ";
        int numLines = 0;
        if (!(std::cin >> numLines)) {
            std::cout << "Error: Invalid input! Please enter a whole number.\n";
            return 1;
        }
        if (numLines < 1 || numLines > 15) {
            std::cout << "Error: Number of lines must be between 1 and 15.\n";
            return 0;
        }
        for (int i = 1; i <= numLines; ++i) {
            int offsetNums = numLines - i;
            for (int s = 0; s < offsetNums; ++s) {
                std::cout << "    ";
            }
            for (int leftSideNums = i; leftSideNums >= 2; --leftSideNums) {
                std::cout << std::setw(4) << leftSideNums;
            }

            for (int rightSideNums = 1; rightSideNums <= i; ++rightSideNums) {
                std::cout << std::setw(4) << rightSideNums;
            }

            std::cout << '\n';
        }

    } catch (const std::exception& e) {
        std::cout << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cout << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}