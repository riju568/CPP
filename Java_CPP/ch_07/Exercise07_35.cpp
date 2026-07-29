#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * ***7.35 (Game: hangman) Hangman game that randomly generates a word and
 * prompts the user to guess one letter at a time.
 */

const std::vector<std::string> WORDS = {
    "words", "bread", "signal", "time", "display", "friend", "computer", "forget", "java"
};
bool isWordSolved(const std::string& hiddenWord) {
    return hiddenWord.find('*') == std::string::npos;
}
int processGuess(const std::string& secretWord, std::string& hiddenWord, char guess) {
    bool matchFound = false;
    bool alreadyGuessed = false;

    for (size_t i = 0; i < secretWord.length(); ++i) {
        if (secretWord[i] == guess) {
            if (hiddenWord[i] == guess) {
                alreadyGuessed = true;
                break;
            } else {
                hiddenWord[i] = guess;
                matchFound = true;
            }
        }
    }

    if (alreadyGuessed) {
        return 0;
    } else if (matchFound) {
        return 1;
    } else {
        return -1;
    }
}
char readCharInput() {
    std::string input;
    if (std::cin >> input) {
        if (!input.empty()) {
            return static_cast<char>(std::tolower(input[0]));
        }
    }
    return '\0';
}
bool askToContinue() {
    while (true) {
        std::cout << "Do you want to guess another word? Enter y or n > ";
        char response = readCharInput();
        if (response == 'y') {
            return true;
        } else if (response == 'n') {
            return false;
        }
    }
}
void playGame(std::mt19937& rng) {
    std::uniform_int_distribution<size_t> dist(0, WORDS.size() - 1);
    std::string secretWord = WORDS[dist(rng)];
    std::string hiddenWord(secretWord.length(), '*');
    int missed = 0;
    while (!isWordSolved(hiddenWord)) {
        std::cout << "(Guess) Enter a letter in word " << hiddenWord << " > ";
        char guess = readCharInput();

        if (guess == '\0') {
            continue; // Skip invalid or empty inputs
        }

        int result = processGuess(secretWord, hiddenWord, guess);

        if (result == 0) {
            std::cout << "  " << guess << " is already in the word\n";
        } else if (result == -1) {
            std::cout << "  " << guess << " is not in the word\n";
            missed++;
        }
    }

    std::cout << "The word is " << secretWord << ". You missed " << missed << (missed == 1 ? " time" : " times") << '\n';
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::random_device rd;
        std::mt19937 rng(rd());

        bool keepPlaying = true;

        while (keepPlaying) {
            playGame(rng);
            keepPlaying = askToContinue();
        }

        std::cout << "Thanks for playing hangman!\n";

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}