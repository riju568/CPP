#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <numbers>


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
class TextAreaSimulation {
private:
    std::string content = "This is a cross-platform C++ simulation of a JavaFX TextArea properties control.";
    bool isEditable = true;
    bool isWrapText = true;
    const std::size_t lineWrapWidth = 25; // Max characters per line when word-wrapping

public:
    void setEditable(bool editable) {
        isEditable = editable;
    }

    bool getEditable() const {
        return isEditable;
    }

    void setWrapText(bool wrap) {
        isWrapText = wrap;
    }

    bool getWrapText() const {
        return isWrapText;
    }

    void updateContent(const std::string& newText) {
        if (!isEditable) {
            std::cout << "\n[ERROR]: Cannot modify content! TextArea is set to Read-Only (Editable = False).\n";
            return;
        }
        content = newText;
        std::cout << "\n[SUCCESS]: TextArea content updated successfully.\n";
    }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "           TEXT AREA DISPLAY            \n";
        std::cout << "----------------------------------------\n";

        if (!isWrapText) {
            std::cout << content << '\n';
        } else {
            std::istringstream stream(content);
            std::string word;
            std::size_t currentLineLength = 0;

            while (stream >> word) {
                if (currentLineLength + word.length() + 1 > lineWrapWidth) {
                    std::cout << '\n';
                    currentLineLength = 0;
                }
                if (currentLineLength > 0) {
                    std::cout << ' ';
                    currentLineLength++;
                }
                std::cout << word;
                currentLineLength += word.length();
            }
            std::cout << '\n';
        }

        std::cout << "----------------------------------------\n";
        std::cout << "Properties Bar: [Editable: " << (isEditable ? "TRUE" : "FALSE") 
                  << "] [WrapText: " << (isWrapText ? "TRUE" : "FALSE") << "]\n";
        std::cout << "----------------------------------------\n";
    }
};

void runTextAreaSimulation() {
    std::cout << "   Feature 2: TextArea Properties\n";
    TextAreaSimulation textArea;
    bool active = true;

    while (active) {
        textArea.renderInterface();
        std::cout << "Controls:\n";
        std::cout << " 1. Toggle 'Editable' CheckBox\n";
        std::cout << " 2. Toggle 'WrapText' CheckBox\n";
        std::cout << " 3. Modify Text Content\n";
        std::cout << " 4. Return to Main Menu\n";
        std::cout << "Select action (1-4): ";

        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid option input for TextArea controls.");
        }

        switch (action) {
            case 1:
                textArea.setEditable(!textArea.getEditable());
                break;
            case 2:
                textArea.setWrapText(!textArea.getWrapText());
                break;
            case 3: {
                std::cout << "Enter new text for TextArea: ";
                std::cin.ignore(10000, '\n'); // Clear remaining newline
                std::string inputBuffer;
                std::getline(std::cin, inputBuffer);
                textArea.updateContent(inputBuffer);
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try {
        std::cout << "C++ Unified Program\n";
        std::cout << "1. Calculate Cylinder Area & Volume (Ex 2.2)\n";
        std::cout << "2. TextArea Properties Simulation (Ex 16.12)\n";
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
                runTextAreaSimulation();
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