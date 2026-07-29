#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Robust C++ implementation of Activity08_02 with input validation,
 * bounds checking, and strict exception handling matching the established pattern.
 */
void gradeAllTests(const std::vector<std::vector<char>>& answers, const std::vector<char>& keys) {
    if (keys.empty()) {
        throw std::invalid_argument("Keys array cannot be empty.");
    }

    for (size_t i = 0; i < answers.size(); ++i) {
        if (answers[i].empty()) {
            std::cout << "Student " << i << "'s answers data is missing or empty.\n";
            continue;
        }
        if (answers[i].size() != keys.size()) {
            std::cout << "Student " << i << "'s answer count does not match the key length.\n";
            continue;
        }

        int correctCount = 0;
        for (size_t j = 0; j < answers[i].size(); ++j) {
            if (answers[i][j] == keys[j]) {
                correctCount++;
            }
        }
        std::cout << "Student " << i << "'s correct count is " << correctCount << '\n';
    }
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<std::vector<char>> answers = {
            { 'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D' },
            { 'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D' },
            { 'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D' },
            { 'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D' },
            { 'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D' },
            { 'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D' },
            { 'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D' },
            { 'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D' }
        };

        std::vector<char> keys = { 'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D' };

        gradeAllTests(answers, keys);

        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Configuration Error: " << e.what() << '\n';
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