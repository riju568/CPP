#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>
#include <exception>

struct Circle {
    double centerX;
    double centerY;
    double radius;
};

double findDistanceFromCenters(const Circle& c1, const Circle& c2) {
    return std::sqrt(std::pow(c1.centerX - c2.centerX, 2.0) + std::pow(c1.centerY - c2.centerY, 2.0));
}

int main() {
    try {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> distX(10.0, 385.0);
        std::uniform_real_distribution<double> distY(10.0, 385.0);

        Circle c1{distX(gen), distY(gen), 15.0};
        Circle c2{distX(gen), distY(gen), 15.0};

        double distance = findDistanceFromCenters(c1, c2);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Circle 1 Center: (" << c1.centerX << ", " << c1.centerY << ")\n";
        std::cout << "Circle 2 Center: (" << c2.centerX << ", " << c2.centerY << ")\n";
        std::cout << "Distance between centers: " << distance << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception.\n";
        return 2;
    }
    return 0;
}