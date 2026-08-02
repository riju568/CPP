#include <iostream>
#include <vector>
#include <string>
#include <set>
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
enum class SelectionMode {
    SINGLE,
    MULTIPLE
};

class ListViewSelectionManager {
private:
    std::vector<std::string> items = {
        "China", "Japan", "Korea", "India", "Malaysia", "Vietnam"
    };
    SelectionMode currentMode = SelectionMode::SINGLE;
    std::set<std::size_t> selectedIndices;
public:
    void setSelectionMode(SelectionMode mode) {
        currentMode = mode;
        selectedIndices.clear();
        std::cout << "\n[COMBOBOX UPDATED]: Selection mode set to "
                  << (currentMode == SelectionMode::SINGLE ? "SINGLE" : "MULTIPLE") << '\n';
    }

    void toggleOrSelectItem(std::size_t index) {
        if (index >= items.size()) {
            throw std::out_of_range("Selected list index is out of bounds.");
        }
        if (currentMode == SelectionMode::SINGLE) {
            selectedIndices.clear();
            selectedIndices.insert(index);
        } else {
            if (selectedIndices.count(index)) {
                selectedIndices.erase(index);
            } else {
                selectedIndices.insert(index);
            }
        }
    }
    void clearSelections() {
        selectedIndices.clear();
    }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << " Selection Mode (ComboBox): "
                  << (currentMode == SelectionMode::SINGLE ? "[SINGLE]" : "[MULTIPLE]") << '\n';
        std::cout << "----------------------------------------\n";
        std::cout << "ListView Items:\n";

        for (std::size_t i = 0; i < items.size(); ++i) {
            bool isSelected = selectedIndices.count(i) > 0;
            std::cout << " [" << (isSelected ? "*" : " ") << "] " << (i + 1) << ". " << items[i] << '\n';
        }
        std::cout << "----------------------------------------\n";
        std::cout << "Bottom Label: ";
        if (selectedIndices.empty()) {
            std::cout << "No items selected\n";
        } else {
            std::cout << "Selected items are ";
            for (std::size_t idx : selectedIndices) {
                std::cout << items[idx] << " ";
            }
            std::cout << '\n';
        }
        std::cout << "----------------------------------------\n";
    }
};

void runListViewSimulation() {
    std::cout << "   Feature 2: ComboBox & ListView\n";
    ListViewSelectionManager manager;
    bool active = true;
    while (active) {
        manager.renderInterface();
        std::cout << "Controls:\n";
        std::cout << " 1. Change Selection Mode (ComboBox)\n";
        std::cout << " 2. Select / Toggle Item in ListView (1-6)\n";
        std::cout << " 3. Clear All Selections\n";
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
                std::cout << "Choose Selection Mode (1 for SINGLE, 2 for MULTIPLE): ";
                int modeChoice = 0;
                if (std::cin >> modeChoice) {
                    if (modeChoice == 1) manager.setSelectionMode(SelectionMode::SINGLE);
                    else if (modeChoice == 2) manager.setSelectionMode(SelectionMode::MULTIPLE);
                    else std::cout << "Invalid mode choice.\n";
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 2: {
                std::cout << "Enter item index (1 - 6): ";
                std::size_t itemIdx = 0;
                if (std::cin >> itemIdx && itemIdx >= 1 && itemIdx <= 6) {
                    manager.toggleOrSelectItem(itemIdx - 1);
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid item selection index.\n";
                }
                break;
            }
            case 3:
                manager.clearSelections();
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
        std::cout << " Cross-Platform C++ Unified Program\n";
        std::cout << "1. Calculate Cylinder Area & Volume (Ex 2.2)\n";
        std::cout << "2. ComboBox & ListView Selection Mode (Ex 16.16)\n";
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
                runListViewSimulation();
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