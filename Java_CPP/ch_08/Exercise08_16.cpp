#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <cstdlib>
/*

*8.16 (Sort two-dimensional array) Write a method to sort a two-dimensional array

using the following header:

public static void sort(int m[][])

The method performs a primary sort on rows and a secondary sort on columns.

For example, the following array

{{4, 2},{1, 7},{4, 5},{1, 2},{1, 1},{4, 1}}

will be sorted to

{{1, 1},{1, 2},{1, 7},{4, 1},{4, 2},{4, 5}}.

 */

/** Compares two rows for primary sort on rows and secondary sort on columns */
int compareRows(const std::vector<int>& rowA, const std::vector<int>& rowB) {
    size_t length = std::min(rowA.size(), rowB.size());
    for (size_t k = 0; k < length; ++k) {
        if (rowA[k] != rowB[k]) {
            return (rowA[k] < rowB[k]) ? -1 : 1;
        }
    }
    if (rowA.size() == rowB.size()) {
        return 0;
    }
    return (rowA.size() < rowB.size()) ? -1 : 1;
}

/** Robust implementation of sorting a two-dimensional vector */
void sortMatrix(std::vector<std::vector<int>>& m) {
    if (m.empty()) {
        throw std::invalid_argument("Matrix cannot be empty.");
    }

    for (size_t i = 0; i < m.size() - 1; ++i) {
        size_t minIndex = i;

        for (size_t j = i + 1; j < m.size(); ++j) {
            int comparisonResult = compareRows(m[j], m[minIndex]);
            // If row j is "less than" the current minimum row, update minIndex
            if (comparisonResult < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(m[i], m[minIndex]);
        }
    }
}

/** Prints the 2D matrix */
void printMatrix(const std::vector<std::vector<int>>& m) {
    for (size_t i = 0; i < m.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < m[i].size(); ++j) {
            std::cout << m[i][j];
            if (j + 1 < m[i].size()) {
                std::cout << ", ";
            }
        }
        std::cout << "] ";
    }
    std::cout << '\n';
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> testArray = {
            {4, 2}, 
            {1, 7}, 
            {4, 5}, 
            {1, 2}, 
            {1, 1}, 
            {4, 1}
        };

        std::cout << "Original Array:\n";
        printMatrix(testArray);

        sortMatrix(testArray);

        std::cout << "\nSorted Array:\n";
        printMatrix(testArray);

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