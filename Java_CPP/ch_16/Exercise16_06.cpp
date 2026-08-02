#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <iomanip>
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

enum class TextAlignment {
    LEFT,
    CENTER,
    RIGHT
};

class TextFieldSimulation {
private:
    std::string textValue = "JavaFX TextField";
    TextAlignment alignment = TextAlignment::RIGHT;
    int prefColumnSize = 13;

public:
    void setTextValue(const std::string& text) {
        textValue = text;
    }

    void setAlignment(TextAlignment align) {
        alignment = align;
    }

    void setPrefColumnSize(int cols) {
        if (cols <= 0) {
            throw std::out_of_range("Column size must be a positive integer.");
        }
        prefColumnSize = cols;
    }

    int getPrefColumnSize() const {
        return prefColumnSize;
    }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "        TEXTFIELD PROPERTIES DEMO       \n";
        std::cout << "----------------------------------------\n";
        std::cout << " Text Field: [";
        std::string displayText = textValue;
        if (static_cast<int>(displayText.length()) > prefColumnSize) {
            displayText = displayText.substr(0, prefColumnSize);
        }

        int padding = prefColumnSize - static_cast<int>(displayText.length());
        if (padding < 0) padding = 0;

        if (alignment == TextAlignment::LEFT) {
            std::cout << displayText << std::string(padding, ' ');
        } else if (alignment == TextAlignment::RIGHT) {
            std::cout << std::string(padding, ' ') << displayText;
        } else { 
            int leftPad = padding / 2;
            int rightPad = padding - leftPad;
            std::cout << std::string(leftPad, ' ') << displayText << std::string(rightPad, ' ');
        }
        std::cout << "]\n";
        std::cout << "----------------------------------------\n";
        std::cout << " Radio Buttons (Alignment): ";
        std::cout << "(" << (alignment == TextAlignment::LEFT ? "X" : " ") << ") Left  ";
        std::cout << "(" << (alignment == TextAlignment::CENTER ? "X" : " ") << ") Center  ";
        std::cout << "(" << (alignment == TextAlignment::RIGHT ? "X" : " ") << ") Right\n";
        std::cout << " Column Size Text Field: [" << prefColumnSize << "]\n";
        std::cout << "----------------------------------------\n";
    }
};

void runTextFieldSimulation() {
    std::cout << "   Feature 2: TextField Properties\n";
    TextFieldSimulation textField;
    bool active = true;

    while (active) {
        textField.renderInterface();
        std::cout << "Controls:\n";
        std::cout << " 1. Change Text Content\n";
        std::cout << " 2. Set Alignment -> Left\n";
        std::cout << " 3. Set Alignment -> Center\n";
        std::cout << " 4. Set Alignment -> Right\n";
        std::cout << " 5. Change Column Size (PrefColumnCount)\n";
        std::cout << " 6. Return to Main Menu\n";
        std::cout << "Select action (1-6): ";

        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid menu selection option.");
        }

        switch (action) {
            case 1: {
                std::cout << "Enter new text field value: ";
                std::cin.ignore(10000, '\n');
                std::string input;
                std::getline(std::cin, input);
                textField.setTextValue(input);
                break;
            }
            case 2:
                textField.setAlignment(TextAlignment::LEFT);
                break;
            case 3:
                textField.setAlignment(TextAlignment::CENTER);
                break;
            case 4:
                textField.setAlignment(TextAlignment::RIGHT);
                break;
            case 5: {
                std::cout << "Enter column size (e.g., 3, 13, 20): ";
                int cols = 0;
                if (std::cin >> cols) {
                    try {
                        textField.setPrefColumnSize(cols);
                    } catch (const std::exception& e) {
                        std::cerr << "[Error]: " << e.what() << '\n';
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid column size input.\n";
                }
                break;
            }
            case 6:
                active = false;
                break;
            default:
                std::cout << "Invalid choice. Please enter a value between 1 and 6.\n";
                break;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << " Cross-Platform C++ Unified Program\n";
        std::cout << "1. Calculate Cylinder Area & Volume (Ex 2.2)\n";
        std::cout << "2. TextField Properties Simulation (Ex 16.6)\n";
        std::cout << "Enter choice (1 or 2): ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            throw std::invalid_argument("Invalid main menu option.");
        }

        switch (choice) {
            case 1:
                runCylinderCalculator();
                break;
            case 2:
                runTextFieldSimulation();
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