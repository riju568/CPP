#include <iostream>
#include <exception>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::cout << "Enter the radius and length of a cylinder: ";
        double radius = 0.0;
        double length = 0.0;
        if (!(std::cin >> radius >> length)) {
            throw std::runtime_error("Invalid non-numeric input received.");
        }
        if (radius < 0 || length < 0) {
            throw std::invalid_argument("Radius and length must be non-negative values.");
        }
        constexpr double pi = 3.14159265358979323846;
        const double area = radius * radius * pi;
        const double volume = area * length;
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "The area is " << area << '\n';
        std::cout << "The volume is " << volume << '\n';
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown fatal error occurred.\n";
        return 2;
    }

    return 0;
}