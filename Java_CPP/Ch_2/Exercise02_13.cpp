#include <iostream>
#include <iomanip>
#include <exception>
/**
 * 2.13 (Financial application: compound value) Write a program that prompts
 * the user to enter a  monthly saving amount and displays the account value
 * after the sixth month.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter the monthly saving amount: ";

        double monthlyDeposit = 0.0;
        if (!(std::cin >> monthlyDeposit))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        constexpr double MONTHLY_INTEREST_RATE = 0.05 / 12.0;
        constexpr double INTEREST_FACTOR = 1.0 + MONTHLY_INTEREST_RATE;
        double total = monthlyDeposit * INTEREST_FACTOR;    // Month 1
        total = (total + monthlyDeposit) * INTEREST_FACTOR; // Month 2
        total = (total + monthlyDeposit) * INTEREST_FACTOR; // Month 3
        total = (total + monthlyDeposit) * INTEREST_FACTOR; // Month 4
        total = (total + monthlyDeposit) * INTEREST_FACTOR; // Month 5
        total = (total + monthlyDeposit) * INTEREST_FACTOR; // Month 6
        std::cout << "After the sixth month, the account value is $"
                  << std::fixed << std::setprecision(2) << total << '\n';
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