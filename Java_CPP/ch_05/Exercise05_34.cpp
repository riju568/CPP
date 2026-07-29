#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <exception>

// Function declarations
std::string getHand(int hand);
std::string getGameStatus(int computer, int player);

/**
 * 5.34 (Game: scissor, rock, paper) Plays scissor-rock-paper continuously 
 * until either the user or the computer wins more than two times more than 
 * its opponent (i.e., a score difference greater than 2).
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    try {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, 2);
        int compWins = 0;
        int userWins = 0;
        while (std::abs(userWins - compWins) <= 2) {
            int computerHand = dist(gen);
            std::cout << "Enter 0 for scissor, 1 for rock, 2 for paper: ";
            int playerHand = 0;
            if (!(std::cin >> playerHand) || playerHand < 0 || playerHand > 2) {
                std::cout << "Invalid selection. Please enter 0, 1, or 2.\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }
            std::string computer = getHand(computerHand);
            std::string player = getHand(playerHand);
            std::string gameStats = getGameStatus(computerHand, playerHand);
            if (gameStats == "You won") {
                userWins++;
            } else if (gameStats == "You lost") {
                compWins++;
            }
            std::cout << "The computer is " << computer << ". You are " << player 
                      << ". " << gameStats << ".\n";
        }

        std::cout << "\n--- Final Score ---\n";
        if (userWins > compWins) {
            std::cout << "You WON the game! User wins: " << userWins 
                      << " | Computer wins: " << compWins << '\n';
        } else {
            std::cout << "You LOST the game! User wins: " << userWins 
                      << " | Computer wins: " << compWins << '\n';
        }

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}

std::string getHand(int hand) {
    switch (hand) {
        case 0: return "scissor";
        case 1: return "rock";
        case 2: return "paper";
        default: return "unknown";
    }
}

std::string getGameStatus(int computer, int player) {
    if (computer == player) {
        return "It's a draw";
    }

    switch (player) {
        case 0: // Scissor
            return (computer != 1) ? "You won" : "You lost";
        case 1: // Rock
            return (computer != 2) ? "You won" : "You lost";
        case 2: // Paper
            return (computer != 0) ? "You won" : "You lost";
        default:
            return "Invalid";
    }
}