#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <exception>
#include <cstdlib>

/**
 * *5.47 (Business: check ISBN-13) ISBN-13 is a new standard for identifying books. It
 * uses 13 digits d1d2d3d4d5d6d7d8d9d10d11d12d13. The last digit d13 is a checksum,
 * which is calculated from the other digits using the following formula:
 * 10 - (d1 + 3d2 + d3 + 3d4 + d5 + 3d6 + d7 + 3d8 + d9 + 3d10 + d11 + 3d12)%10
 * If the checksum is 10, replace it with 0. Your program should read the input as a
 * string.
 * <p>
 * <strong>Here are sample runs:</strong>
 * <p>
 * {@code Enter the first 12 digits of an ISBN-13 as a string: 978013213080
 * The ISBN-13 number is 9780132130806
 * <p>
 * Enter the first 12 digits of an ISBN-13 as a string: 978013213079
 * The ISBN-13 number is 9780132130790
 * <p>
 * Enter the first 12 digits of an ISBN-13 as a string: 97801320
 * 97801320 is an invalid input}
 */


int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter the first 12 digits of an ISBN-13 as a string: ";
        std::string isbn;
        if (!std::getline(std::cin, isbn)) {
            std::cerr << "Error reading input.\n";
            return EXIT_FAILURE;
        }
        bool is_valid_digits = std::all_of(isbn.begin(), isbn.end(), [](unsigned char c) {
            return std::isdigit(c);
        });
        if (isbn.length() != 12 || !is_valid_digits) {
            std::cout << isbn << " is an invalid input\n";
            return EXIT_SUCCESS;
        }
        int sum = 0;
        for (std::size_t i = 0; i < isbn.length(); ++i) {
            int digit = isbn[i] - '0'; // Fast ASCII character to integer conversion
            sum += (i % 2 == 0) ? digit : 3 * digit;
        }
        int check = 10 - (sum % 10);
        if (check == 10) {
            check = 0;
        }
        std::cout << "The ISBN-13 number is " << isbn << check << '\n';
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