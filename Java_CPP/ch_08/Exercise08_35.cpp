#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Finds a maximum square submatrix whose elements are all 1s.
 * Returns an array (vector) of three values: row index, column index, and size (number of rows).
 */
std::vector<int> findLargestBlock(const std::vector<std::vector<int>>& m) {
    if (m.empty() || m[0].empty()) {
        return {0, 0, 0};
    }
    size_t rowLength = m.size();
    size_t columnLength = m[0].size();
    std::vector<std::vector<int>> dp(rowLength, std::vector<int>(columnLength, 0));
    int maxSize = 0;
    size_t maxI = 0;
    size_t maxJ = 0;
    for (size_t i = 0; i < rowLength; ++i) {
        for (size_t j = 0; j < columnLength; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = m[i][j];
            } else if (m[i][j] == 1) {
                dp[i][j] = std::min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
            } else {
                dp[i][j] = 0;
            }

            if (dp[i][j] > maxSize) {
                maxSize = dp[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }
    if (maxSize == 0) {
        return {0, 0, 0};
    }
    int startRow = static_cast<int>(maxI) - maxSize + 1;
    int startCol = static_cast<int>(maxJ) - maxSize + 1;
    return {startRow, startCol, maxSize};
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        int numRows = 0;
        std::cout << "Enter the number of rows in the matrix: ";
        if (!(std::cin >> numRows) || numRows <= 0) {
            throw std::invalid_argument("Invalid integer value for rows.");
        }
        std::vector<std::vector<int>> userMatrix(numRows, std::vector<int>(numRows));
        std::cout << "Enter the matrix row by row (0 or 1 values only): \n";

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numRows; ++j) {
                if (!(std::cin >> userMatrix[i][j])) {
                    throw std::invalid_argument("Invalid matrix element format.");
                }
            }
        }

        std::vector<int> largestBlock = findLargestBlock(userMatrix);

        std::cout << "The maximum square submatrix is at (" 
                  << largestBlock[0] << ", " 
                  << largestBlock[1] << ") with " 
                  << largestBlock[2] << " rows.\n";

        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << '\n';
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