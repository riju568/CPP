#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
template <typename T>
T max(const std::vector<T>& list) {
    if (list.empty()) {
        throw std::invalid_argument("Error: Vector cannot be empty.");
    }
    T max_value = list[0];
    for (size_t i = 1; i < list.size(); ++i) {
        if (list[i] > max_value) {
            max_value = list[i];
        }
    }
    return max_value;
}
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::vector<double> values = {4400.1, 1203.3, 3100.0, 18700.8, 4100.6};

        double max_val = max(values);
        std::cout << "Generic Max method returned: " << max_val << '\n';
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