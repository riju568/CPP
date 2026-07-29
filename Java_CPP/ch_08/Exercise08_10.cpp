#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * 8.10 (Largest row and column) Write a program that randomly fills in 0s and 1s into
 * a 4-by-4 matrix, prints the matrix, and finds the first row and column with the
 * most 1s. Here is a sample run of the program:
 * 0011
 * 0011
 * 1101
 * 1010
 * The largest row index: 2
 * The largest column index: 2
 */

/** Prints the 2D matrix */
void printMatrix(const std::vector<std::vector<int>>& a) {
    if (a.empty()) {
        throw std::invalid_argument("Matrix cannot be empty.");
    }
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            std::cout << a[i][j];
        }
        std::cout << '\n';
    }
}

/** Finds the first row index with the most 1s dynamically */
int findLargestRow(const std::vector<std::vector<int>>& a) {
    if (a.empty() || a[0].empty()) {
        throw std::invalid_argument("Matrix cannot be null or empty.");
    }

    int largeRow = 0;
    int largeSum = 0;

    // Sum the first row
    for (size_t j = 0; j < a[0].size(); ++j) {
        largeSum += a[0][j];
    }

    // Compare with subsequent rows
    for (size_t i = 1; i < a.size(); ++i) {
        int currentSum = 0;
        for (size_t j = 0; j < a[i].size(); ++j) {
            currentSum += a[i][j];
        }

        if (currentSum > largeSum) {
            largeSum = currentSum;
            largeRow = static_cast<int>(i);
        }
    }
    return largeRow;
}

/** Finds the first column index with the most 1s dynamically */
int findLargestColumn(const std::vector<std::vector<int>>& a) {
    if (a.empty() || a[0].empty()) {
        throw std::invalid_argument("Matrix cannot be null or empty.");
    }

    int largeColumn = 0;
    int largeSum = 0;

    // Sum the first column
    for (size_t i = 0; i < a.size(); ++i) {
        if (!a[i].empty()) {
            largeSum += a[i][0];
        }
    }

    // Compare with subsequent columns
    for (size_t j = 1; j < a[0].size(); ++j) {
        int currentSum = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            if (j < a[i].size()) {
                currentSum += a[i][j];
            }
        }

        if (currentSum > largeSum) {
            largeSum = currentSum;
            largeColumn = static_cast<int>(j);
        }
    }
    return largeColumn;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        const int size = 4;
        std::vector<std::vector<int>> randomMatrix(size, std::vector<int>(size));

        // Randomly fill the matrix with 0s and 1s using modern C++ random facilities
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                randomMatrix[i][j] = dis(gen);
            }
        }

        std::cout << "Generated Matrix:\n";
        printMatrix(randomMatrix);

        int largestRow = findLargestRow(randomMatrix);
        int largestColumn = findLargestColumn(randomMatrix);

        std::cout << "The largest row index: " << largestRow << '\n';
        std::cout << "The largest column index: " << largestColumn << '\n';

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