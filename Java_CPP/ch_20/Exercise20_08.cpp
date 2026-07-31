#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <exception>
#include <stdexcept>

class LotteryGame {
private:
    int lottery_number;
    std::string lot_str;

    static int count_matches(const std::vector<int>& lot_digits, const std::vector<int>& played_digits) {
        int matches = 0;
        std::vector<int> temp_lot = lot_digits;
        for (int p : played_digits) {
            auto it = std::find(temp_lot.begin(), temp_lot.end(), p);
            if (it != temp_lot.end()) {
                matches++;
                temp_lot.erase(it); // Avoid double-counting duplicate matched digits
            }
        }
        return matches;
    }

public:
    LotteryGame() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(100, 999);
        lottery_number = dist(gen);
        lot_str = std::to_string(lottery_number);
    }

    void evaluate_guess(int user_guess) const {
        std::string guess_str = std::to_string(user_guess);
        while (guess_str.length() < 3) {
            guess_str = "0" + guess_str;
        }

        std::vector<int> played_digits;
        std::vector<int> lot_digits;

        for (char c : guess_str) played_digits.push_back(c - '0');
        for (char c : lot_str) lot_digits.push_back(c - '0');

        int matches = count_matches(lot_digits, played_digits);

        std::cout << "The lottery number is " << lottery_number << '\n';

        if (user_guess == lottery_number) {
            std::cout << "Exact match: you win $10,000\n";
        } else if (matches == 3) {
            std::cout << "Match all digits: you win $3,000\n";
        } else if (matches == 2) {
            std::cout << "Match two digits: you win $2,000\n";
        } else if (matches == 1) {
            std::cout << "Match one digit: you win $1,000\n";
        } else {
            std::cout << "Sorry no match, play again!!!\n";
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter your lottery pick as an integer of three digits (100-999): ";
        int guess = 0;
        if (!(std::cin >> guess) || guess < 100 || guess > 999) {
            std::cerr << "Error: Invalid input. Must be a 3-digit integer.\n";
            return 3;
        }

        LotteryGame game;
        game.evaluate_guess(guess);
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