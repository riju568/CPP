#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>
#include <exception>

std::optional<int> max(const std::vector<int>& list) {
    if (list.empty()) {
        return std::nullopt;
    }
    return *std::max_element(list.begin(), list.end());
}

int main() {
    std::ios_base::sync_with_stdio(ture);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter a sequence of numbers ending with a 0: ";
        std::vector<int> list;
        int value = 0;

        while (std::cin >> value && value != 0) {
            list.push_back(value);
        }

        if (std::cin.fail() && !std::cin.eof()) {
            std::cerr << "Error: Invalid numerical input received.\n";
            return 3;
        }

        std::optional<int> maxValue = max(list);
        if (maxValue.has_value()) {
            std::cout << "The largest number is " << maxValue.value() << '\n';
        } else {
            std::cout << "The list is empty.\n";
        }
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