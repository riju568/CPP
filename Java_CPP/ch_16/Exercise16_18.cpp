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

class CustomFanSimulation {
private:
    double startAngle = 30.0;
    double increment = 5.0;
    double speedRate = 10.0;
    bool isRunning = true;

public:
    void move() {
        if (isRunning) {
            startAngle += (increment * (speedRate / 10.0));
            startAngle = std::fmod(startAngle, 360.0);
            if (startAngle < 0.0) startAngle += 360.0;
        }
    }

    void pause() {
        isRunning = false;
        std::cout << "\n[FAN PAUSED]: Animation halted.\n";
    }

    void resume() {
        isRunning = true;
        std::cout << "\n[FAN RESUMED]: Animation running.\n";
    }

    void reverse() {
        increment = -increment;
        std::cout << "\n[FAN REVERSED]: Rotation direction flipped.\n";
    }

    void setSpeedRate(double rate) {
        speedRate = std::clamp(rate, 0.0, 20.0);
        std::cout << "\n[SPEED SLIDER UPDATED]: Speed set to " << speedRate << " (Max: 20.0)\n";
    }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "         FAN SIMULATION STATE           \n";
        std::cout << "----------------------------------------\n";
        std::cout << "Status: " << (isRunning ? "RUNNING" : "PAUSED") << '\n';
        std::cout << "Direction: " << (increment > 0 ? "Clockwise (+)" : "Counter-Clockwise (-)") << '\n';
        std::cout << "Base Start Angle: " << std::fixed << std::setprecision(1) << startAngle << "°\n";
        
        // Print calculated angles for 4 fan blades (90 degrees apart)
        std::cout << "Blade Angles (4-Blades): ";
        for (int i = 0; i < 4; ++i) {
            double bladeAngle = std::fmod(startAngle + (i * 90.0), 360.0);
            std::cout << "[" << std::setw(5) << bladeAngle << "°] ";
        }
        std::cout << "\nSpeed Slider Value: " << speedRate << " / 20.0\n";
        std::cout << "----------------------------------------\n";
    }
};

void runFanSimulation() {
    std::cout << "   Feature 2: Running Fan Simulation\n";

    CustomFanSimulation fan;
    bool active = true;

    while (active) {
        fan.renderInterface();
        std::cout << "Controls:\n";
        std::cout << " 1. [Step Animation] (Advance fan frame)\n";
        std::cout << " 2. [Pause]\n";
        std::cout << " 3. [Resume]\n";
        std::cout << " 4. [Reverse]\n";
        std::cout << " 5. Adjust Speed Slider (0.0 - 20.0)\n";
        std::cout << " 6. Return to Main Menu\n";
        std::cout << "Select action (1-6): ";

        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid option input for fan controls.");
        }

        switch (action) {
            case 1:
                fan.move();
                break;
            case 2:
                fan.pause();
                break;
            case 3:
                fan.resume();
                break;
            case 4:
                fan.reverse();
                break;
            case 5: {
                std::cout << "Enter speed value (0.0 - 20.0): ";
                double spd = 0.0;
                if (std::cin >> spd) {
                    fan.setSpeedRate(spd);
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid speed value entered.\n";
                }
                break;
            }
            case 6:
                active = false;
                break;
            default:
                std::cout << "Invalid choice. Please choose 1 to 6.\n";
                break;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
        std::cout << " C++ Unified Program\n";
        std::cout << "1. Calculate Cylinder Area & Volume (Ex 2.2)\n";
        std::cout << "2. Running Fan & Speed Controls (Ex 16.18)\n";
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
                runFanSimulation();
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