#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>

class BabyNameRankings {
private:
    std::vector<std::unordered_map<std::string, std::string>> boysRankings;
    std::vector<std::unordered_map<std::string, std::string>> girlsRankings;

public:
    BabyNameRankings() : boysRankings(10), girlsRankings(10) {}

    void loadYearData(int year, const std::string& filepath) {
        if (year < 2001 || year > 2010) {
            throw std::out_of_range("Year range supported is 2001 to 2010.");
        }
        std::ifstream file(filepath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filepath);
        }
        int index = year - 2001;
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            std::stringstream ss(line);
            std::string rank, boy, boyCount, girl, girlCount;
            if (ss >> rank >> boy >> boyCount >> girl >> girlCount) {
                boysRankings[index][boy] = rank;
                girlsRankings[index][girl] = rank;
            }
        }
    }

    std::string getRank(int year, char gender, const std::string& name) const {
        if (year < 2001 || year > 2010) return "";
        int index = year - 2001;

        if (gender == 'M' || gender == 'm') {
            auto it = boysRankings[index].find(name);
            return (it != boysRankings[index].end()) ? it->second : "";
        } else if (gender == 'F' || gender == 'f') {
            auto it = girlsRankings[index].find(name);
            return (it != girlsRankings[index].end()) ? it->second : "";
        }
        return "";
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        BabyNameRankings rankings;
        for (int year = 2001; year <= 2010; ++year) {
            std::string filename = "babynamesranking" + std::to_string(year) + ".txt";
            try {
                rankings.loadYearData(year, filename);
            } catch (const std::exception& e) {
            }
        }

        char choice = 'Y';
        while (choice == 'Y' || choice == 'y') {
            int year = 0;
            char gender = ' ';
            std::string name;
            std::cout << "\nEnter the year (2001-2010): ";
            if (!(std::cin >> year)) throw std::runtime_error("Invalid year input.");
            std::cout << "Enter the gender (M/F): ";
            if (!(std::cin >> gender)) throw std::runtime_error("Invalid gender input.");
            std::cout << "Enter the name: ";
            if (!(std::cin >> name)) throw std::runtime_error("Invalid name input.");
            std::string rank = rankings.getRank(year, gender, name);
            if (!rank.empty()) {
                std::cout << (gender == 'M' || gender == 'm' ? "Boy" : "Girl") 
                          << " name " << name << " is ranked #" << rank << " in year " << year << '\n';
            } else {
                std::cout << "Name or data not found for the given input.\n";
            }

            std::cout << "\nEnter another inquiry? (Y/N): ";
            std::cin >> choice;
        }
        std::cout << "GoodBye\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}