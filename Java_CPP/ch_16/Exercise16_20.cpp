#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <iomanip>
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

class StopwatchTime {
private:
    int totalSeconds = 0;

public:
    void increase() {
        totalSeconds++;
    }

    void reset() {
        totalSeconds = 0;
    }

    int getSecond() const {
        return totalSeconds % 60;
    }

    int getMinute() const {
        return (totalSeconds / 60) % 60;
    }

    int getHour() const {
        return totalSeconds / 3600;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << getHour() << ":"
            << std::setfill('0') << std::setw(2) << getMinute() << ":"
            << std::setfill('0') << std::setw(2) << getSecond();
        return oss.str();
    }
};

enum class StopwatchState {
    START,
    PAUSE,
    RESUME
};

class StopwatchSimulation {
private:
    StopwatchTime time;
    StopwatchState state = StopwatchState::START;

public:
    void handleStartPauseResume() {
        switch (state) {
            case StopwatchState::START:
                state = StopwatchState::PAUSE;
                time.increase(); // Simulate time passage
                std::cout << "\n[STOPWATCH RUNNING]: Timer started.\n";
                break;
            case StopwatchState::PAUSE:
                state = StopwatchState::RESUME;
                std::cout << "\n[STOPWATCH PAUSED]: Timer paused.\n";
                break;
            case StopwatchState::RESUME:
                state = StopwatchState::PAUSE;
                time.increase(); // Resume time passage
                std::cout << "\n[STOPWATCH RESUMED]: Timer running again.\n";
                break;
        }
    }

    void handleClear() {
        time.reset();
        state = StopwatchState::START;
        std::cout << "\n[STOPWATCH CLEARED]: Count reset to 00:00:00.\n";
    }

    std::string getPrimaryButtonLabel() const {
        switch (state) {
            case StopwatchState::START:  return "Start";
            case StopwatchState::PAUSE:  return "Pause";
            case StopwatchState::RESUME: return "Resume";
        }
        return "Start";
    }

    void renderInterface() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "         STOPWATCH: " << time.toString() << '\n';
        std::cout << "----------------------------------------\n";
    }
};

void runStopwatchSimulation() {
    std::cout << "   Feature 2: Count-up Stopwatch\n";
    StopwatchSimulation stopwatch;
    bool active = true;

    while (active) {
        stopwatch.renderInterface();
        std::cout << "Controls:\n";
        std::cout << " 1. [" << stopwatch.getPrimaryButtonLabel() << "] Button\n";
        std::cout << " 2. [Clear] Button\n";
        std::cout << " 3. Return to Main Menu\n";
        std::cout << "Select action (1-3): ";
        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid menu selection.");
        }

        switch (action) {
            case 1:
                stopwatch.handleStartPauseResume();
                break;
            case 2:
                stopwatch.handleClear();
                break;
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
        std::cout << "2. Count-up Stopwatch Simulation (Ex 16.20)\n";
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
                runStopwatchSimulation();
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