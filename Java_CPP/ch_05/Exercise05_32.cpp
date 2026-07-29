#include <iostream>
#include <random>
#include <exception>

/**
 * **5.32 (Game: lottery) Revise Listing 3.8, Lottery.java, to generate a lottery of a two digit number.
 * The two digits in the number are distinct. (Hint: Generate the first
 * digit. Use a loop to continuously generate the second digit until it is different
 * from the first digit.)
 */

int main() {
    std::ios_base::sync_with_stdio(true);

    try {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distDigit1(1, 9); // First digit: 1-9
        std::uniform_int_distribution<int> distDigit2(0, 9); // Second digit: 0-9
        int lotteryDigit1 = distDigit1(gen);
        int lotteryDigit2 = 0;
        do {
            lotteryDigit2 = distDigit2(gen);
        } while (lotteryDigit1 == lotteryDigit2);
        int lottery = lotteryDigit1 * 10 + lotteryDigit2;
        std::cout << "Enter your lottery pick (two digits): ";
        int guess = 0;
        if (!(std::cin >> guess) || guess < 0 || guess > 99) {
            std::cerr << "Error: Invalid input. Please enter a 2-digit number.\n";
            return 1;
        }
        int guessDigit1 = guess / 10;
        int guessDigit2 = guess % 10;
        std::cout << "The lottery number is " << (lottery < 10 ? "0" : "") << lottery << "\n";
        if (guess == lottery) {
            std::cout << "Exact match: you win $10,000\n";
        } else if (guessDigit2 == lotteryDigit1 && guessDigit1 == lotteryDigit2) {
            std::cout << "Match all digits: you win $3,000\n";
        } else if (guessDigit1 == lotteryDigit1
                || guessDigit1 == lotteryDigit2
                || guessDigit2 == lotteryDigit1
                || guessDigit2 == lotteryDigit2) {
            std::cout << "Match one digit: you win $1,000\n";
        } else {
            std::cout << "Sorry, no match\n";
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