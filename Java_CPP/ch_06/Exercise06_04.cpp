#include <iostream>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * 6.4 (Display an integer reversed) Write a method with the following header to
 * display an integer in reverse order. public static void reverse(int number)
 * For example, reverse(3456) displays 6543. Write a test program that prompts
 * the user to enter an integer and displays its reversal.
 */
void reverse(int number)
{
    if (number == 0)
    {
        std::cout << 0;
        return;
    }

    if (number < 0)
    {
        std::cout << '-';
        number = std::abs(number);
    }

    while (number > 0)
    {
        std::cout << (number % 10);
        number /= 10;
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter an integer now: \n";
        int number = 0;

        if (!(std::cin >> number))
        {
            std::cerr << "Error: Invalid input. Please enter a valid integer.\n";
            return EXIT_SUCCESS;
        }

        reverse(number);
        std::cout << '\n';

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