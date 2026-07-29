#include <iostream>
#include <random>
#include <string>
#include <stdexcept>
#include <iomanip>
/**
 * **3.15 (Game: lottery) Revise Listing 3.8, Lottery.java, to generate a
 * lottery of a three digit number.
 * <p>
 * The program prompts the user to enter a three-digit number and determines
 * whether the user wins according to the following rules:
 * <p>
 * 1. If the user input matches the lottery number in the exact order, the award
 * is $10,000.
 * <p>
 * 2.If all digits in the user input match all digits in the lottery number, the
 * award is $3,000.
 * <p>
 * 3. If one digit in the user input matches a digit in the lottery number, the
 * award is $1,000
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 999);
        int lottery = dis(gen);
        std::cout << "Enter your lottery pick as an integer of three digits: ";
        int guess = 0;
        if (!(std::cin >> guess)) {
            throw std::runtime_error("Invalid input: Please enter a valid integer.");
        }
        if (guess < 0 || guess > 999) {
            throw std::out_of_range("Error: The lottery pick must be a three-digit integer (000 to 999).");
        }

        int l1 = lottery / 100;
        int l2 = (lottery / 10) % 10;
        int l3 = lottery % 10;

        std::cout << "l1 = " << l1 << "\n";
        std::cout << "l2 = " << l2 << "\n";
        std::cout << "l3 = " << l3 << "\n";

        int g1 = guess / 100;
        int g2 = (guess / 10) % 10;
        int g3 = guess % 10;

        std::cout << "g1 = " << g1 << "\n";
        std::cout << "g2 = " << g2 << "\n";
        std::cout << "g3 = " << g3 << "\n";

        std::cout << "The lottery number is " << std::setw(3) << std::setfill('0') << lottery << "\n";
        std::string result = "";

        if (guess == lottery) {
            result += "Exact match: you win $10,000";
        } else if ((g1 == l1 || g1 == l2 || g1 == l3) && (g2 == l1 || g2 == l2 || g2 == l3)
                && (g3 == l1 || g3 == l2 || g3 == l3)) {
            result += "Match all digits: you win $3,000";
        } else if ((g1 == l1 || g1 == l2 || g1 == l3) && (g3 == l1 || g3 == l2 || g3 == l3)
                && (g2 == l1 || g2 == l2 || g2 == l3)) {
            result += "Match all digits: you win $3,000";
        } else if ((g2 == l1 || g2 == l2 || g2 == l3) && (g1 == l1 || g1 == l2 || g1 == l3)
                && (g3 == l1 || g3 == l2 || g3 == l3)) {
            result += "Match all digits: you win $3,000";
        } else if ((g2 == l1 || g2 == l2 || g2 == l3) && (g3 == l1 || g3 == l2 || g3 == l3)
                && (g1 == l1 || g1 == l2 || g1 == l3)) {
            result += "Match all digits: you win $3,000";
        } else if ((g3 == l1 || g3 == l2 || g3 == l3) && (g1 == l1 || g1 == l2 || g1 == l3)
                && (g2 == l1 || g2 == l2 || g2 == l3)) {
            result += "Match all digits: you win $3,000";
        } else if ((g3 == l1 || g3 == l2 || g3 == l3) && (g2 == l1 || g2 == l2 || g2 == l3)
                && (g1 == l1 || g1 == l2 || g1 == l3)) {
            result += "Match all digits: you win $3,000";
        } else if (g1 == l1 || g1 == l2 || g1 == l3 || g2 == l1 || g2 == l2 || g2 == l3 || g3 == l1 || g3 == l2
                || g3 == l3) {
            result += "Match one digit: you win $1,000";
        } else {
            result += "Sorry no match, play again!!!";
        }

        std::cout << result << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}