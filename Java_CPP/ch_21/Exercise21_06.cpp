#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <exception>

void processAndPrintMaxOccurrences(const std::map<int, int>& counts) {
    if (counts.empty()) {
        std::cout << "No numbers were entered.\n";
        return;
    }

    int maxCount = 0;
    for (const auto& entry : counts) {
        maxCount = std::max(maxCount, entry.second);
    }

    std::cout << "The most occurring number(s):\n";
    for (const auto& entry : counts) {
        if (entry.second == maxCount) {
            std::cout << entry.first << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter space-separated integers, ending with a '0':\n";

        std::map<int, int> numberCounts;
        int input = 0;

        while (std::cin >> input) {
            if (input == 0) {
                break;
            }
            numberCounts[input]++;
        }

        if (std::cin.fail() && !std::cin.eof()) {
            throw std::runtime_error("Invalid non-integer input encountered.");
        }

        processAndPrintMaxOccurrences(numberCounts);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown fatal exception occurred.\n";
        return 2;
    }

    return 0;
}