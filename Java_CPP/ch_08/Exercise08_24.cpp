#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * *8.24 (Check Sudoku solution) Listing 8.4 checks whether a solution is valid by checking whether every number is valid in the board.
 * Rewrite the program by checking whether every row, every column,
 * and every small box has the numbers 1 to 9.
 *
 */
int evalColumns(const std::vector<std::vector<int>>& array) {
    if (array.empty() || array[0].empty()) {
        throw std::invalid_argument("Matrix cannot be empty.");
    }

    size_t cols = array[0].size();
    size_t rows = array.size();

    for (size_t c = 0; c < cols; ++c) {
        int colCountOnes = 0;
        for (size_t r = 0; r < rows; ++r) {
            if (array[r][c] == 1) {
                ++colCountOnes;
            }
        }
        if (colCountOnes % 2 != 0) {
            return static_cast<int>(c);
        }
    }
    return -1;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::vector<std::vector<int>> matrix(6, std::vector<int>(6));
        std::cout << "Enter a 6-by-6 matrix row by row (0s and 1s):\n";
        int invalidRow = -1;
        for (int i = 0; i < 6; ++i) {
            int rowCountOnes = 0;
            for (int j = 0; j < 6; ++j) {
                int val = 0;
                if (!(std::cin >> val)) {
                    std::cerr << "Error: Expected an integer (0 or 1).\n";
                    return EXIT_FAILURE;
                }
                if (val != 0 && val != 1) {
                    std::cerr << "Error: Matrix values must strictly be 0 or 1.\n";
                    return EXIT_FAILURE;
                }
                matrix[i][j] = val;
                if (val == 1) {
                    ++rowCountOnes;
                }
            }
            if (rowCountOnes % 2 != 0) {
                invalidRow = i;
            }
        }
        int invalidCol = evalColumns(matrix);
        if (invalidRow != -1 && invalidCol != -1) {
            std::cout << "The flipped cell is at (" << invalidRow << ", " << invalidCol << ")\n";
        } else {
            std::cout << "No flipped cell detected or matrix parity is fully valid.\n";
        }
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