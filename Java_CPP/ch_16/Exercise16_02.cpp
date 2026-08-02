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
enum class ShapeType {
    NONE,
    CIRCLE,
    RECTANGLE,
    ELLIPSE
};

class GeometricFigureSimulation {
private:
    ShapeType selectedShape = ShapeType::NONE;
    bool isFilled = false;

public:
    void selectCircle() { selectedShape = ShapeType::CIRCLE; }
    void selectRectangle() { selectedShape = ShapeType::RECTANGLE; }
    void selectEllipse() { selectedShape = ShapeType::ELLIPSE; }
    
    void toggleFill() { isFilled = !isFilled; }
    void setFill(bool fill) { isFilled = fill; }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "     GEOMETRIC FIGURE SELECTOR DEMO     \n";
        std::cout << "----------------------------------------\n";
        
        // Canvas Rendering Section
        std::cout << " Visual Display:\n";
        switch (selectedShape) {
            case ShapeType::CIRCLE:
                if (isFilled) {
                    std::cout << "   ( Filled Circle: [●] )\n";
                } else {
                    std::cout << "   ( Outline Circle: ( ) )\n";
                }
                break;

            case ShapeType::RECTANGLE:
                if (isFilled) {
                    std::cout << "   [ Filled Rectangle: ■■■■■ ]\n";
                } else {
                    std::cout << "   [ Outline Rectangle: [___] ]\n";
                }
                break;

            case ShapeType::ELLIPSE:
                if (isFilled) {
                    std::cout << "   ( Filled Ellipse: (===) )\n";
                } else {
                    std::cout << "   ( Outline Ellipse: (...) )\n";
                }
                break;

            case ShapeType::NONE:
            default:
                std::cout << "   [ No Figure Selected ]\n";
                break;
        }

        // Toolbar State Section
        std::cout << "----------------------------------------\n";
        std::cout << " Radio Buttons (ToggleGroup): ";
        std::cout << "(" << (selectedShape == ShapeType::CIRCLE ? "X" : " ") << ") Circle  ";
        std::cout << "(" << (selectedShape == ShapeType::RECTANGLE ? "X" : " ") << ") Rectangle  ";
        std::cout << "(" << (selectedShape == ShapeType::ELLIPSE ? "X" : " ") << ") Ellipse\n";
        std::cout << " CheckBox (Fill Property)   : [" << (isFilled ? "X" : " ") << "] Fill\n";
        std::cout << "----------------------------------------\n";
    }
};

void runGeometricFigureSimulation() {
    std::cout << "   Feature 2: Geometric Figure Selector\n";
    GeometricFigureSimulation simulation;
    bool active = true;

    while (active) {
        simulation.renderInterface();
        std::cout << "Controls:\n";
        std::cout << " 1. Select RadioButton -> Circle\n";
        std::cout << " 2. Select RadioButton -> Rectangle\n";
        std::cout << " 3. Select RadioButton -> Ellipse\n";
        std::cout << " 4. Toggle CheckBox -> Fill (" << (simulation.isFilled ? "Uncheck" : "Check") << ")\n";
        std::cout << " 5. Return to Main Menu\n";
        std::cout << "Select action (1-5): ";
        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid option input choice.");
        }

        switch (action) {
            case 1:
                simulation.selectCircle();
                break;
            case 2:
                simulation.selectRectangle();
                break;
            case 3:
                simulation.selectEllipse();
                break;
            case 4:
                simulation.toggleFill();
                break;
            case 5:
                active = false;
                break;
            default:
                std::cout << "Invalid choice. Please enter a value between 1 and 5.\n";
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
        std::cout << "2. Geometric Figure Selector (Ex 16.2)\n";
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
                runGeometricFigureSimulation();
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