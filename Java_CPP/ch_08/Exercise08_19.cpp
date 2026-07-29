#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Tests whether a two-dimensional vector has four consecutive numbers
 * of the same value horizontally, vertically, or diagonally.
 * @param values 2D integer vector
 * @return true if four consecutive equal values exist, false otherwise
 */
bool isConsecutiveFour(const std::vector<std::vector<int>>& values) {
    if (values.empty() || values[0].empty()) {
        throw std::invalid_argument("Matrix cannot be empty.");
    }

    int rows = static_cast<int>(values.size());
    int cols = static_cast<int>(values[0].size());

    // 1. Check Horizontal (Rows)
    for (int r = 0; r < rows; ++r) {
        int count = 1;
        for (int c = 1; c < cols; ++c) {
            if (values[r][c] == values[r][c - 1]) {
                ++count;
            } else {
                count = 1;
            }
            if (count >= 4) {
                return true;
            }
        }
    }

    // 2. Check Vertical (Columns)
    for (int c = 0; c < cols; ++c) {
        int count = 1;
        for (int r = 1; r < rows; ++r) {
            if (values[r][c] == values[r - 1][c]) {
                ++count;
            } else {
                count = 1;
            }
            if (count >= 4) {
                return true;
            }
        }
    }

    // 3. Check Diagonal (Down-Right and Up-Right)
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int val = values[r][c];

            // Check Down-Right diagonal
            if (r + 3 < rows && c + 3 < cols) {
                if (values[r + 1][c + 1] == val &&
                    values[r + 2][c + 2] == val &&
                    values[r + 3][c + 3] == val) {
                    return true;
                }
            }

            // Check Up-Right diagonal
            if (r - 3 >= 0 && c + 3 < cols) {
                if (values[r - 1][c + 1] == val &&
                    values[r - 2][c + 2] == val &&
                    values[r - 3][c + 3] == val) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::cout << "Enter the number of rows and columns of a two-dimensional array: ";
        int numRows = 0;
        int numColumns = 0;

        if (!(std::cin >> numRows >> numColumns)) {
            std::cerr << "Error: Invalid dimension format.\n";
            return EXIT_FAILURE;
        }

        if (numRows <= 0 || numColumns <= 0) {
            std::cerr << "Error: Matrix dimensions must be greater than zero.\n";
            return EXIT_FAILURE;
        }

        std::vector<std::vector<int>> values(numRows, std::vector<int>(numColumns));
        std::cout << "Enter the values for the " << numRows << "-by-" << numColumns << " matrix:\n";

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numColumns; ++j) {
                if (!(std::cin >> values[i][j])) {
                    std::cerr << "Error: Invalid numeric input format.\n";
                    return EXIT_FAILURE;
                }
            }
        }

        std::cout << "\nAre there four consecutive numbers?\n";
        std::cout << (isConsecutiveFour(values) ? "true" : "false") << '\n';

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