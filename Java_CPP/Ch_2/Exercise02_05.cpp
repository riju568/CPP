#include <iostream>
#include <iomanip>
#include <exception>
/**
 * 2.5 (Financial application: calculate tips)
 * Write a program that reads the sub-total and
 * the gratuity rate, then computes the gratuity and
 * total. For example, if the user enters 10 for sub-total
 * and 15% for gratuity rate, the program displays $1.5 as
 * gratuity and $11.5 as total.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Welcome to the super excellent java master gratuity and bill calculator! :) \n";
        std::cout << "Enter your subtotal and the gratuity rate: \n";

        double subTotal = 0.0;
        double percentGratuity = 0.0;
        if (!(std::cin >> subTotal >> percentGratuity))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double gratuity = subTotal * (percentGratuity / 100.0);
        const double total = subTotal + gratuity;
        std::cout << "The gratuity is: $" << std::fixed << std::setprecision(2) << gratuity;
        std::cout << " and the total including gratuity is: $" << total << '\n';
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