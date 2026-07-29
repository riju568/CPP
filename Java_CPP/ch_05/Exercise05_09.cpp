#include <iostream>
#include <string>
#include <limits>
#include <exception>

/**
 * 5.9 (Find the two highest scores) Prompts the user to enter the number of students 
 * and each student's name and score, then displays the student with the highest score 
 * and the student with the second-highest score.
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    try {
        std::cout << "Enter the number of students: ";
        int numStudents = 0;

        if (!(std::cin >> numStudents)) {
            std::cerr << "Error: Invalid input for total number of students.\n";
            return 1;
        }

        if (numStudents < 2) {
            std::cout << "Error: Please enter at least 2 students to compare highest and second-highest scores.\n";
            return 0;
        }
        std::string highName = "";
        std::string secondName = "";
        double highScore = -std::numeric_limits<double>::infinity();
        double secondHigh = -std::numeric_limits<double>::infinity();
        int i = 1;
        while (i <= numStudents) {
            std::cout << "Enter student " << i << "'s name: ";
            std::string tempName;
            if (!(std::cin >> tempName)) {
                std::cerr << "Error reading student name.\n";
                return 1;
            }

            std::cout << "Enter " << tempName << "'s score: ";
            double tempScore = 0.0;
            if (!(std::cin >> tempScore)) {
                std::cout << "Error: Invalid score entry. Please re-enter this student's information.\n\n";
                std::cin.clear(); // Reset cin error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush invalid tokens
                continue; // Retry current student without incrementing i
            }

            // Compare and update top two scores
            if (tempScore > highScore) {
                secondHigh = highScore;
                secondName = highName;
                highScore = tempScore;
                highName = tempName;
            } else if (tempScore > secondHigh) {
                secondHigh = tempScore;
                secondName = tempName;
            }

            ++i; 
        }

        // Display results
        std::cout << "\nThe top two students are:\n";
        std::cout << "Highest Score: " << highName << " (" << highScore << ")\n";
        std::cout << "Second Highest Score: " << secondName << " (" << secondHigh << ")\n";

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}