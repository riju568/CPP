#include <iostream>
#include <vector>
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
class DynamicTextRenderer {
private:
    std::string textContent = "Programming is fun";
    std::vector<std::string> fontFamilies = {
        "SansSerif", "Serif", "Monospaced", "Courier New", "Arial", "Times New Roman"
    };
    std::size_t selectedFontIdx = 0;
    int fontSize = 20;
    bool isBold = false;
    bool isItalic = false;

public:
    void setFontFamily(std::size_t index) {
        if (index >= fontFamilies.size()) {
            throw std::out_of_range("Selected font index is out of bounds.");
        }
        selectedFontIdx = index;
    }

    void setFontSize(int size) {
        fontSize = std::clamp(size, 1, 100);
    }

    void toggleBold() {
        isBold = !isBold;
    }
    void toggleItalic() {
        isItalic = !isItalic;
    }
    const std::vector<std::string>& getFontFamilies() const {
        return fontFamilies;
    }
    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << " Top Bar Controls:\n";
        std::cout << "  * Font Name: [" << fontFamilies[selectedFontIdx] << "]\n";
        std::cout << "  * Font Size: [" << fontSize << "] (Range: 1-100)\n";
        std::cout << " Bottom Bar Controls:\n";
        std::cout << "  * Bold:   [" << (isBold ? "X" : " ") << "]\n";
        std::cout << "  * Italic: [" << (isItalic ? "X" : " ") << "]\n";
        std::cout << "----------------------------------------\n";
        std::cout << " Center Display Label:\n";
        std::cout << "  \"";
        if (isBold) std::cout << "**";
        if (isItalic) std::cout << "*";
        std::cout << textContent;
        if (isItalic) std::cout << "*";
        if (isBold) std::cout << "**";
        std::cout << "\" (Font: " << fontFamilies[selectedFontIdx] << ", Size: " << fontSize << "pt)\n";
        std::cout << "----------------------------------------\n";
    }
};

void runFontSelectorSimulation() {
    std::cout << "   Feature 2: Dynamic Font Selector\n";
    DynamicTextRenderer renderer;
    bool active = true;

    while (active) {
        renderer.renderInterface();
        std::cout << "Controls:\n";
        std::cout << " 1. Select Font Name (ComboBox)\n";
        std::cout << " 2. Select Font Size (1 - 100)\n";
        std::cout << " 3. Toggle Bold CheckBox\n";
        std::cout << " 4. Toggle Italic CheckBox\n";
        std::cout << " 5. Return to Main Menu\n";
        std::cout << "Select action (1-5): ";
        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid option input for font controls.");
        }
        switch (action) {
            case 1: {
                const auto& fonts = renderer.getFontFamilies();
                std::cout << "\nAvailable Fonts:\n";
                for (std::size_t i = 0; i < fonts.size(); ++i) {
                    std::cout << " " << (i + 1) << ". " << fonts[i] << '\n';
                }
                std::cout << "Select font (1-" << fonts.size() << "): ";
                std::size_t fontChoice = 0;
                if (std::cin >> fontChoice && fontChoice >= 1 && fontChoice <= fonts.size()) {
                    renderer.setFontFamily(fontChoice - 1);
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid font selection.\n";
                }
                break;
            }
            case 2: {
                std::cout << "Enter font size (1 - 100): ";
                int sizeInput = 0;
                if (std::cin >> sizeInput) {
                    renderer.setFontSize(sizeInput);
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid size input.\n";
                }
                break;
            }
            case 3:
                renderer.toggleBold();
                break;
            case 4:
                renderer.toggleItalic();
                break;
            case 5:
                active = false;
                break;
            default:
                std::cout << "Invalid choice. Please choose 1 to 5.\n";
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
        std::cout << "2. Dynamic Font & Style Controls (Ex 16.14)\n";
        std::cout << "Enter choice (1 or 2): ";
        int choice = 0;
        if (!(std::cin >> choice)) {
            throw std::invalid_argument("Invalid menu option selected.");
        }

        switch (choice) {
            case 1:
                runCylinderCalculator();
                break;
            case 2:
                runFontSelectorSimulation();
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