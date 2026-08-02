#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <numbers>
#include <algorithm>
#include <bitset>
#include <cctype>


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

class NumberConverterSimulation {
private:
    std::string decimalText = "0";
    std::string hexText = "0";
    std::string binaryText = "0";

    // Converts a standard 32-bit integer to an unpadded binary string
    static std::string toBinaryString(int value) {
        if (value == 0) return "0";
        std::string b = std::bitset<32>(value).to_string();
        std::size_t firstOne = b.find_first_not_of('0');
        return (firstOne != std::string::npos) ? b.substr(firstOne) : "0";
    }
    static std::string toHexString(int value) {
        std::ostringstream ss;
        ss << std::hex << value;
        return ss.str();
    }

public:
    void updateFromDecimal(const std::string& decInput) {
        int val = std::stoi(decInput, nullptr, 10);
        decimalText = std::to_string(val);
        hexText = toHexString(val);
        binaryText = toBinaryString(val);
    }

    void updateFromHex(const std::string& hexInput) {
        int val = std::stoi(hexInput, nullptr, 16);
        decimalText = std::to_string(val);
        hexText = toHexString(val);
        binaryText = toBinaryString(val);
    }

    void updateFromBinary(const std::string& binInput) {
        int val = std::stoi(binInput, nullptr, 2);
        decimalText = std::to_string(val);
        hexText = toHexString(val);
        binaryText = toBinaryString(val);
    }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "       RADIX NUMBER CONVERTER DEMO       \n";
        std::cout << "----------------------------------------\n";
        std::cout << "  Decimal Field : [" << std::setw(16) << std::right << decimalText << "]\n";
        std::cout << "  Hex Field     : [" << std::setw(16) << std::right << hexText << "]\n";
        std::cout << "  Binary Field  : [" << std::setw(16) << std::right << binaryText << "]\n";
        std::cout << "----------------------------------------\n";
    }
};

void runNumberConverterSimulation() {
    std::cout << "   Feature 2: Base Number Converter\n";
    NumberConverterSimulation converter;
    bool active = true;

    while (active) {
        converter.renderInterface();
        std::cout << "Controls (Simulating KeyCode.ENTER Events):\n";
        std::cout << " 1. Enter Value in Decimal Field\n";
        std::cout << " 2. Enter Value in Hex Field\n";
        std::cout << " 3. Enter Value in Binary Field\n";
        std::cout << " 4. Return to Main Menu\n";
        std::cout << "Select action (1-4): ";

        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid menu selection option.");
        }

        switch (action) {
            case 1: {
                std::cout << "Enter Decimal integer value: ";
                std::string input;
                std::cin >> input;
                try {
                    converter.updateFromDecimal(input);
                } catch (const std::exception&) {
                    std::cout << "\n[Error]: Invalid decimal character or integer overflow.\n";
                }
                break;
            }
            case 2: {
                std::cout << "Enter Hexadecimal string value: ";
                std::string input;
                std::cin >> input;
                try {
                    converter.updateFromHex(input);
                } catch (const std::exception&) {
                    std::cout << "\n[Error]: Invalid hexadecimal digit format.\n";
                }
                break;
            }
            case 3: {
                std::cout << "Enter Binary string value: ";
                std::string input;
                std::cin >> input;
                try {
                    converter.updateFromBinary(input);
                } catch (const std::exception&) {
                    std::cout << "\n[Error]: Invalid binary format (use 0s and 1s only).\n";
                }
                break;
            }
            case 4:
                active = false;
                break;
            default:
                std::cout << "Invalid choice. Please enter 1, 2, 3, or 4.\n";
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
        std::cout << "2. Radix Number Converter (Ex 16.5)\n";
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
                runNumberConverterSimulation();
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