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


enum class AudioState {
    STOPPED,
    PLAYING_ONCE,
    LOOPING
};

class AudioPlayerSimulation {
private:
    fs::path audioPath;
    AudioState currentState = AudioState::STOPPED;

public:
    AudioPlayerSimulation() {
        fs::path baseDir = "resources";
        audioPath = baseDir / "audio" / "anthem" / "anthem2.mp3";
    }

    void playOnce() {
        currentState = AudioState::PLAYING_ONCE;
        std::cout << "\n[AUDIO PLAYING]: Playing audio file once...\n";
    }

    void loopAudio() {
        currentState = AudioState::LOOPING;
        std::cout << "\n[AUDIO LOOPING]: Continuously looping audio file...\n";
    }

    void stopAudio() {
        currentState = AudioState::STOPPED;
        std::cout << "\n[AUDIO STOPPED]: Audio playback stopped.\n";
    }

    void renderStatus() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << "Audio File Path: " << fs::absolute(audioPath).string() << '\n';
        std::cout << "File Present: " << (fs::exists(audioPath) ? "Yes" : "No (Simulation Mode)") << '\n';
        std::cout << "Current State: ";
        switch (currentState) {
            case AudioState::PLAYING_ONCE:
                std::cout << "PLAYING (Once)\n";
                break;
            case AudioState::LOOPING:
                std::cout << "LOOPING (Indefinitely)\n";
                break;
            case AudioState::STOPPED:
                std::cout << "STOPPED\n";
                break;
        }
        std::cout << "----------------------------------------\n";
    }
};
void runAudioPlayerSimulation() {
    std::cout << "\n========================================\n";
    std::cout << "   Feature 2: Audio Player Simulation\n";
    AudioPlayerSimulation player;
    bool active = true;
    while (active) {
        player.renderStatus();
        std::cout << "Controls:\n";
        std::cout << " 1. [Play] (Play once)\n";
        std::cout << " 2. [Loop] (Play repeatedly)\n";
        std::cout << " 3. [Stop] (Stop audio)\n";
        std::cout << " 4. Return to Main Menu\n";
        std::cout << "Select action (1-4): ";
        int action = 0;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw std::invalid_argument("Invalid input received for audio control.");
        }

        switch (action) {
            case 1:
                player.playOnce();
                break;
            case 2:
                player.loopAudio();
                break;
            case 3:
                player.stopAudio();
                break;
            case 4:
                player.stopAudio();
                active = false;
                break;
            default:
                std::cout << "Invalid choice. Please choose 1, 2, 3, or 4.\n";
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
        std::cout << "2. Play, Loop, and Stop Audio Simulation (Ex 16.22)\n";
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
                runAudioPlayerSimulation();
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