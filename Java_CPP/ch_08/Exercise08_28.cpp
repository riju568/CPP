#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * *8.27 (Column sorting) Implement the following method to sort the columns in
 * a two-dimensional array. A new array is returned and the original array is intact.
 * public static double[][] sortColumns(double[][] m)
 */
std::vector<std::vector<double>> sortColumns(const std::vector<std::vector<double>>& m) {
    if (m.empty() || m[0].empty()) {
        throw std::invalid_argument("Matrix cannot be null or empty.");
    }
    size_t rows = m.size();
    size_t cols = m[0].size();
    std::vector<std::vector<double>> sorted(rows, std::vector<double>(cols));
    for (size_t i = 0; i < rows; ++i) {
        if (m[i].size() != cols) {
            throw std::invalid_argument("All rows must have the same number of columns.");
        }
        sorted[i] = m[i];
    }
    for (size_t col = 0; col < cols; ++col) {
        std::vector<double> columnData(rows);
        for (size_t row = 0; row < rows; ++row) {
            columnData[row] = sorted[row][col];
        }
        std::sort(columnData.begin(), columnData.end());
        for (size_t row = 0; row < rows; ++row) {
            sorted[row][col] = columnData[row];
        }
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
        std::vector<std::vector<double>> sortedMatrix = sortColumns(matrix);
        std::cout << "\nThe column-sorted array is:\n";
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