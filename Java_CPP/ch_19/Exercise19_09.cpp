#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

template <typename T>
void print_vector(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& item : vec) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

template <typename T>
void sort(std::vector<T>& list) {
    if (list.empty()) return;

    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (size_t i = 0; i < list.size() - 1; ++i) {
            if (list[i + 1] < list[i]) {
                std::swap(list[i], list[i + 1]);
                swapped = true;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::vector<double> double_list = {5.0, 7.0, 1.0, 9.0, 10.0, 6.0, 2.0, 4.0, 3.0, 8.0};
        std::vector<int> integer_list = {55, 99, 66, 33, 100, 11, 77, 44, 88, 22};

        std::cout << "Before sorting Doubles: ";
        print_vector(double_list);
        sort(double_list);
        std::cout << "After generic sort:     ";
        print_vector(double_list);

        std::cout << "\nBefore sorting Integers: ";
        print_vector(integer_list);
        sort(integer_list);
        std::cout << "After generic sort:     ";
        print_vector(integer_list);
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