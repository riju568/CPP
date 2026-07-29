#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>

/**
 * 5.22 (Financial application: loan amortization schedule)
 * Prompts the user for loan amount, number of years, and annual interest rate,
 * calculates monthly/total payments, and prints the month-by-month amortization schedule.
 */
int main() {

    std::ios_base::sync_with_stdio(true);

    try {
        std::cout << "Enter the loan amount: ";
        double loanAmount = 0.0;
        if (!(std::cin >> loanAmount) || loanAmount <= 0) {
            std::cerr << "Error: Invalid loan amount. Please enter a positive number.\n";
            return 1;
        }

        std::cout << "Number of years: ";
        int numYears = 0;
        if (!(std::cin >> numYears) || numYears <= 0) {
            std::cerr << "Error: Invalid number of years. Please enter a positive integer.\n";
            return 1;
        }

        std::cout << "Annual Interest Rate (e.g., 7 for 7%): ";
        double annualRate = 0.0;
        if (!(std::cin >> annualRate) || annualRate <= 0) {
            std::cerr << "Error: Invalid annual interest rate. Please enter a positive number.\n";
            return 1;
        }
        double monthlyInterestRate = annualRate / 1200.0;
        int totalMonths = numYears * 12;
        double monthlyPayment = (loanAmount * monthlyInterestRate) /
            (1.0 - (1.0 / std::pow(1.0 + monthlyInterestRate, totalMonths)));
        double totalPayment = monthlyPayment * totalMonths;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\nMonthly Payment: " << monthlyPayment << '\n';
        std::cout << "Total Payment: " << totalPayment << "\n\n";
        std::cout << "Payment#\tInterest\tPrincipal\tBalance\n";
        
        double balance = loanAmount;
        for (int i = 1; i <= totalMonths; ++i) {
            double interest = monthlyInterestRate * balance;
            double principal = monthlyPayment - interest;
            balance -= principal;
            if (i == totalMonths && std::abs(balance) < 1e-4) {
                balance = 0.0;
            }

            std::cout << i << "\t\t"
                      << interest << "\t\t"
                      << principal << "\t\t"
                      << balance << '\n';
        }

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}