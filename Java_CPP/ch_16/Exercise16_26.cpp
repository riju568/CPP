#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <filesystem>
#include <thread>
#include <chrono>
#include <cmath>
#include <numbers>

namespace fs = std::filesystem;
constexpr int ANIMATION_STEPS = 10;
constexpr int STEP_DELAY_MS = 500;
void runCylinderCalculator() {
    std::cout << "   Feature 1: Cylinder Calculator\n";
    std::cout << "Enter the radius and length of a cylinder: ";
    double radius = 0.0;
    double length = 0.0;
    if (!(std::cin >> radius >> length)) {
        std::cin.clear(); // Reset error state flags
        std::cin.ignore(10000, '\n'); // Flush input stream buffer
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
class FlagSimulation {
private:
    fs::path imagePath;
    fs::path audioPath;

public:
    FlagSimulation() {
        fs::path baseDir = "resources";
        imagePath = baseDir / "images" / "us.gif";
        audioPath = baseDir / "audio" / "anthem" / "anthem2.mp3";
    }

    void execute() const {
        std::cout << "   Feature 2: Flag Simulation\n";
        std::cout << "Checking media assets...\n";
        std::cout << " -> Image Path: " << fs::absolute(imagePath).string() << '\n';
        std::cout << " -> Audio Path: " << fs::absolute(audioPath).string() << '\n';
        bool imageExists = fs::exists(imagePath);
        bool audioExists = fs::exists(audioPath);
        if (!imageExists) {
            std::cout << " [Warning] Image file not found on disk. Proceeding with simulation mock.\n";
        }
        if (!audioExists) {
            std::cout << " [Warning] Audio file not found on disk. Proceeding with simulation mock.\n";
        }

        std::cout << "\n[AUDIO PLAYBACK STARTED]: National Anthem is playing...\n";
        std::cout << "Raising flag from Y=200 to Y=0...\n\n";
        for (int i = 0; i <= ANIMATION_STEPS; ++i) {
            int currentY = 200 - (i * (200 / ANIMATION_STEPS));
            std::cout << "Frame " << (i + 1) << "/" << (ANIMATION_STEPS + 1)  << " | Flag Height position Y: " << currentY << "px  ";
            std::cout << "|";
            for (int j = 0; j < (200 - currentY) / 10; ++j) {
                std::cout << "=";
            }
            std::cout << "[FLAG]\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(STEP_DELAY_MS));
        }

        std::cout << "\nFlag reached the top! Simulation complete.\n";
        std::cout << "[AUDIO PLAYBACK STOPPED]\n";
    }
};

void runFlagSimulation() {
    FlagSimulation sim;
    sim.execute();
}
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::cout << " C++ Unified Program\n";
        std::cout << "1. Calculate Cylinder Area & Volume (Ex 2.2)\n";
        std::cout << "2. Simulate Raising Flag & Anthem (Ex 16.26)\n";
        std::cout << "Enter option (1 or 2): ";
        int choice = 0;
        if (!(std::cin >> choice)) {
            throw std::invalid_argument("Invalid menu selection.");
        }

        switch (choice) {
            case 1:
                runCylinderCalculator();
                break;
            case 2:
                runFlagSimulation();
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