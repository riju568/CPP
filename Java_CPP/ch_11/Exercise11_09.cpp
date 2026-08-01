#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <exception>

int maxValue(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    return *std::max_element(nums.begin(), nums.end());
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter the array size n: ";
        int size = 0;
        if (!(std::cin >> size) || size <= 0) {
            std::cerr << "Error: Size must be a positive integer.\n";
            return 3;
        }

        std::vector<std::vector<int>> matrix(size, std::vector<int>(size));
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, 1);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = dist(gen);
            }
        }

        std::vector<int> rowSums(size, 0);
        std::vector<int> columnSums(size, 0);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                rowSums[i] += matrix[i][j];
                columnSums[j] += matrix[i][j];
            }
        }
        int maxRowVal = maxValue(rowSums);
        int maxColVal = maxValue(columnSums);
        std::cout << "The random array is:\n";
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << matrix[i][j];
            }
            std::cout << '\n';
        }

        std::cout << "\nThe largest row index/es is: ";
        for (int i = 0; i < size; ++i) {
            if (rowSums[i] == maxRowVal) {
                std::cout << i << " ";
            }
        }

        std::cout << "\nThe largest column index/es is: ";
        for (int j = 0; j < size; ++j) {
            if (columnSums[j] == maxColVal) {
                std::cout << j << " ";
            }
        }
        std::cout << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}