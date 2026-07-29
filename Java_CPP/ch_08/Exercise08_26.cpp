#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * *8.26 (Row sorting) Implement the following method to sort the rows in a
 * two-dimensional array.
 * <p>
 * A new array is returned and the original array is intact.
 * public static double[][] sortRows(double[][] m)
 * <p>
 * <p>
 * Write a test program that prompts the user to enter a 3 * 3 matrix of double
 * values and displays a new row-sorted matrix.
 * <p>
 * Here is a sample run:
 * Enter a 3-by-3 matrix row by row:
 * 0.15 0.875 0.375
 * 0.55 0.005 0.225
 * 0.30 0.12 0.4
 * The row-sorted array is
 * 0.15 0.375 0.875
 * 0.005 0.225 0.55
 * 0.12 0.30 0.4
 */
std::vector<std::vector<double>> sortRows(const std::vector<std::vector<double>>& m) {
    if (m.empty() || m[0].empty()) {
        throw std::invalid_argument("Matrix cannot be empty.");
    }
    size_t rows = m.size();
    size_t cols = m[0].size();
    std::vector<std::vector<double>> sorted(rows, std::vector<double>(cols));
    for (size_t i = 0; i < rows; ++i) {
        if (m[i].size() != cols) {
            throw std::invalid_argument("All rows must have the same number of columns.");
        }
        sorted[i] = m[i];
        std::sort(sorted[i].begin(), sorted[i].end());
    }

    return sorted;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        int size = 3; 
        std::vector<std::vector<double>> matrix(size, std::vector<double>(size));
        std::cout << "Enter a " << size << "-by-" << size << " matrix row by row:\n";
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (!(std::cin >> matrix[i][j])) {
                    std::cerr << "Error: Expected a double value.\n";
                    return EXIT_FAILURE;
                }
            }
        }
        std::vector<std::vector<double>> sortedMatrix = sortRows(matrix);
        std::cout << "\nThe row-sorted array is:\n";
        for (size_t i = 0; i < sortedMatrix.size(); ++i) {
            for (size_t j = 0; j < sortedMatrix[i].size(); ++j) {
                std::cout << sortedMatrix[i][j] << (j + 1 < sortedMatrix[i].size() ? " " : "");
            }
            std::cout << '\n';
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