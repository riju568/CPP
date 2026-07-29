#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Adds two matrices together and returns the resulting matrix.
 */
std::vector<std::vector<double>> addMatrix(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b) {
    if (a.empty() || b.empty()) {
        throw std::invalid_argument("Matrices cannot be empty.");
    }
    if (a.size() != b.size() || a[0].size() != b[0].size()) {
        throw std::invalid_argument("Matrices must have the exact same dimensions to be added.");
    }

    std::vector<std::vector<double>> sum(a.size(), std::vector<double>(a[0].size(), 0.0));

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i].empty() || b[i].empty() || a[i].size() != b[i].size()) {
            throw std::invalid_argument("Matrix rows must match in length and cannot be empty.");
        }
        for (size_t j = 0; j < a[i].size(); ++j) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    return sum;
}

/**
 * Prints the matrices side by side.
 */
void printSideBySideMatrices(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2, const std::vector<std::vector<double>>& res) {
    for (size_t i = 0; i < m1.size(); ++i) {
        for (size_t j = 0; j < m1[i].size(); ++j) {
            std::cout << m1[i][j] << " ";
        }
        if (i == 1) {
            std::cout << " +   ";
        } else {
            std::cout << "     ";
        }

        // Print Matrix 2 row
        for (size_t j = 0; j < m2[i].size(); ++j) {
            std::cout << m2[i][j] << " ";
        }
        if (i == 1) {
            std::cout << " =   ";
        } else {
            std::cout << "     ";
        }
        for (size_t j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<std::vector<double>> matrix1(3, std::vector<double>(3));
        std::vector<std::vector<double>> matrix2(3, std::vector<double>(3));

        std::cout << "Enter matrix one (3-by-3) row by row: \n";
        for (size_t i = 0; i < matrix1.size(); ++i) {
            for (size_t j = 0; j < matrix1[i].size(); ++j) {
                if (!(std::cin >> matrix1[i][j])) {
                    std::cerr << "Error: Invalid input format. Please enter numeric values.\n";
                    return EXIT_FAILURE;
                }
            }
        }

        std::cout << "Enter matrix two (3-by-3) row by row: \n";
        for (size_t i = 0; i < matrix2.size(); ++i) {
            for (size_t j = 0; j < matrix2[i].size(); ++j) {
                if (!(std::cin >> matrix2[i][j])) {
                    std::cerr << "Error: Invalid input format. Please enter numeric values.\n";
                    return EXIT_FAILURE;
                }
            }
        }

        std::vector<std::vector<double>> newMatrix = addMatrix(matrix1, matrix2);

        std::cout << "\nThe addition of the matrices is: \n";
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