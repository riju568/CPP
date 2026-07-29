#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * 8.29 (Identical arrays) The two-dimensional arrays m1 and m2 are identical if they
 * have the same contents. Write a method that returns true if m1 and m2 are identical, using the following header:
 * public static boolean equals(int[][] m1, int[][] m2)
 * <p>
 * <p>
 * Write a test program that prompts the user to enter two 3 * 3 arrays of integers
 * and displays whether the two are identical. Here are the sample runs.
 * Enter list1: 51 5 22 6 1 4 24 54 6
 * Enter list2: 51 22 25 6 1 4 24 54 6
 * The two arrays are not identical
 * Enter list1: 51 25 22 6 1 4 24 54 6
 * Enter list2: 51 22 25 6 1 4 24 54 6
 * The two arrays are identical
 */

std::vector<int> flattenAndSort(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        throw std::invalid_argument("Matrix cannot be empty.");
    }
    size_t totalRows = matrix.size();
    size_t totalCols = matrix[0].size();
    std::vector<int> flat;
    flat.reserve(totalRows * totalCols);
    for (size_t i = 0; i < totalRows; ++i) {
        if (matrix[i].size() != totalCols) {
            throw std::invalid_argument("All rows must have the same number of columns.");
        }
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            flat.push_back(matrix[i][j]);
        }
    }
    std::sort(flat.begin(), flat.end());
    return flat;
}
bool equals(const std::vector<std::vector<int>>& m1, const std::vector<std::vector<int>>& m2) {
    if (m1.size() != m2.size()) {
        return false;
    }
    
    std::vector<int> flat1 = flattenAndSort(m1);
    std::vector<int> flat2 = flattenAndSort(m2);

    return flat1 == flat2;
}

/** Populates a 3x3 matrix from standard input */
void populateArray(std::vector<std::vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (!(std::cin >> matrix[i][j])) {
                throw std::invalid_argument("Non-integer value encountered.");
            }
        }
    }
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        int size = 3;
        std::vector<std::vector<int>> one(size, std::vector<int>(size));
        std::cout << "Enter list1: ";
        populateArray(one);
        std::vector<std::vector<int>> two(size, std::vector<int>(size));
        std::cout << "Enter list2: ";
        populateArray(two);
        if (equals(one, two)) {
            std::cout << "The arrays are identical.\n";
        } else {
            std::cout << "The arrays are not identical.\n";
        }

        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << '\n';
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