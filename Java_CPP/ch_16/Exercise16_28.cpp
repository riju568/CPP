#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <thread>
#include <chrono>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <numbers>

namespace fs = std::filesystem;

constexpr int NUMBER_OF_SLIDES = 10;
constexpr int DISPLAY_DURATION_MS = 2000;
void runCylinderCalculator() {
    std::cout << "\n--- [ Feature 1: Cylinder Calculator ] ---\n";
    std::cout << "Enter the radius and length of a cylinder: ";

    double radius = 0.0;
    double length = 0.0;

    if (!(std::cin >> radius >> length)) {
        std::cin.clear(); // Clear error state flags
        std::cin.ignore(10000, '\n'); // Clear input buffer
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

std::string readAFile(const fs::path& filePath) {
    std::cout << "Reading file: " << fs::absolute(filePath) << '\n';

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        return "[Slide file missing or unreadable: " + filePath.string() + "]\n";
    }

    std::ostringstream ss;
    ss << inputFile.rdbuf(); 
    return ss.str();
}
std::vector<std::string> loadTextToSlides() {
    std::vector<std::string> slides;
    slides.reserve(NUMBER_OF_SLIDES);
    fs::path relativeFolderPath = fs::path("resources") / "text";
    for (int i = 0; i < NUMBER_OF_SLIDES; ++i) {
        fs::path slidePath = relativeFolderPath / ("slide" + std::to_string(i) + ".txt");
        slides.push_back(readAFile(slidePath));
    }

    return slides;
}

void runTextSlideshow() {
    std::cout << "\n--- [ Feature 2: Text Slide Show ] ---\n";
    const std::vector<std::string> slides = loadTextToSlides();
    if (slides.empty()) {
        throw std::runtime_error("Failed to load slide contents.");
    }
    std::cout << "\nStarting Slideshow for 3 cycles (Press Ctrl+C to abort early)\n";
    std::size_t current = 0;
    const std::size_t totalRuns = NUMBER_OF_SLIDES * 3;
    for (std::size_t step = 0; step < totalRuns; ++step) {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "=== [ Slide " << current << " of " << NUMBER_OF_SLIDES - 1 << " ] ===\n\n";
        std::cout << slides[current] << '\n';
        std::cout << "========================================" << '\n';

        current = (current + 1) % NUMBER_OF_SLIDES;
        std::this_thread::sleep_for(std::chrono::milliseconds(DISPLAY_DURATION_MS));
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    try {
        std::cout << "Select a program feature to run:\n";
        std::cout << "1. Calculate Cylinder Area and Volume\n";
        std::cout << "2. Start Text File Slideshow\n";
        std::cout << "Enter choice (1 or 2): ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            throw std::invalid_argument("Invalid option selected.");
        }

        switch (choice) {
            case 1:
                runCylinderCalculator();
                break;
            case 2:
                runTextSlideshow();
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