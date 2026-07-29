#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * 8.2 (Sum the major diagonal in a matrix) Write a method that
 * sums all the numbers in the major diagonal in an n � n matrix
 * of double values using the following header:
 * Write a test program that reads a 4-by-4 matrix and
 * displays the sum of all its elements on the major diagonal.
 */



double sumMajorDiagonal(const std::vector<std::vector<double>>& m) {
    if (m.empty()) {
        throw std::invalid_argument("Matrix cannot be empty.");
    }
    double sum = 0.0;
    size_t n = m.size();

    for (size_t i = 0; i < n; ++i) {
        if (m[i].empty()) {
            throw std::runtime_error("Row " + std::to_string(i) + " in the matrix is empty.");
        }
        if (m.size() != m[i].size()) {
            throw std::invalid_argument("Matrix must be a square (n x n) matrix.");
        }

        sum += m[i][i];
    }
    return sum;
}
int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<double>> fourByFour(4, std::vector<double>(4));

        std::cout << "Enter a 4-by-4 matrix row by row (space-separated values): \n";

        for (size_t row = 0; row < fourByFour.size(); ++row) {
            for (size_t column = 0; column < fourByFour[row].size(); ++column) {
                if (!(std::cin >> fourByFour[row][column])) {
                    std::cerr << "Error: Invalid input format. Please enter numeric values.\n";
                    return EXIT_FAILURE;
                }
            }
        }

        double diagonalSum = sumMajorDiagonal(fourByFour);
        std::cout << "The sum of the elements in the major diagonal is: " << diagonalSum << '\n';

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