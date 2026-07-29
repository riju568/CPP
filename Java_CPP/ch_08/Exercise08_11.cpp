#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * **8.11 (Game: nine heads and tails) Nine coins are placed in a 3-by-3 matrix
 * with some face up and some face down. You can represent the state of the
 * coins using a 3-by-3 matrix with values 0 (heads) and 1 (tails). Here are
 * some examples: 0 0 0 1 0 1 1 1 0 1 0 1 1 0 0 0 1 0 0 0 1 1 0 0 1 1 0 1 1 1 0
 * 0 0 1 0 0 0 0 1 1 0 0 1 1 0 Each state can also be represented using a binary
 * number. For example, the preceding matrices correspond to the numbers
 * 000010000 101001100 110100001 101110100 100111110 There are a total of 512
 * possibilities, so you can use decimal numbers 0, 1, 2, 3, . . . , and 511 to
 * represent all states of the matrix. Write a program that prompts the user to
 * enter a number between 0 and 511 and displays the corresponding matrix with
 * the characters H and T.
 * <p>
 * Here is a sample run: Enter a number between 0 and 511: 7
 * <p>
 * H H H H H H T T T
 * <p>
 * The user entered 7, which corresponds to 000000111. Since 0 stands for H and
 * 1 for T, the output is correct. (e.g) count from 1 to 7: 000 001 010 011 100
 * 101 110 111
 */




/** Displays the 3x3 coin matrix corresponding to the given number (0 to 511) */
void displayCoinMatrix(int number) {
    std::string binStr = std::bitset<9>(number).to_string();
    std::vector<std::vector<char>> coinMatrix(3, std::vector<char>(3));
    int charIndex = 0;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            char bit = binStr[charIndex++];
            // '0' stands for Heads (H), '1' stands for Tails (T)
            coinMatrix[row][col] = (bit == '1') ? 'T' : 'H';
        }
    }

    // Print the resulting 3x3 matrix
    std::cout << "\nCorresponding 3x3 Coin Matrix:\n";
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << coinMatrix[row][col] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a number between 0 and 511: ";
        int userNum = 0;
        
        if (!(std::cin >> userNum)) {
            std::cerr << "Error: Invalid input format. Please enter an integer.\n";
            return EXIT_FAILURE;
        }

        // Validate that the number falls within the allowed 0 to 511 range
        if (userNum < 0 || userNum > 511) {
            std::cerr << "Error: Number must be between 0 and 511 inclusive.\n";
            return EXIT_FAILURE;
        }

        displayCoinMatrix(userNum);

        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Validation Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    } 
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}