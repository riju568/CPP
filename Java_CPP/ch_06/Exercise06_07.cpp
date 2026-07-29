#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * *6.7 (Financial application: compute the future investment value) Write a method that
 * computes future investment value at a given interest rate for a specified number
 * of years. The future investment is determined using the formula:
 * * futureInvestmentValue = investmentAmount * (1 + monthlyInterestRate)^(numberOfYears * 12)
 * * Write a test program that prompts the user to enter the investment amount (e.g.,
 * 1000) and the interest rate (e.g., 9%) and prints a table that displays future value
 * for the years from 1 to 30.
 */

constexpr int FIRST_YEAR = 1;
constexpr int LAST_YEAR = 30;

double future_investment_value(double investment_amount, double monthly_interest_rate, int years)
{
    return investment_amount * std::pow(1.0 + monthly_interest_rate, years * 12);
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter the amount invested: \n";
        double amount = 0.0;
        if (!(std::cin >> amount))
        {
            std::cerr << "Error: Invalid input. Please enter a valid number.\n";
            return EXIT_SUCCESS;
        }

        std::cout << "The Annual interest rate as (ex: 5.25 for 5.25%:): \n";
        double year_rate = 0.0;
        if (!(std::cin >> year_rate))
        {
            std::cerr << "Error: Invalid input. Please enter a valid interest rate.\n";
            return EXIT_SUCCESS;
        }

        year_rate /= 100.0;
        double month_rate = year_rate / 12.0;

        std::cout << "Years --- Future Value \n";

        for (int i = FIRST_YEAR; i <= LAST_YEAR; ++i)
        {
            std::cout << i << "      " 
                      << std::fixed << std::setprecision(2) 
                      << future_investment_value(amount, month_rate, i) << '\n';
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}