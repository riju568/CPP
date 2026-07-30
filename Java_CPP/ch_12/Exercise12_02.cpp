#include <iostream>
#include <string>
#include <limits>
#include <format>
#include <exception>
#include <cstdlib>

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        int i1{0};
        int i2{0};
        bool inputMismatch{false};

        do {
            std::cout << "Enter two integers: ";
            if (std::cin >> i1 >> i2) {
                std::cout << std::format("Sum = {}\n", i1 + i2);
                inputMismatch = false;
            } else {
                inputMismatch = true;
                std::cout << "Incorrect input type, please try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (inputMismatch);

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