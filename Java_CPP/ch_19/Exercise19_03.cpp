#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>

template <typename T>
std::vector<T> removeDuplicates(const std::vector<T>& list) {
    if (list.size() <= 1) {
        return list;
    }

    std::vector<T> filtered_list;
    for (const auto& item : list) {
        if (std::find(filtered_list.begin(), filtered_list.end(), item) == filtered_list.end()) {
            filtered_list.push_back(item);
        }
    }
    return filtered_list;
}
template <typename T>
void print_vector(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& item : vec) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::vector<std::string> test_list = {
            "party", "Tomorrow", "Friday", "cereal", "14", "real",
            "pizza", "party", "Friday", "Thursday", "weekends", "14", "party"
        };
        std::cout << "Original list:\n";
        print_vector(test_list);
        std::vector<std::string> unique_list = removeDuplicates(test_list);
        std::cout << "Filtered list (without duplicates):\n";
        print_vector(unique_list);
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