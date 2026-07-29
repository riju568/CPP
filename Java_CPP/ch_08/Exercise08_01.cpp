#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/* 8.1 (Sum elements column by column) Write a method that returns the sum of
 * all the elements in a specified column in a matrix using the following header:
 * public static double sumColumn(double[][] m, int columnIndex)
 * Write a test program that reads a 3-by-4
 * matrix and displays the sum of each column.
 */
double sumColumn(const std::vector<std::vector<double>>& m, int columnIndex) {
    if (m.empty() || m[0].empty()) {
        throw std::invalid_argument("Matrix cannot be empty.");
    }
    if (columnIndex < 0 || static_cast<size_t>(columnIndex) >= m[0].size()) {
        throw std::out_of_range("Column index " + std::to_string(columnIndex) + " is out of bounds for the matrix.");
    }

    double sum = 0.0;

    for (size_t i = 0; i < m.size(); ++i) {
        if (m[i].empty()) {
            throw std::runtime_error("Row " + std::to_string(i) + " in the matrix is empty.");
        }
        if (static_cast<size_t>(columnIndex) >= m[i].size()) {
            throw std::out_of_range("Row " + std::to_string(i) + " does not have column index " + std::to_string(columnIndex));
        }

        sum += m[i][columnIndex];
    }

    return sum;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<std::vector<double>> superArray(3, std::vector<double>(4));

        std::cout << "Enter a 3-by-4 matrix row by row (space-separated values): \n";

        for (size_t i = 0; i < superArray.size(); ++i) {
            for (size_t j = 0; j < superArray[i].size(); ++j) {
                if (!(std::cin >> superArray[i][j])) {
                    std::cerr << "Error: Invalid input format. Please enter numeric values.\n";
                    return EXIT_FAILURE;
                }
            }
        }

        std::cout << "\n--- Results ---\n";
        for (size_t col = 0; col < superArray[0].size(); ++col) {
            double sum = sumColumn(superArray, static_cast<int>(col));
            std::cout << "The sum of the elements in column " << col << " is " << sum << '\n';
        }

        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Validation Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    } 
    catch (const std::out_of_range& e) {
        std::cerr << "Bounds Error: " << e.what() << '\n';
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