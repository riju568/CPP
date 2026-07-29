#include <iostream>
#include <iomanip>
#include <exception>
/**
 * 5.30 (Financial application: compound value) Suppose you save $100
 * each month into a savings account with the annual interest rate 5%.
 * So, the monthly interest rate is 0.05 / 12 = 0.00417. After the first
 * month, the value in the account becomes.
 * Write a program that prompts the user to enter an amount (e.g., 100)
 * the annual interest rate (e.g., 5), and the number of months (e.g., 6)
 * and displays the amount in the savings account after the given month.
 */

int main() {
    std::ios_base::sync_with_stdio(true);
    try {
        std::cout << "Enter the amount you would like to invest each month: ";
        double investment = 0.0;
        if (!(std::cin >> investment) || investment < 0.0) {
            std::cerr << "Error: Invalid investment amount.\n";
            return 1;
        }

        std::cout << "Enter the annual interest rate (e.g. 5, 10, 20): ";
        double annualInterestRate = 0.0;
        if (!(std::cin >> annualInterestRate) || annualInterestRate < 0.0) {
            std::cerr << "Error: Invalid interest rate.\n";
            return 1;
        }

        std::cout << "Enter the number of months: ";
        int numberOfMonths = 0;
        if (!(std::cin >> numberOfMonths) || numberOfMonths <= 0) {
            std::cerr << "Error: Number of months must be greater than 0.\n";
            return 1;
        }
        double monthlyInterestRate = (annualInterestRate / 100.0) / 12.0;
        double totalAccountValue = 0.0;
        for (int i = 1; i <= numberOfMonths; ++i) {
            totalAccountValue = (investment + totalAccountValue) * (1.0 + monthlyInterestRate);
        }
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "After the " << numberOfMonths << " month(s), the account value is " 
                  << totalAccountValue << '\n';
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}