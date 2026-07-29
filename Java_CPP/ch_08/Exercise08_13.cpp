#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>


/**
 * *8.13 (Locate the largest element) Write the following method that returns the location
 * of the largest element in a two-dimensional array.
 * public static int[] locateLargest(double[][] a)
 * The return value is a one-dimensional array that contains two elements. These
 * two elements indicate the row and column indices of the largest element in the
 * two-dimensional array.
 * <p>
 * Write a test program that prompts the user to enter a two-dimensional array and displays
 * the location of the largest element in the array.
 */
std::vector<int> locateLargest(const std::vector<std::vector<double>>& a) {
    if (a.empty() || a[0].empty()) {
        throw std::invalid_argument("Matrix cannot be null or empty.");
    }

    std::vector<int> largeIdx = {0, 0};
    // Initialize to the first element to correctly handle negative-only numbers
    double largest = a[0][0];

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i].empty()) {
            throw std::invalid_argument("Matrix row cannot be empty.");
        }
        for (size_t j = 0; j < a[i].size(); ++j) {
            if (a[i][j] > largest) {
                largest = a[i][j];
                largeIdx[0] = static_cast<int>(i);
                largeIdx[1] = static_cast<int>(j);
            }
        }
    }

    return largeIdx;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter the number of rows: ";
        int rows = 0;
        if (!(std::cin >> rows)) {
            std::cerr << "Error: Invalid row count format.\n";
            return EXIT_FAILURE;
        }

        std::cout << "Enter the number of columns: ";
        int cols = 0;
        if (!(std::cin >> cols)) {
            std::cerr << "Error: Invalid column count format.\n";
            return EXIT_FAILURE;
        }

        if (rows <= 0 || cols <= 0) {
            std::cerr << "Error: Matrix dimensions must be greater than zero.\n";
            return EXIT_FAILURE;
        }

        std::vector<std::vector<double>> arrTwoDim(rows, std::vector<double>(cols));
        std::cout << "Enter the elements for the " << rows << "-by-" << cols << " matrix row by row:\n";

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!(std::cin >> arrTwoDim[i][j])) {
                    std::cerr << "Error: Invalid numeric input format.\n";
                    return EXIT_FAILURE;
                }
            }
        }

        std::vector<int> largestLocation = locateLargest(arrTwoDim);
        std::cout << "The largest element is located at [" << largestLocation[0] << ", " << largestLocation[1] << "]\n";

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