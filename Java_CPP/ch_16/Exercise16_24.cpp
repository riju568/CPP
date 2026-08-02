#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <filesystem>
#include <thread>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <numbers>

namespace fs = std::filesystem;
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
class MediaPlayerSimulation {
private:
    fs::path mediaPath;
    bool isPlaying = false;
    double volume = 50.0;
    long currentTimeSeconds = 238;
    long totalDurationSeconds = 303

public:
    MediaPlayerSimulation() {
        fs::path baseDir = "resources";
        mediaPath = baseDir / "videos" / "sample.mp4";
    }
    static std::string formatTime(long seconds) {
        long hour = (seconds / 3600) % 24;
        long minute = (seconds / 60) % 60;
        long second = seconds % 60;

        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << hour << ":"
            << std::setfill('0') << std::setw(2) << minute << ":"
            << std::setfill('0') << std::setw(2) << second;
        return oss.str();
    }

    void togglePlayPause() {
        isPlaying = !isPlaying;
        std::cout << "State changed: " << (isPlaying ? "PLAYING [||]" : "PAUSED [>]") << '\n';
    }

    void setVolume(double newVolume) {
        volume = std::clamp(newVolume, 0.0, 100.0);
        std::cout << "Volume set to: " << volume << "%\n";
    }

    void seekToPercentage(double percentage) {
        percentage = std::clamp(percentage, 0.0, 100.0);
        currentTimeSeconds = static_cast<long>((percentage / 100.0) * totalDurationSeconds);
        std::cout << "Seeked to (" << percentage << "%): " << formatTime(currentTimeSeconds) << '\n';
    }

    void renderControlInterface() const {
        std::cout << "\n--------------------------------------------------\n";
        std::cout << "Media File: " << fs::absolute(mediaPath).string() << '\n';
        std::cout << "Status: " << (isPlaying ? "PLAYING [||]" : "PAUSED [>]") << '\n';
        std::cout << "Time: " << formatTime(currentTimeSeconds) << " / " << formatTime(totalDurationSeconds) << '\n';
        double progress = (static_cast<double>(currentTimeSeconds) / totalDurationSeconds) * 100.0;
        std::cout << "Progress Slider [" << std::fixed << std::setprecision(1) << progress << "%]: [";
        int barWidth = 20;
        int pos = static_cast<int>((progress / 100.0) * barWidth);
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << "O";
            else std::cout << "-";
        }
        std::cout << "]\n";
        std::cout << "Volume Level: " << volume << "%\n";
        std::cout << "--------------------------------------------------\n";
    }
};

void runMediaPlayerSimulation() {
    std::cout << "   Feature 2: Media Player Simulation\n";
    MediaPlayerSimulation player;
    bool active = true;
    while (active) {
        player.renderControlInterface();
        std::cout << "Controls:\n";
        std::cout << " 1. Toggle Play/Pause\n";
        std::cout << " 2. Seek Position (%)\n";
        std::cout << " 3. Adjust Volume\n";
        std::cout << " 4. Return to Main Menu\n";
        std::cout << "Select action: ";
        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid player control input.");
        }

        switch (action) {
            case 1:
                player.togglePlayPause();
                break;
            case 2: {
                std::cout << "Enter target playback position (0 - 100%): ";
                double pct = 0.0;
                if (std::cin >> pct) player.seekToPercentage(pct);
                break;
            }
            case 3: {
                std::cout << "Enter volume level (0 - 100): ";
                double vol = 0.0;
                if (std::cin >> vol) player.setVolume(vol);
                break;
            }
            case 4:
                active = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(ture);
    std::cin.tie(nullptr);
    try {
        std::cout << " C++ Unified Program\n";
        std::cout << "1. Calculate Cylinder Area & Volume (Ex 2.2)\n";
        std::cout << "2. Simulate Media Player & Sliders (Ex 16.24)\n";
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
                runMediaPlayerSimulation();
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