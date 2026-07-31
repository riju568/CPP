#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>

template <typename T>
T max(const std::vector<std::vector<T>>& list) {
    if (list.empty() || list[0].empty()) {
        throw std::invalid_argument("Error: 2D Vector matrix cannot be empty.");
    }

    T max_value = list[0][0];
    for (size_t i = 0; i < list.size(); ++i) {
        for (size_t j = 0; j < list[i].size(); ++j) {
            if (list[i][j] > max_value) {
                max_value = list[i][j];
            }
        }
    }
    return max_value;
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::vector<std::vector<double>> values = {
            {100.1, 100.3, 555.12},
            {100.0, 100.8, 100.6},
            {65656.22, 1112.34, 99.9}
        };

        double max_val = max(values);
        std::cout << "Generic Max method for 2D array returned: " << max_val << '\n';
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