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
enum class TextColor {
    RED,
    YELLOW,
    BLACK,
    ORANGE,
    GREEN
};

class MovingTextSimulation {
private:
    std::string message = "Programming is fun";
    int positionX = 10; 
    TextColor color = TextColor::BLACK;
    const int paneWidth = 40;
    std::string getColorName() const {
        switch (color) {
            case TextColor::RED:    return "Red";
            case TextColor::YELLOW: return "Yellow";
            case TextColor::BLACK:  return "Black";
            case TextColor::ORANGE: return "Orange";
            case TextColor::GREEN:  return "Green";
            default:                return "Unknown";
        }
    }

public:
    void moveLeft() {
        if (positionX > 0) {
            positionX -= 2;
        }
    }

    void moveRight() {
        if (positionX + static_cast<int>(message.length()) < paneWidth) {
            positionX += 2;
        }
    }

    void setColor(TextColor newColor) {
        color = newColor;
    }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "      MOVING TEXT & COLOR DEMO          \n";
        std::cout << "----------------------------------------\n";
        std::cout << " Radio Buttons (Color Selection):\n ";
        std::cout << "(" << (color == TextColor::RED ? "X" : " ") << ") Red  ";
        std::cout << "(" << (color == TextColor::YELLOW ? "X" : " ") << ") Yellow  ";
        std::cout << "(" << (color == TextColor::BLACK ? "X" : " ") << ") Black  ";
        std::cout << "(" << (color == TextColor::ORANGE ? "X" : " ") << ") Orange  ";
        std::cout << "(" << (color == TextColor::GREEN ? "X" : " ") << ") Green\n";
        std::cout << "----------------------------------------\n";
        std::cout << " Center Display Box [Color: " << getColorName() << "]:\n";
        std::cout << " +----------------------------------------+\n";
        std::cout << " |" << std::string(positionX, ' ') << message;
        int rightSpace = paneWidth - positionX - static_cast<int>(message.length());
        if (rightSpace < 0) rightSpace = 0;
        std::cout << std::string(rightSpace, ' ') << "|\n";
        std::cout << " +----------------------------------------+\n";
        std::cout << " Position X: " << positionX << "\n";
        std::cout << "----------------------------------------\n";
    }
};

void runMovingTextSimulation() {
    std::cout << "   Feature 2: Text Movement & Color\n";
    MovingTextSimulation simulation;
    bool active = true;
    while (active) {
        simulation.renderInterface();
        std::cout << "Controls:\n";
        std::cout << " 1. Button [<=] Move Left\n";
        std::cout << " 2. Button [=>] Move Right\n";
        std::cout << " 3. Select RadioButton -> Red\n";
        std::cout << " 4. Select RadioButton -> Yellow\n";
        std::cout << " 5. Select RadioButton -> Black\n";
        std::cout << " 6. Select RadioButton -> Orange\n";
        std::cout << " 7. Select RadioButton -> Green\n";
        std::cout << " 8. Return to Main Menu\n";
        std::cout << "Select action (1-8): ";
        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid option input choice.");
        }

        switch (action) {
            case 1:
                simulation.moveLeft();
                break;
            case 2:
                simulation.moveRight();
                break;
            case 3:
                simulation.setColor(TextColor::RED);
                break;
            case 4:
                simulation.setColor(TextColor::YELLOW);
                break;
            case 5:
                simulation.setColor(TextColor::BLACK);
                break;
            case 6:
                simulation.setColor(TextColor::ORANGE);
                break;
            case 7:
                simulation.setColor(TextColor::GREEN);
                break;
            case 8:
                active = false;
                break;
            default:
                std::cout << "Invalid choice. Please enter a value between 1 and 8.\n";
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
        std::cout << "2. Text Movement & Color Customization (Ex 16.1)\n";
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
                runMovingTextSimulation();
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