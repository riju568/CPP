#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cctype>
#include <exception>
#include <stdexcept>

class HangmanGame {
private:
    std::vector<std::string> word_bank = {
        "abstract", "assert", "boolean", "break", "byte", "case", "catch",
        "class", "const", "continue", "default", "double", "enum",
        "protected", "public", "return", "short", "static", "super",
        "switch", "synchronized", "this", "throw", "throws", "transient",
        "void", "volatile", "while"
    };
    std::string current_word;
    std::vector<char> played_letters;
    std::vector<char> missed_letters;
    int wrong_answers;
    bool word_complete;

    void print_hangman_art(int stage) const {
        static const std::vector<std::string> stages = {
            "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
        };

        if (stage >= 0 && stage < static_cast<int>(stages.size())) {
            std::cout << stages[stage] << "\n";
        }
    }

    std::string get_display_word() const {
        std::string result;
        for (char ch : current_word) {
            if (std::find(played_letters.begin(), played_letters.end(), ch) != played_letters.end()) {
                result += ch;
            } else {
                result += '*';
            }
        }
        return result;
    }

public:
    HangmanGame() : wrong_answers(0), word_complete(false) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(word_bank.begin(), word_bank.end(), g);
    }

    void start_new_round(size_t index) {
        if (word_bank.empty()) {
            throw std::runtime_error("Word bank is empty.");
        }
        current_word = word_bank[index % word_bank.size()];
        played_letters.clear();
        missed_letters.clear();
        wrong_answers = 0;
        word_complete = false;
    }

    void play() {
        size_t word_index = 0;
        start_new_round(word_index);

        while (true) {
            std::cout << "\n----------------------------------------\n";
            print_hangman_art(wrong_answers);
            
            std::string display = get_display_word();
            std::cout << "Guess a word: " << display << "\n";
            std::cout << "Missed letters: ";
            for (char m : missed_letters) std::cout << m << " ";
            std::cout << "\n";

            if (wrong_answers >= 6) {
                std::cout << "GAME OVER! The word was: " << current_word << "\n";
                std::cout << "Press ENTER to continue to next word, or 'q' then ENTER to quit: ";
                std::string line;
                std::getline(std::cin, line);
                if (!line.empty() && (line[0] == 'q' || line[0] == 'Q')) break;
                start_new_round(++word_index);
                continue;
            }

            if (display.find('*') == std::string::npos) {
                std::cout << "You guessed it! Word: " << current_word << "\n";
                std::cout << "To continue the game, press ENTER (or 'q' to quit): ";
                std::string line;
                std::getline(std::cin, line);
                if (!line.empty() && (line[0] == 'q' || line[0] == 'Q')) break;
                start_new_round(++word_index);
                continue;
            }

            std::cout << "Enter a letter: ";
            std::string input;
            if (!(std::cin >> input)) {
                break;
            }
            std::cin.ignore(10000, '\n');

            if (input.empty()) continue;
            char guess = static_cast<char>(std::tolower(input[0]));

            if (!std::isalpha(guess)) {
                std::cout << "Please enter a valid alphabetic letter.\n";
                continue;
            }

            if (current_word.find(guess) != std::string::npos) {
                if (std::find(played_letters.begin(), played_letters.end(), guess) == played_letters.end()) {
                    played_letters.push_back(guess);
                }
            } else {
                if (std::find(missed_letters.begin(), missed_letters.end(), guess) == missed_letters.end()) {
                    missed_letters.push_back(guess);
                    wrong_answers++;
                }
            }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        HangmanGame game;
        game.play();
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}