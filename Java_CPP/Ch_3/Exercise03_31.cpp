#include <iostream>
#include <cstdio>
#include <stdexcept>
/**
 * *3.31 (Financials: currency exchange) Write a program that prompts the user to enter
 * the exchange rate from currency in U.S. dollars to Chinese RMB.
 * <p>
 * Prompt the user to enter 0 to convert from U.S. dollars to Chinese RMB and 1 to convert from
 * Chinese RMB and U.S. dollars.
 * <p>
 * Prompt the user to enter the amount in U.S. dollars or Chinese RMB to convert it to Chinese RMB or U.S. dollars, respectively.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        double rate = 0.0;
        std::cout << "\nEnter the exchange rate from dollars to RMB: ";
        if (!(std::cin >> rate))
        {
            throw std::runtime_error("Please enter valid numeric values matching the prompt.");
        }

        int choice = 0;
        std::cout << "Enter 0 to convert dollars to RMB and 1 vice versa: ";
        if (!(std::cin >> choice))
        {
            throw std::runtime_error("Please enter valid numeric values matching the prompt.");
        }
        if (choice != 0 && choice != 1)
        {
            std::cout << "Incorrect input\n";
            return 0;
        }
        double amt = 0.0;
        if (choice == 0)
        {
            std::cout << "Enter the dollar amount: ";
            if (!(std::cin >> amt))
            {
                throw std::runtime_error("Please enter valid numeric values matching the prompt.");
            }
            double rmb = amt * rate;
            std::printf("$%.1f is %.1f yuan\n", amt, rmb);
        }
        else
        {
            std::cout << "Enter the RMB amount: ";
            if (!(std::cin >> amt))
            {
                throw std::runtime_error("Please enter valid numeric values matching the prompt.");
            }
            double dollars = amt / rate;
            std::printf("%.1f yuan is $%.2f\n", amt, dollars);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}