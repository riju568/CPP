#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cctype>
#include <exception>

struct StateCapital {
    std::string state;
    std::string capital;
};

static std::string trim_and_lowercase(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    std::string trimmed = str.substr(start, end - start + 1);
    std::transform(trimmed.begin(), trimmed.end(), trimmed.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return trimmed;
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::vector<StateCapital> capitals = {
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

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(capitals.begin(), capitals.end(), g);

        int correct = 0;
        int incorrect = 0;

        while (!capitals.empty()) {
            StateCapital current = capitals.back();
            capitals.pop_back();

            std::cout << "What is the capital of " << current.state << "? ";
            std::string user_input;
            std::getline(std::cin, user_input);

            if (trim_and_lowercase(user_input) == trim_and_lowercase(current.capital)) {
                std::cout << "Your answer is correct.\n";
                correct++;
            } else {
                std::cout << "Your answer is incorrect. The correct answer is: " 
                          << current.capital << "\n";
                incorrect++;
            }

            std::cout << "Keep playing? Enter Y or N: ";
            std::string response;
            std::getline(std::cin, response);
            std::string clean_resp = trim_and_lowercase(response);
            if (clean_resp != "y" && clean_resp != "yes") {
                break;
            }
        }

        std::cout << "\nThanks for playing! Final score:\n";
        std::cout << correct << " correct.\n";
        std::cout << incorrect << " incorrect.\n";
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}