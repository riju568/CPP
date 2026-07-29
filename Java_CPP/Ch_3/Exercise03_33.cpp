#include <iostream>
#include <cmath>
#include <stdexcept>

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        double weightP1 = 0.0;
        double p1 = 0.0;
        double weightP2 = 0.0;
        double p2 = 0.0;

        std::cout << "Enter weight and price for package 1: ";
        if (!(std::cin >> weightP1 >> p1)) {
            throw std::runtime_error("Please enter valid numeric values matching the prompt.");
        }

        std::cout << "Enter weight and price for package 2: ";
        if (!(std::cin >> weightP2 >> p2)) {
            throw std::runtime_error("Please enter valid numeric values matching the prompt.");
        }
        if (weightP1 <= 0.0 || weightP2 <= 0.0 || p1 <= 0.0 || p2 <= 0.0) {
            std::cout << "Weight and price must be positive numbers.\n";
            return 0;
        }
        double pricePerUnit1 = p1 / weightP1;
        double pricePerUnit2 = p2 / weightP2;
        if (std::abs(pricePerUnit1 - pricePerUnit2) < 1E-5) {
            std::cout << "Both packages have the same price.\n";
        } else if (pricePerUnit1 < pricePerUnit2) {
            std::cout << "Package 1 has a better price.\n";
        } else {
            std::cout << "Package 2 has a better price.\n";
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}