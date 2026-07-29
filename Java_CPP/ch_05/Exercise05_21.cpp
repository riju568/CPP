#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>

/**

 * **5.21 (Financial application: compare loans with various interest rates)

 * <p>

 * Write a program that lets the user enter the loan amount and loan period in number of years

 * and displays the monthly and total payments for each interest rate starting from

 * 5% to 8%, with an increment of 1/8. Here is a sample run:

 * Loan Amount: 10000

 * Number of Years: 5

 * Interest Rate Monthly Payment Total Payment

 * 5.000% 188.71 11322.74

 * 5.125% 189.29 11357.13

 * 5.250% 189.86 11391.59

 * ...

 * 7.875% 202.17 12129.97

 * 8.000% 202.76 12165.84

 */
int main() {
    std::ios_base::sync_with_stdio(true);

    try {
        std::cout << "Loan amount: ";
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
        std::cout << "\nInterest Rate   Monthly Payment   Total Payment\n";
        for (double annualRate = 5.0; annualRate <= 8.001; annualRate += 0.125) {
            double monthlyInterestRate = annualRate / 1200.0;
            double monthlyPayment = (loanAmount * monthlyInterestRate) /
                (1.0 - (1.0 / std::pow(1.0 + monthlyInterestRate, numYears * 12)));
            double totalPayment = monthlyPayment * numYears * 12;
            std::cout << std::fixed 
                      << std::setprecision(3) << annualRate << "%"
                      << std::setw(18) << std::setprecision(2) << monthlyPayment
                      << std::setw(18) << std::setprecision(2) << totalPayment << '\n';
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