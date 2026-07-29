#include <iostream>
#include <exception>
/**
 * 2.6 (Sum the digits in an integer)
 * Write a program that reads an integer between 0 and
 * 1000 and adds all the digits in the integer.
 * For example, if an integer is 932, the sum of all its digits is 14.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a number between 0 and 1000: \n";
        int number = 0;
        if (!(std::cin >> number))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        int sum = 0;
        int remainingNumber = number;

        while (remainingNumber > 0)
        {
            sum += remainingNumber % 10;
            remainingNumber /= 10;
        }

        std::cout << "The sum of the digits is " << sum << '\n';
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