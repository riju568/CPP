#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <algorithm>
#include <exception>

void loadNamesFromFile(const std::string& filename, std::set<std::string>& boyNames, std::set<std::string>& girlNames) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string rank, boy, boyCount, girl, girlCount;
        if (ss >> rank >> boy >> boyCount >> girl >> girlCount) {
            boyNames.insert(boy);
            girlNames.insert(girl);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::cout << "Enter a file name for baby name ranking: ";
        std::string fileName;
        if (!(std::cin >> fileName)) {
            throw std::runtime_error("Invalid input.");
        }
        std::set<std::string> boyNames;
        std::set<std::string> girlNames;
        loadNamesFromFile(fileName, boyNames, girlNames);
        std::set<std::string> commonNames;
        std::set_intersection(
            boyNames.begin(), boyNames.end(),
            girlNames.begin(), girlNames.end(),
            std::inserter(commonNames, commonNames.begin())
        );
        std::cout << commonNames.size() << " names used for both genders\nThey are ";
        int count = 0;
        for (const auto& name : commonNames) {
            if (count > 0 && count % 10 == 0) {
                std::cout << "\n";
            }
            std::cout << name << " ";
            count++;
        }
        std::cout << '\n';

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}