#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>

template <typename T>
void sort(std::vector<T>& list) {
    if (list.empty()) return;

    for (size_t i = 0; i < list.size() - 1; ++i) {
        T current_min = list[i];
        size_t current_min_index = i;

        for (size_t j = i + 1; j < list.size(); ++j) {
            if (list[j] < current_min) {
                current_min = list[j];
                current_min_index = j;
            }
        }

        if (current_min_index != i) {
            list[current_min_index] = list[i];
            list[i] = current_min;
        }
    }
}

/** Print elements of a vector */
template <typename T>
void printList(const std::vector<T>& list) {
    for (const auto& item : list) {
        std::cout << item << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::vector<int> int_array = {2, 4, 3};
        std::vector<double> double_array = {3.4, 1.3, -22.1};
        std::vector<char> char_array = {'a', 'J', 'r'};
        std::vector<std::string> str_array = {"Tom", "Dick", "Harry"};
        sort(int_array);
        sort(double_array);
        sort(char_array);
        sort(str_array);
        std::cout << "Sorted Integer objects:\n";
        printList(int_array);
        std::cout << "Sorted Double objects:\n";
        printList(double_array);
        std::cout << "Sorted Character objects:\n";
        printList(char_array);
        std::cout << "Sorted String objects:\n";
        printList(str_array);
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