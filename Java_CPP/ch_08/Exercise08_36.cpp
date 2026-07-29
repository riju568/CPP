#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <string>

/**
 * **8.36 (Latin square) A Latin square is an n-by-n array filled with n different Latin letters,
 * each occurring exactly once in each row and once in each column.
 * <p>
 * Write a program that prompts the user to enter the number n and the array of characters,
 * as shown in the sample output, and checks if the input array is a Latin square.
 * The characters are the first n characters starting from A.
 * Enter number n: 3
 * Enter 3 rows of letters separated by spaces:
 * A F D
 * Wrong input: the letters must be from A to C
 * <p>
 * Enter number n: 4
 * Enter 4 rows of letters separated by spaces:
 * A B C D
 * B A D C
 * C D B A
 * D C A B
 * The input array is a Latin square
 */


/**
 * *8.36 (Latin square) A Latin square is an n-by-n array filled with n different 
 * Latin letters, each occurring exactly once in each row and once in each column.
 */


int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter number n: ";
        int numRows = 0;
        if (!(std::cin >> numRows)) {
            std::cout << "Invalid input for n.\n";
            return EXIT_FAILURE;
        }

        if (numRows <= 0) {
            std::cout << "The number n must be greater than 0.\n";
            return EXIT_FAILURE;
        }

        std::vector<std::vector<char>> chars(numRows, std::vector<char>(numRows));
        char upperBoundChar = static_cast<char>('A' + numRows - 1);

        std::cout << "Enter " << numRows << " rows of letters separated by spaces: \n";
        for (int r = 0; r < numRows; ++r) {
            for (int c = 0; c < numRows; ++c) {
                std::string strCh;
                if (!(std::cin >> strCh)) {
                    std::cout << "Error: Invalid input encountered.\n";
                    return EXIT_FAILURE;
                }
                chars[r][c] = strCh[0];
            }
        }

        // Validate character boundaries and uniqueness
        bool isLatinSquare = true;

        for (int i = 0; i < numRows; ++i) {
            std::vector<bool> rowCheck(numRows, false);
            std::vector<bool> colCheck(numRows, false);

            for (int j = 0; j < numRows; ++j) {
                // Check row elements
                char rowChar = chars[i][j];
                if (rowChar < 'A' || rowChar > upperBoundChar) {
                    std::cout << "Wrong input: the letters must be from A to " << upperBoundChar << '\n';
                    return EXIT_SUCCESS;
                }
                int rowIndex = rowChar - 'A';
                if (rowCheck[rowIndex]) {
                    isLatinSquare = false;
                    break;
                }
                rowCheck[rowIndex] = true;

                // Check column elements
                char colChar = chars[j][i];
                if (colChar < 'A' || colChar > upperBoundChar) {
                    std::cout << "Wrong input: the letters must be from A to " << upperBoundChar << '\n';
                    return EXIT_SUCCESS;
                }
                int colIndex = colChar - 'A';
                if (colCheck[colIndex]) {
                    isLatinSquare = false;
                }
                colCheck[colIndex] = true;
            }
            if (!isLatinSquare && !rowCheck[chars[i][0] - 'A']) {
                // Break out if row check failed early
                break;
            }
        }

        if (isLatinSquare) {
            std::cout << "The input array is a Latin square\n";
        } else {
            std::cout << "The input array is not a Latin square\n";
        }

        return EXIT_SUCCESS;
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