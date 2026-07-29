#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <cstdlib>
/**
 * 5.46 (Reverse a string) Write a program that prompts
 * the user to enter a string and displays the string in reverse order.
 */
int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter a string: ";
        std::string str;
        if (!std::getline(std::cin, str)) {
            std::cerr << "Error: Failed to read input string.\n";
            return EXIT_FAILURE;
        }
        for (auto it = str.rbegin(); it != str.rend(); ++it) {
            std::cout << *it;
        }
        std::cout << '\n';
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