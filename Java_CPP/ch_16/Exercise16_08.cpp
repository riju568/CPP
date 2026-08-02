#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <numbers>
#include <iomanip>


void runCylinderCalculator() {
    std::cout << "   Feature 1: Cylinder Calculator\n";
    std::cout << "Enter the radius and length of a cylinder: ";

    double radius = 0.0;
    double length = 0.0;

    if (!(std::cin >> radius >> length)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw std::invalid_argument("Invalid or non-numeric input received.");
    }

    if (radius < 0.0 || length < 0.0) {
        throw std::out_of_range("Radius and length must be non-negative values.");
    }
    #if __cpp_lib_math_constants
        const double pi = std::numbers::pi;
    #else
        const double pi = 3.14159265358979323846;
    #endif
    const double area = radius * radius * pi;
    const double volume = area * length;
    std::cout << "The area is " << area << '\n';
    std::cout << "The volume is " << volume << '\n';
}

struct Circle {
    double x = 0.0;
    double y = 0.0;
    double radius = 0.0;
};

class CircleIntersectSimulation {
private:
    Circle c1{52.0, 60.0, 30.0};
    Circle c2{180.0, 56.0, 40.0};

public:
    void setCircle1(double x, double y, double r) {
        if (r < 0.0) throw std::out_of_range("Radius cannot be negative.");
        c1 = {x, y, r};
    }

    void setCircle2(double x, double y, double r) {
        if (r < 0.0) throw std::out_of_range("Radius cannot be negative.");
        c2 = {x, y, r};
    }

    bool doIntersect() const {
        double distance = std::hypot(c1.x - c2.x, c1.y - c2.y);
        return distance <= (c1.radius + c2.radius);
    }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "        CIRCLE INTERSECTION CHECK       \n";
        std::cout << "----------------------------------------\n";
        std::cout << " Two circles intersect? " << (doIntersect() ? "Yes" : "No") << "\n\n";
        std::cout << " Circle 1: Center(" << c1.x << ", " << c1.y << "), Radius: " << c1.radius << '\n';
        std::cout << " Circle 2: Center(" << c2.x << ", " << c2.y << "), Radius: " << c2.radius << '\n';
        std::cout << "----------------------------------------\n";
    }
};

void runCircleIntersectSimulation() {
    std::cout << "   Feature 2: Circle Intersection\n";
    CircleIntersectSimulation sim;
    bool active = true;

    while (active) {
        sim.renderInterface();
        std::cout << "Controls:\n";
        std::cout << " 1. Update Circle 1 Info (Center X, Y, Radius)\n";
        std::cout << " 2. Update Circle 2 Info (Center X, Y, Radius)\n";
        std::cout << " 3. Redraw / Re-calculate Intersection\n";
        std::cout << " 4. Return to Main Menu\n";
        std::cout << "Select action (1-4): ";

        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid option choice.");
        }

        switch (action) {
            case 1: {
                std::cout << "Enter Circle 1 Center X, Center Y, and Radius: ";
                double x, y, r;
                if (std::cin >> x >> y >> r) {
                    try {
                        sim.setCircle1(x, y, r);
                    } catch (const std::exception& e) {
                        std::cerr << "[Error]: " << e.what() << '\n';
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid numbers entered.\n";
                }
                break;
            }
            case 2: {
                std::cout << "Enter Circle 2 Center X, Center Y, and Radius: ";
                double x, y, r;
                if (std::cin >> x >> y >> r) {
                    try {
                        sim.setCircle2(x, y, r);
                    } catch (const std::exception& e) {
                        std::cerr << "[Error]: " << e.what() << '\n';
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid numbers entered.\n";
                }
                break;
            }
            case 3:
                std::cout << "\n[REDRAWING]: Recalculated intersection state.\n";
                break;
            case 4:
                active = false;
                break;
            default:
                std::cout << "Invalid choice. Please select 1, 2, 3, or 4.\n";
                break;
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "C++ Unified Program\n";
        std::cout << "1. Calculate Cylinder Area & Volume (Ex 2.2)\n";
        std::cout << "2. Circle Intersection Check (Ex 16.8)\n";
        std::cout << "Enter choice (1 or 2): ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            throw std::invalid_argument("Invalid menu selection.");
        }

        switch (choice) {
            case 1:
                runCylinderCalculator();
                break;
            case 2:
                runCircleIntersectSimulation();
                break;
            default:
                throw std::out_of_range("Choice must be 1 or 2.");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "\n[Standard Exception Catch]: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "\n[Unknown Critical Exception Encountered]\n";
        return 2;
    }

    return 0;
}