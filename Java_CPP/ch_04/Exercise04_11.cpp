#include <iostream>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *4.11 (Decimal to hex) Write a program that prompts the user to enter an integer between
 * 0 and 15 and displays its corresponding hex number.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a decimal value (0 to 15): ";
        int user_input = 0;
        if (!(std::cin >> user_input))
        {
            std::cout << "Please enter a valid integer input.\n";
            return EXIT_SUCCESS;
        }

        if (user_input < 0 || user_input > 15)
        {
            std::cout << user_input << " is an invalid input\n";
        }
        else if (user_input >= 0 && user_input <= 9)
        {
            std::cout << "The hex value is " << user_input << '\n';
        }
        else
        {
            char hex_char = static_cast<char>('A' + (user_input - 10));
            std::cout << "The hex value is " << hex_char << '\n';
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}