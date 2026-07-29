#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Robust implementation of Exercise 08.03 with validation, exception handling,
 * and a corrected score-tracking mechanism.
 */
void sortAndDisplayStudents(const std::vector<std::vector<char>>& answers, const std::vector<char>& keys) {
    if (keys.empty()) {
        throw std::invalid_argument("Keys array cannot be empty.");
    }

    // stuScores = vector of vectors [Student count][2], where [][0] = score, [][1] = student ID
    std::vector<std::vector<int>> stuScores(answers.size(), std::vector<int>(2, 0));

    for (size_t i = 0; i < answers.size(); ++i) {
        if (answers[i].empty()) {
            std::cout << "Warning: Student " << i << " answers data is missing or empty.\n";
            stuScores[i][1] = static_cast<int>(i);
            continue;
        }
        if (answers[i].size() != keys.size()) {
            std::cout << "Warning: Student " << i << " answer count does not match the key length.\n";
            stuScores[i][1] = static_cast<int>(i);
            continue;
        }

        int ptsCount = 0;
        for (size_t j = 0; j < answers[i].size(); ++j) {
            if (answers[i][j] == keys[j]) {
                ptsCount++;
            }
        }
        stuScores[i][0] = ptsCount;
        stuScores[i][1] = static_cast<int>(i); // Track index of student
    }

    // Selection Sort to sort student scores in ascending order
    for (size_t i = 0; i < stuScores.size() - 1; ++i) {
        for (size_t j = i + 1; j < stuScores.size(); ++j) {
            if (stuScores[j][0] < stuScores[i][0]) {
                std::vector<int> temp = stuScores[i];
                stuScores[i] = stuScores[j];
                stuScores[j] = temp;
            }
        }
    }

    // Display results
    std::cout << "Students sorted by increasing order of correct answers:\n";
    for (size_t a = 0; a < stuScores.size(); ++a) {
        std::cout << "Student " << stuScores[a][1] << " correct count: " << stuScores[a][0] << '\n';
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
        sortAndDisplayStudents(answers, keys);

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