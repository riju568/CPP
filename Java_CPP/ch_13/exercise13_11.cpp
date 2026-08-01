#include <iostream>
#include <exception>
#include <stdexcept>
#include <memory>
#include <numbers> // Requirements: C++20 for std::numbers::pi

class Cylinder {
private:
    double radius_;
    double length_;

public:
    Cylinder(double radius, double length) : radius_(radius), length_(length) {
        if (radius < 0.0 || length < 0.0) {
            throw std::invalid_argument("Radius and length cannot be negative.");
        }
    }

    [[nodiscard]] double area() const noexcept {
        return radius_ * radius_ * std::numbers::pi;
    }

    [[nodiscard]] double volume() const noexcept {
        return area() * length_;
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
        std::cout << "Enter the radius and length of a cylinder: ";
        double radius = 0.0;
        double length = 0.0;
        std::cin >> radius >> length;
        auto cylinder = std::make_unique<Cylinder>(radius, length);
        std::cout << "The area is: " << cylinder->area() << '\n';
        std::cout << "The volume is: " << cylinder->volume() << '\n';
    } catch (const std::ios_base::failure &) {
        std::cerr << "Input Error: Invalid non-numeric value or stream reading failed.\n";
        return 3;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Validation Error: " << e.what() << '\n';
        return 4;
    } catch (const std::exception &e) {
        std::cerr << "Standard Exception: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred.\n";
        return 2;
    }

    return 0;
}