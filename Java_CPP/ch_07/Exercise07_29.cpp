#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *7.29 (Game: pick four cards) Picks four cards from a deck of 52 
 * and displays the number of picks that yields the sum of 24.
 */

const std::vector<std::string> SUITS = {"Spades", "Hearts", "Diamonds", "Clubs"};
const std::vector<std::string> RANKS = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

// Creates a standard deck of 52 unique cards represented from 0 to 51.
std::vector<int> makeDeck() {
    std::vector<int> deck(52);
    for (int i = 0; i < 52; ++i) {
        deck[i] = i;
    }
    return deck;
}

// Draws 4 unique random cards from the 52-card deck using efficient shuffling.
std::vector<int> randomDraw4(const std::vector<int>& deck, std::mt19937& rng) {
    std::vector<int> shuffled = deck;
    std::shuffle(shuffled.begin(), shuffled.end(), rng);
    return {shuffled[0], shuffled[1], shuffled[2], shuffled[3]};
}

// Prints the human-readable names of the 4 winning cards.
void printDrawnCards(const std::vector<int>& cards) {
    std::cout << "Winning cards: ";
    for (size_t i = 0; i < cards.size(); ++i) {
        int suitIndex = cards[i] / 13;
        int rankIndex = cards[i] % 13;
        std::cout << RANKS[rankIndex] << " of " << SUITS[suitIndex];
        if (i < cards.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << '\n';
}

int main() {
    try {
        // Optimize standard I/O operations for cross-platform execution
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<int> deck = makeDeck();
        int picks = 0;
        int sum = 0;
        std::vector<int> drawnCards;

        std::cout << "Starting simulation to find a draw sum of 24...\n";

        std::random_device rd;
        std::mt19937 rng(rd());

        while (sum != 24) {
            picks++;
            drawnCards = randomDraw4(deck, rng);

            // Calculate sum based on face values (Ace=1, Jack=11, Queen=12, King=13)
            sum = 0;
            for (int card : drawnCards) {
                int value = (card % 13) + 1;
                sum += value;
            }
        }

        std::cout << "Drew cards " << picks << " times to yield a target sum of 24.\n";
        printDrawnCards(drawnCards);

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e) {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}