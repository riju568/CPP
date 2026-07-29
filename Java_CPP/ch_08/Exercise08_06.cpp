#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Multiplies two matrices together and returns the resulting matrix.
 */
std::vector<std::vector<double>> multiplyMatrix(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b) {
    if (a.empty() || b.empty()) {
        throw std::invalid_argument("Matrices cannot be empty.");
    }

    size_t rowsA = a.size();
    size_t colsA = a[0].size();
    size_t rowsB = b.size();
    size_t colsB = b[0].size();

    // Validation: Columns in A must equal rows in B
    if (colsA != rowsB) {
        throw std::invalid_argument(
            "Cannot multiply: Number of columns in Matrix A (" + std::to_string(colsA) + 
            ") must match the number of rows in Matrix B (" + std::to_string(rowsB) + ")."
        );
    }

    std::vector<std::vector<double>> result(rowsA, std::vector<double>(colsB, 0.0));

    for (size_t i = 0; i < rowsA; ++i) {
        if (a[i].empty() || a[i].size() != colsA) {
            throw std::invalid_argument("Matrix A contains inconsistent row lengths or empty rows.");
        }
        for (size_t j = 0; j < colsB; ++j) {
            for (size_t z = 0; z < colsA; ++z) {
                if (b[z].empty() || b[z].size() != colsB) {
                    throw std::invalid_argument("Matrix B contains inconsistent row lengths or empty rows.");
                }
                result[i][j] += a[i][z] * b[z][j];
            }
        }
    }

    return result;
}

/**
 * Safely prints Matrix 1, Matrix 2, and the Product Matrix side-by-side.
 */
void printSideBySideMatrices(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2, const std::vector<std::vector<double>>& res) {
    for (size_t i = 0; i < m1.size(); ++i) {
        // Print Matrix 1 row
        for (size_t j = 0; j < m1[i].size(); ++j) {
            std::cout << m1[i][j] << " ";
        }
        if (i == 1) {
            std::cout << " * ";
        } else {
            std::cout << "    ";
        }

        // Print Matrix 2 row
        for (size_t j = 0; j < m2[i].size(); ++j) {
            std::cout << m2[i][j] << " ";
        }
        if (i == 1) {
            std::cout << " =  ";
        } else {
            std::cout << "    ";
        }

        // Print Result Matrix row
        for (size_t j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<double>> matrix1(3, std::vector<double>(3));
        std::vector<std::vector<double>> matrix2(3, std::vector<double>(3));

        std::cout << "Enter the values for the first 3 x 3 matrix: \n";
        for (size_t i = 0; i < matrix1.size(); ++i) {
            for (size_t j = 0; j < matrix1[i].size(); ++j) {
                if (!(std::cin >> matrix1[i][j])) {
                    std::cerr << "Error: Invalid input format. Please enter numeric values.\n";
                    return EXIT_FAILURE;
                }
            }
        }

        std::cout << "Enter the values for the second 3 x 3 matrix: \n";
        for (size_t i = 0; i < matrix2.size(); ++i) {
            for (size_t j = 0; j < matrix2[i].size(); ++j) {
                if (!(std::cin >> matrix2[i][j])) {
                    std::cerr << "Error: Invalid input format. Please enter numeric values.\n";
                    return EXIT_FAILURE;
                }
            }
        }

        std::vector<std::vector<double>> newMatrix = multiplyMatrix(matrix1, matrix2);

        std::cout << "\nThe multiplication of the two matrices is as follows:\n";
        printSideBySideMatrices(matrix1, matrix2, newMatrix);

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