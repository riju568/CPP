#include <iostream>
#include <iomanip>
#include <exception>

/**
 * *5.31 (Financial application: compute CD value) Suppose you put $10,000 into a CD
 * with an annual percentage yield of 5.75%. After one month, the CD is worth
 * 10000 + 10000 * 5.75 / 1200 = 10047.92
 * After two months, the CD is worth
 * 10047.91 + 10047.91 * 5.75 / 1200 = 10096.06
 * After three months, the CD is worth
 * 10096.06 + 10096.06 * 5.75 / 1200 = 10144.44
 * and so on.
 * Write a program that prompts the user to enter an amount (e.g., 10000), the
 * annual percentage yield (e.g., 5.75), and the number of months (e.g., 18) and
 * displays a table as shown in the sample run.
 */


int main() {
    std::ios_base::sync_with_stdio(true);

    try {
        std::cout << "Enter the initial deposit amount: ";
        double deposit = 0.0;
        if (!(std::cin >> deposit) || deposit < 0.0) {
            std::cerr << "Error: Invalid deposit amount.\n";
            return 1;
        }
        std::cout << "Enter annual percentage yield: ";
        double annualYield = 0.0;
        if (!(std::cin >> annualYield) || annualYield < 0.0) {
            std::cerr << "Error: Invalid annual yield.\n";
            return 1;
        }
        std::cout << "Enter maturity period in months: ";
        int numberOfMonths = 0;
        if (!(std::cin >> numberOfMonths) || numberOfMonths <= 0) {
            std::cerr << "Error: Number of months must be greater than 0.\n";
            return 1;
        }
        double monthlyYield = annualYield / 1200.0;
        double cdValue = deposit;
        std::cout << "\nMonth\tCD Value\n";
        for (int month = 1; month <= numberOfMonths; ++month) {
            cdValue += cdValue * monthlyYield;

            std::cout << std::setw(5) << month 
                      << std::fixed << std::setprecision(2) 
                      << std::setw(15) << cdValue << '\n';
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