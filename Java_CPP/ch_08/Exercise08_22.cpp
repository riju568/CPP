#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
#include <exception>
#include <cstdlib>
/**
 * *8.22 (Even number of 1s) Write a program that generates a 6-by-6 two-dimensional
 * matrix filled with 0s and 1s, displays the matrix, and checks if every row and
 * every column have an even number of 1s.
 */
void printMatrix(const std::vector<std::vector<int>>& arr) {
    for (const auto& row : arr) {
        std::cout << "[";
        for (size_t j = 0; j < row.size(); ++j) {
            std::cout << row[j];
            if (j + 1 < row.size()) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
}
void fillZeroAndOnes(std::vector<std::vector<int>>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("Matrix cannot be empty.");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = 0; j < arr[i].size(); ++j) {
            arr[i][j] = dis(gen); // Generates either 0 or 1
        }
    }
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> matrix(6, std::vector<int>(6));
        fillZeroAndOnes(matrix);

        std::cout << "Generated 6-by-6 Binary Matrix:\n";
        printMatrix(matrix);
        std::cout << '\n';

        bool allRowsEven = true;
        bool allColsEven = true;

        for (size_t r = 0; r < matrix.size(); ++r) {
            int numOnes = 0;
            for (int val : matrix[r]) {
                if (val == 1) {
                    ++numOnes;
                }
            }
            bool isEven = (numOnes % 2 == 0);
            std::cout << "Row " << r << " has " << numOnes << " ones (Even: " << (isEven ? "true" : "false") << ")\n";
            if (!isEven) {
                allRowsEven = false;
            }
        }

        std::cout << '\n';
        for (size_t c = 0; c < matrix[0].size(); ++c) {
            int numOnes = 0;
            for (size_t r = 0; r < matrix.size(); ++r) {
                if (matrix[r][c] == 1) {
                    ++numOnes;
                }
            }
            bool isEven = (numOnes % 2 == 0);
            std::cout << "Column " << c << " has " << numOnes << " ones (Even: " << (isEven ? "true" : "false") << ")\n";
            if (!isEven) {
                allColsEven = false;
            }
        }

        std::cout << '\n';
        if (allRowsEven && allColsEven) {
            std::cout << "Every row and every column have an even number of 1s.\n";
        } else {
            std::cout << "Not every row and every column have an even number of 1s.\n";
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