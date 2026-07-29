#include <iostream>
#include <cmath>
#include <exception>
/**
 * 2.20 (Financial application: calculate interest) If you know the balance and the annual
 * percentage interest rate, you can compute the interest on the next monthly payment
 * using the following formula:
 * interest = balance * (annualInterestRate/1200)
 * Write a program that reads the balance and the annual percentage interest rate and
 * displays the interest for the next month.
 * Example:
 * Enter balance and interest rate (e.g., 3 for 3%): 1000 3.5
 * The interest is 2.91667
 */

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter balance and interest rate: (e.g., 3 for 3%): \n";
        double balance = 0.0;
        double rate = 0.0;

        if (!(std::cin >> balance >> rate))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double interest = balance * (rate / 1200.0);
        const double roundedInterest = std::round(interest * 100000.0) / 100000.0;
        std::cout << "The interest rate is: " << roundedInterest << '\n';
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