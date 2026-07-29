#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
#include <exception>
#include <cstdlib>
/**

 * **8.14 (Explore matrix) Write a program that prompts the user to enter the length of a
 * square matrix, randomly fills in 0s and 1s into the matrix, prints the matrix, and
 * finds the rows, columns, and diagonals with all 0s or 1s. Here is a sample run of
 * the program:
 * <p>
 * Enter the size for the matrix: 4
 * 0111
 * 0000
 * 0100
 * 1111
 * All 0s on row 1
 * All 1s on row 3
 * No same numbers on a column
 * No same numbers on the major diagonal
 * No same numbers on the sub-diagonal
 */
/** Prints the matrix without array brackets for clean sample-run matching */
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
    }
}

/** Checks if a specific row contains identical elements matching 'num' */
bool isRowUniform(const std::vector<std::vector<int>>& matrix, int row, int num) {
    for (size_t j = 0; j < matrix[row].size(); ++j) {
        if (matrix[row][j] != num) {
            return false;
        }
    }
    return true;
}

/** Checks if a specific column contains identical elements matching 'num' */
bool isColumnUniform(const std::vector<std::vector<int>>& matrix, int col, int num) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (matrix[i][col] != num) {
            return false;
        }
    }
    return true;
}

/** Checks if the major diagonal (top-left to bottom-right) is uniform */
bool isMajorDiagonalUniform(const std::vector<std::vector<int>>& matrix, int num) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (matrix[i][i] != num) {
            return false;
        }
    }
    return true;
}

/** Checks if the sub-diagonal (top-right to bottom-left) is uniform */
bool isSubDiagonalUniform(const std::vector<std::vector<int>>& matrix, int num) {
    size_t size = matrix.size();
    for (size_t i = 0; i < size; ++i) {
        if (matrix[i][size - 1 - i] != num) {
            return false;
        }
    }
    return true;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter the size for the matrix: ";
        int size = 0;
        
        if (!(std::cin >> size)) {
            std::cerr << "Error: Invalid size format. Please enter an integer.\n";
            return EXIT_FAILURE;
        }

        if (size <= 0) {
            std::cerr << "Error: Matrix size must be greater than zero.\n";
            return EXIT_FAILURE;
        }
        std::vector<std::vector<int>> matrix(size, std::vector<int>(size));
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = dis(gen);
            }
        }
        std::cout << "\nGenerated Matrix:\n";
        printMatrix(matrix);
        std::cout << '\n';
        bool foundRowMatch = false;
        for (int i = 0; i < size; ++i) {
            if (isRowUniform(matrix, i, 0)) {
                std::cout << "All 0s on row " << i << '\n';
                foundRowMatch = true;
            } else if (isRowUniform(matrix, i, 1)) {
                std::cout << "All 1s on row " << i << '\n';
                foundRowMatch = true;
            }
        }
        if (!foundRowMatch) {
            std::cout << "No same numbers on a row\n";
        }

        // Evaluate and display column results
        bool foundColMatch = false;
        for (int j = 0; j < size; ++j) {
            if (isColumnUniform(matrix, j, 0)) {
                std::cout << "All 0s on column " << j << '\n';
                foundColMatch = true;
            } else if (isColumnUniform(matrix, j, 1)) {
                std::cout << "All 1s on column " << j << '\n';
                foundColMatch = true;
            }
        }
        if (!foundColMatch) {
            std::cout << "No same numbers on a column\n";
        }

        // Evaluate and display major diagonal results
        if (isMajorDiagonalUniform(matrix, 0)) {
            std::cout << "All 0s on the major diagonal\n";
        } else if (isMajorDiagonalUniform(matrix, 1)) {
            std::cout << "All 1s on the major diagonal\n";
        } else {
            std::cout << "No same numbers on the major diagonal\n";
        }

        // Evaluate and display sub-diagonal results
        if (isSubDiagonalUniform(matrix, 0)) {
            std::cout << "All 0s on the sub-diagonal\n";
        } else if (isSubDiagonalUniform(matrix, 1)) {
            std::cout << "All 1s on the sub-diagonal\n";
        } else {
            std::cout << "No same numbers on the sub-diagonal\n";
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