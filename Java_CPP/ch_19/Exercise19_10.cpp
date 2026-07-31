#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
template <typename T>
T max(const std::vector<T>& list) {
    if (list.empty()) {
        throw std::invalid_argument("Error: max() function requires a non-empty vector.");
    }
    T max_val = list[0];
    for (size_t i = 1; i < list.size(); ++i) {
        if (max_val < list[i]) {
            max_val = list[i];
        }
    }
    return max_val;
}
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::vector<double> double_list = {
            4400.0, 2.2, 6.6, 4400.1, 4.4, 7.7, 1.1, 8.8, 3.3, 5.5, 1203.3, 4400.2, 4400.6, 55.2
        };
        std::vector<int> integer_list = {55, 66, 33, 11, 77, 44, 88, 22};
        std::cout << "Max value in double list:  " << max(double_list) << '\n';
        std::cout << "Max value in integer list: " << max(integer_list) << '\n';
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