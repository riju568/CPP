#include <iostream>
#include <vector>
#include <numeric>
#include <exception>


double sum(const std::vector<double>& list) {
    return std::accumulate(list.begin(), list.end(), 0.0);
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::cout << "Enter 5 numbers: ";
        std::vector<double> list;
        list.reserve(5);

        for (int i = 0; i < 5; ++i) {
            double val = 0.0;
            if (!(std::cin >> val)) {
                std::cerr << "Error: Invalid numerical input received.\n";
                return 3;
            }
            list.push_back(val);
        }

        std::cout << "Sum = " << sum(list) << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}