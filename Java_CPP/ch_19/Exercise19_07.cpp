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
int binarySearch(std::vector<T>& list, const T& key) {
    std::cout << "Sorting the array to ensure binarySearch is supported:\n";
    std::sort(list.begin(), list.end());
    print_vector(list);

    int low_idx = 0;
    int high_idx = static_cast<int>(list.size()) - 1;

    while (high_idx >= low_idx) {
        int mid_idx = low_idx + (high_idx - low_idx) / 2; 
        if (key < list[mid_idx]) {
            high_idx = mid_idx - 1;
        } else if (list[mid_idx] < key) {
            low_idx = mid_idx + 1;
        } else {
            return mid_idx; 
        }
    }

    return -1; 
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        double search_key = 111.11;
        std::vector<double> values = {4400.1, 1203.3, 3100.0, 18700.8, 4100.6, 111.11, 2222.21, 4529.21};

        int index = binarySearch(values, search_key);
        std::cout << "Generic Binary Search found key " << search_key 
                  << " at index: " << index << " in the sorted array.\n";
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