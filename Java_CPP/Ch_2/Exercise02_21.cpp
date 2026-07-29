#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>
/**
 * *2.21(Financial application: calculate future investment value) Write a
 * program that reads in investment amount, annual interest rate, and number of
 * years, and displays the future investment value using the following formula:
 * <p>
 * futureInvestmentValue = investmentAmount * (1 +
 * monthlyInterestRate)^numberOfYears*12
 * <p>
 * For example, if you enter amount 1000, annual interest rate 3.25%, and number
 * of years 1, the future investment value is 1032.98. Here is a sample run:
 * <p>
 * Enter investment amount: 1000.56 Enter annual interest rate in percentage:
 * 4.25 Enter number of years: 1 Accumulated value is $1043.92
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter investment amount: ";
        double investmentAmount = 0.0;
        if (!(std::cin >> investmentAmount))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        std::cout << "Enter annual interest rate in percentage: ";
        double monthInterestRate = 0.0;
        if (!(std::cin >> monthInterestRate))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        std::cout << "Enter number of years: ";
        double years = 0.0;
        if (!(std::cin >> years))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        years *= 12.0;
        monthInterestRate /= 1200.0;
        const double futureInvestmentValue = investmentAmount * std::pow(monthInterestRate + 1.0, years);
        std::cout << "Accumulated Value is $" << std::fixed << std::setprecision(2) << futureInvestmentValue << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }
    return 0;
}