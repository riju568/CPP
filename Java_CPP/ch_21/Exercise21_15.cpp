#include <iostream>
#include <unordered_set>
#include <random>
#include <exception>

int getRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::unordered_set<int> previousGuesses;
        int number1 = getRandomNumber(0, 9);
        int number2 = getRandomNumber(0, 9);
        int correctAnswer = number1 + number2;
        std::cout << "What is " << number1 << " + " << number2 << "? ";
        int answer = 0;
        while (true) {
            if (!(std::cin >> answer)) {
                throw std::runtime_error("Invalid non-integer input entered.");
            }

            if (answer == correctAnswer) {
                std::cout << "You got it!\n";
                break;
            }

            if (previousGuesses.find(answer) != previousGuesses.end()) {
                std::cout << "You've already entered " << answer << "\n";
            } else {
                previousGuesses.insert(answer);
                std::cout << "Wrong answer. ";
            }

            std::cout << "Try again. What is " << number1 << " + " << number2 << "? ";
        }

    } catch (const std::exception& e) {
        std::cerr << "\nException caught: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "\nAn unknown fatal error occurred.\n";
        return 2;
    }

    return 0;
}