#include <iostream>
#include <exception>
#include <memory>

class HangmanDrawing {
public:
    void draw() {
        std::cout << "Drawing Hangman components safely with zero raw pointers...\n";
    }
};

int main() {
    try {
        auto hangman = std::make_unique<HangmanDrawing>();
        hangman->draw();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception.\n";
        return 2;
    }
    return 0;
}