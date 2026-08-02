#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <numbers>
#include <algorithm>


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
class DistanceConverterSimulation {
private:
    std::string milesText = "0.0";
    std::string kilometerText = "0.0";
    static constexpr double CONVERSION_FACTOR = 0.6241;

public:
    void updateFromMiles(const std::string& input) {
        double miles = std::stod(input);
        if (miles < 0.0) {
            throw std::out_of_range("Distance value cannot be negative.");
        }
        double kilometer = miles / CONVERSION_FACTOR;
        std::ostringstream ssMiles, ssKilo;
        ssMiles << std::fixed << std::setprecision(4) << miles;
        ssKilo << std::fixed << std::setprecision(4) << kilometer;
        milesText = ssMiles.str();
        kilometerText = ssKilo.str();
    }
    void updateFromKilometers(const std::string& input) {
        double kilometer = std::stod(input);
        if (kilometer < 0.0) { throw std::out_of_range("Distance value cannot be negative.");}
        double miles = CONVERSION_FACTOR * kilometer;
        std::ostringstream ssMiles, ssKilo;
        ssMiles << std::fixed << std::setprecision(4) << miles;
        ssKilo << std::fixed << std::setprecision(4) << kilometer;
        milesText = ssMiles.str();
        kilometerText = ssKilo.str();
    }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "     MILES / KILOMETERS CONVERTER       \n";
        std::cout << "----------------------------------------\n";
        std::cout << "  Miles TextField      : [" << std::setw(12) << std::right << milesText << "]\n";
        std::cout << "  Kilometer TextField  : [" << std::setw(12) << std::right << kilometerText << "]\n";
        std::cout << "----------------------------------------\n";
    }
};

void runDistanceConverterSimulation() {
    std::cout << "   Feature 2: Miles/Kilometers Converter\n";
    DistanceConverterSimulation converter;
    bool active = true;
    while (active) {
        converter.renderInterface();
        std::cout << "Controls (Simulating TextField Action Event):\n";
        std::cout << " 1. Enter value in 'Mile' TextField and Press Enter\n";
        std::cout << " 2. Enter value in 'Kilometer' TextField and Press Enter\n";
        std::cout << " 3. Return to Main Menu\n";
        std::cout << "Select action (1-3): ";
        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid option input choice.");
        }
        switch (action) {
            case 1: {
                std::cout << "Enter distance in Miles: ";
                std::string input;
                std::cin >> input;
                try {
                    converter.updateFromMiles(input);
                } catch (const std::exception& e) {
                    std::cout << "\n[Error]: " << e.what() << '\n';
                }
                break;
            }
            case 2: {
                std::cout << "Enter distance in Kilometers: ";
                std::string input;
                std::cin >> input;
                try {
                    converter.updateFromKilometers(input);
                } catch (const std::exception& e) {
                    std::cout << "\n[Error]: " << e.what() << '\n';
                }
                break;
            }
            case 3:
                active = false;
                break;
            default:
                std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
                break;
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::cout << " C++ Unified Program\n";
        std::cout << "1. Calculate Cylinder Area & Volume (Ex 2.2)\n";
        std::cout << "2. Miles/Kilometers Converter (Ex 16.4)\n";
        std::cout << "Enter choice (1 or 2): ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            throw std::invalid_argument("Invalid main menu selection option.");
        }

        switch (choice) {
            case 1:
                runCylinderCalculator();
                break;
            case 2:
                runDistanceConverterSimulation();
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