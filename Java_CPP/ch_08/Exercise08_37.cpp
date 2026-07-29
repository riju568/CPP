#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <exception>

/**
 * 8.37 (Guess the capitals) Write a program that repeatedly
 * prompts the user to enter a capital for a state. Upon
 * receiving the user input, the program reports whether
 * the answer is correct. Assume that 50 states and their
 * capitals are stored in a two-dimensional array, as shown
 * in Figure 8.10. The program prompts the user to answer all
 * states� capitals and displays the total correct count.
 * The user�s answer is not case-sensitive.
 */

bool equalsIgnoreCase(const std::string& str1, const std::string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    return std::equal(str1.begin(), str1.end(), str2.begin(), [](char c1, char c2) {
        return std::tolower(static_cast<unsigned char>(c1)) == std::tolower(static_cast<unsigned char>(c2));
    });
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<std::string>> statesAndTheirCapitals = {
            {"Alabama", "Montgomery"}, {"Alaska", "Juneau"}, {"Arizona", "Phoenix"},
            {"Arkansas", "Little Rock"}, {"California", "Sacramento"},
            {"Colorado", "Denver"}, {"Connecticut", "Hartford"},
            {"Delaware", "Dover"}, {"Florida", "Tallahassee"},
            {"Georgia", "Atlanta"}, {"Hawaii", "Honolulu"}, {"Idaho", "Boise"},
            {"Illinois", "Springfield"}, {"Indiana", "Indianapolis"},
            {"Iowa", "Des Moines"}, {"Kansas", "Topeka"}, {"Kentucky", "Frankfort"},
            {"Louisiana", "Baton Rouge"}, {"Maine", "Augusta"},
            {"Maryland", "Annapolis"}, {"Massachusetts", "Boston"},
            {"Michigan", "Lansing"}, {"Minnesota", "Saint Paul"},
            {"Mississippi", "Jackson"}, {"Missouri", "Jefferson City"},
            {"Montana", "Helena"}, {"Nebraska", "Lincoln"},
            {"Nevada", "Carson City"}, {"New Hampshire", "Concord"},
            {"New Jersey", "Trenton"}, {"New Mexico", "Santa Fe"},
            {"New York", "Albany"}, {"North Carolina", "Raleigh"},
            {"North Dakota", "Bismarck"}, {"Ohio", "Columbus"},
            {"Oklahoma", "Oklahoma City"}, {"Oregon", "Salem"},
            {"Pennsylvania", "Harrisburg"}, {"Rhode Island", "Providence"},
            {"South Carolina", "Columbia"}, {"South Dakota", "Pierre"},
            {"Tennessee", "Nashville"}, {"Texas", "Austin"},
            {"Utah", "Salt Lake City"}, {"Vermont", "Montpelier"},
            {"Virginia", "Richmond"}, {"Washington", "Olympia"},
            {"West Virginia", "Charleston"}, {"Wisconsin", "Madison"},
            {"Wyoming", "Cheyenne"}
        };

        int correctCount = 0;
        for (size_t i = 0; i < statesAndTheirCapitals.size(); ++i) {
            std::cout << "What is the capital of " << statesAndTheirCapitals[i][0] << "? ";
            std::string checkAnswer;
            if (!std::getline(std::cin, checkAnswer)) {
                break;
            }
            if (equalsIgnoreCase(statesAndTheirCapitals[i][1], trim(checkAnswer))) {
                std::cout << "Your answer is correct\n";
                correctCount++;
            } else {
                std::cout << "The correct answer should be " << statesAndTheirCapitals[i][1] << '\n';
            }
        }
        std::cout << "\nThe total correct count is " << correctCount 
                  << " out of " << statesAndTheirCapitals.size() << '\n';

        return EXIT_SUCCESS;
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