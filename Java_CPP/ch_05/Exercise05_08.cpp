#include <iostream>
#include <string>
#include <limits>
#include <exception>

/**
 * 5.8 (Find the highest score) Prompts the user to enter the number of students 
 * and each student's name and score, displaying the highest-scoring student.
 */
int main() {
    std::ios_base::sync_with_stdio(true);

    try {
        std::cout << "Enter the number of students: ";
        int numberOfStudents = 0;

        if (!(std::cin >> numberOfStudents)) {
            std::cerr << "Error: Invalid input for total number of students.\n";
            return 1;
        }

        if (numberOfStudents <= 0) {
            std::cout << "Error: The number of students must be greater than 0.\n";
            return 0;
        }

        std::string highestScoreName = "";
        double highScore = -std::numeric_limits<double>::infinity();

        int i = 1;
        while (i <= numberOfStudents) {
            std::cout << "Enter student " << i << "'s name: ";
            std::string name;
            if (!(std::cin >> name)) {
                std::cerr << "Error reading student name.\n";
                return 1;
            }

            std::cout << "Enter " << name << "'s score: ";
            double score = 0.0;
            if (!(std::cin >> score)) {
                std::cout << "Error: Invalid numeric input for score. Please re-enter this student's details.\n\n";
                std::cin.clear(); // Reset cin failure state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear stream buffer
                continue; // Retry current student without incrementing i
            }

            if (score > highScore) {
                highScore = score;
                highestScoreName = name;
            }

            ++i; 
        }

        std::cout << "\nThe highest scoring student was " << highestScoreName 
                  << " with a score of " << highScore << '\n';

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}