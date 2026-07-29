#include <iostream>
#include <cmath>
#include <stdexcept>
/**
 * 3.7 (Financial application: monetary units) Modify Listing 2.10, ComputeChange
 * .java, to display the nonzero denominations only, using singular words for single
 * units such as 1 dollar and 1 penny, and plural words for more than one unit such
 * as 2 dollars and 3 pennies.
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        double amount = 0.0;
        std::cout << "Enter an amount in double, for example 11.56: ";
        if (!(std::cin >> amount))
        {
            throw std::runtime_error("Invalid input: Please enter a valid numeric amount.");
        }
        if (amount < 0.0)
        {
            throw std::out_of_range("Amount cannot be a negative value.");
        }
        int remaining_amount = static_cast<int>(std::round(amount * 100.0));

        int number_of_one_dollars = remaining_amount / 100;
        remaining_amount %= 100;

        int number_of_quarters = remaining_amount / 25;
        remaining_amount %= 25;

        int number_of_dimes = remaining_amount / 10;
        remaining_amount %= 10;

        int number_of_nickels = remaining_amount / 5;
        remaining_amount %= 5;

        int number_of_pennies = remaining_amount;

        std::cout << "Your amount " << amount << " consists of:\n";

        if (number_of_one_dollars > 0)
        {
            std::cout << "   " << number_of_one_dollars << (number_of_one_dollars == 1 ? " dollar\n" : " dollars\n");
        }
        if (number_of_quarters > 0)
        {
            std::cout << "   " << number_of_quarters << (number_of_quarters == 1 ? " quarter\n" : " quarters\n");
        }
        if (number_of_dimes > 0)
        {
            std::cout << "   " << number_of_dimes << (number_of_dimes == 1 ? " dime\n" : " dimes\n");
        }
        if (number_of_nickels > 0)
        {
            std::cout << "   " << number_of_nickels << (number_of_nickels == 1 ? " nickel\n" : " nickels\n");
        }
        if (number_of_pennies > 0)
        {
            std::cout << "   " << number_of_pennies << (number_of_pennies == 1 ? " penny\n" : " pennies\n");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}