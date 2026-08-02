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
        std::cin.clear()
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
enum class LightState {
    OFF,
    RED,
    YELLOW,
    GREEN
};

class TrafficLightSimulation {
private:
    LightState activeState = LightState::OFF;

public:
    void setRed() { activeState = LightState::RED; }
    void setYellow() { activeState = LightState::YELLOW; }
    void setGreen() { activeState = LightState::GREEN; }
    void setOff() { activeState = LightState::OFF; }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "        TRAFFIC LIGHT SIMULATION        \n";
        std::cout << "----------------------------------------\n";
        
        // Render Simulated Graphical Traffic Light Housing Box
        std::cout << "         +-------+\n";
        std::cout << "         |  " << (activeState == LightState::RED ? "(R)" : "( )") << "  |  [RED]\n";
        std::cout << "         |  " << (activeState == LightState::YELLOW ? "(Y)" : "( )") << "  |  [YELLOW]\n";
        std::cout << "         |  " << (activeState == LightState::GREEN ? "(G)" : "( )") << "  |  [GREEN]\n";
        std::cout << "         +-------+\n";

        std::cout << "----------------------------------------\n";
        std::cout << " Radio Buttons (ToggleGroup State):\n";
        std::cout << " (" << (activeState == LightState::RED ? "X" : " ") << ") Red   ";
        std::cout << "(" << (activeState == LightState::YELLOW ? "X" : " ") << ") Yellow   ";
        std::cout << "(" << (activeState == LightState::GREEN ? "X" : " ") << ") Green   ";
        std::cout << "(" << (activeState == LightState::OFF ? "X" : " ") << ") Off\n";
        std::cout << "----------------------------------------\n";
    }
};

void runTrafficLightSimulation() {
    std::cout << "   Feature 2: Traffic Light Simulator\n";
    TrafficLightSimulation trafficLight;
    bool active = true;

    while (active) {
        trafficLight.renderInterface();
        std::cout << "Controls (Select Radio Button Toggle):\n";
        std::cout << " 1. Select RadioButton -> Red\n";
        std::cout << " 2. Select RadioButton -> Yellow\n";
        std::cout << " 3. Select RadioButton -> Green\n";
        std::cout << " 4. Turn Off All Lights\n";
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
                trafficLight.setRed();
                break;
            case 2:
                trafficLight.setYellow();
                break;
            case 3:
                trafficLight.setGreen();
                break;
            case 4:
                trafficLight.setOff();
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
        std::cout << "2. Traffic Light Simulator (Ex 16.3)\n";
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
                runTrafficLightSimulation();
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