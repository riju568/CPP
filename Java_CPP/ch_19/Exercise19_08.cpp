#include <iostream>
#include <vector>
#include <random>
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
void shuffle(std::vector<T>& list) {
    if (list.empty()) return;
    std::random_device rd;
    std::mt19937 gen(rd());
    for (size_t i = list.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<size_t> dist(0, i);
        size_t j = dist(gen);
        std::swap(list[i], list[j]);
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::vector<double> double_list = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
        std::vector<int> integer_list = {11, 22, 33, 44, 55, 66, 77, 88};

        std::cout << "Before shuffling Doubles: ";
        print_vector(double_list);
        shuffle(double_list);
        std::cout << "After generic shuffle:    ";
        print_vector(double_list);

        std::cout << "\nBefore shuffling Integers: ";
        print_vector(integer_list);
        shuffle(integer_list);
        std::cout << "After generic shuffle:     ";
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