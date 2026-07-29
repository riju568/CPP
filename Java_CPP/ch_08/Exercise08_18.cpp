#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <cstdlib>
/**
 * *8.18 (Shuffle rows) Write a method that shuffles the rows in a two-dimensional int
 * array using the following header:
 * public static void shuffle(int[][] m)
 * Write a test program that shuffles the following matrix:
 * int[][] m = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
 */
void shuffle(std::vector<std::vector<int>>& m) {
    if (m.empty()) {
        throw std::invalid_argument("Matrix cannot be empty.");
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = static_cast<int>(m.size()) - 1; i > 0; --i) {
        // Pick a random index from 0 to i
        std::uniform_int_distribution<> dis(0, i);
        int j = dis(gen);
        std::swap(m[i], m[j]);
    }
}

void printMatrix(const std::vector<std::vector<int>>& m) {
    for (const auto& row : m) {
        std::cout << "[";
        for (size_t j = 0; j < row.size(); ++j) {
            std::cout << row[j];
            if (j + 1 < row.size()) {
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
        std::vector<std::vector<int>> m = {
            {1, 2}, 
            {3, 4}, 
            {5, 6}, 
            {7, 8}, 
            {9, 10}
        };
        std::cout << "Original Matrix:\n";
        printMatrix(m);
        shuffle(m);
        std::cout << "\nShuffled Matrix:\n";
        printMatrix(m);
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