#include <iostream>
#include <exception>
/**
 * *2.22 (Financial application: monetary units) Rewrite Listing 2.10,
 * ComputeChange .java, to fix the possible loss of accuracy when converting a
 * double value to an int value.
 * <p>
 * Enter the input as an integer whose last two digits represent the cents. For
 * example, the input 1156 represents 11 dollars and 56 cents.
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        std::cout << "Enter dollar amount as an integer whose last two digits represent the cents, for example 1156 for $11.56: ";
        int amount = 0;
        if (!(std::cin >> amount))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        int quarters = 0;
        int dimes = 0;
        int nickles = 0;
        int pennies = 0;
        int cents = amount % 100;
        int dollars = amount / 100;
        quarters = cents / 25;
        cents %= 25;
        dimes = cents / 10;
        cents %= 10;
        nickles = cents / 5;
        cents %= 5;
        pennies = cents / 1;
        cents %= 1;

        std::cout << "Your integer amount " << amount << " consists of \n"
                  << dollars << " dollars\n"
                  << quarters << " quarters \n"
                  << dimes << " dimes\n"
                  << nickles << " nickels\n"
                  << pennies << " pennies\n";
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