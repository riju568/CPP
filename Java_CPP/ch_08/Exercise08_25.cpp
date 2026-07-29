#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>

const std::string MARKOV_MSG = "It is a Markov matrix";
const std::string NOT_MARKOV_MSG = "It is not a Markov matrix";

/**
 * *8.25 (Markov matrix) An n * n matrix is called a positive Markov matrix if each
 * element is positive and the sum of the elements in each column is 1. Write the
 * following method to check whether a matrix is a Markov matrix.
 * public static boolean isMarkovMatrix(double[][] m)
 * <p>
 * Write a test program that prompts the user to enter a 3 * 3 matrix of double
 * values and tests whether it is a Markov matrix. Here are sample runs:
 * Enter a 3-by-3 matrix row by row:
 * 0.15 0.875 0.375
 * 0.55 0.005 0.225
 * 0.30 0.12 0.4
 * It is a Markov matrix
 * Enter a 3-by-3 matrix row by row:
 * 0.95 -0.875 0.375
 * 0.65 0.005 0.225
 * 0.30 0.22 -0.4
 * It is not a Markov matrix
 */
bool isMarkovMatrix(const std::vector<std::vector<double>>& m) {
    if (m.empty() || m[0].empty() || m.size() != m[0].size()) {
        throw std::invalid_argument("Matrix must be a non-null, square matrix.");
    }

    size_t n = m.size();
    const double EPSILON = 1e-9; // Threshold for floating-point accuracy comparison

    for (size_t c = 0; c < n; ++c) {
        double sum = 0.0;
        for (size_t r = 0; r < n; ++r) {
            if (m[r][c] < 0.0) {
                return false;
            }
            sum += m[r][c];
        }
        if (std::abs(sum - 1.0) > EPSILON) {
            return false;
        }
    }
    return true;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int size = 3; // Standard 3-by-3 matrix configuration for this exercise
        std::vector<std::vector<double>> test(size, std::vector<double>(size));

        std::cout << "Enter a " << size << "-by-" << size << " matrix row by row:\n";

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (!(std::cin >> test[i][j])) {
                    std::cerr << "Error: Expected a double value.\n";
                    return EXIT_FAILURE;
                }
            }
        }

        if (isMarkovMatrix(test)) {
            std::cout << MARKOV_MSG << '\n';
        } else {
            std::cout << NOT_MARKOV_MSG << '\n';
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