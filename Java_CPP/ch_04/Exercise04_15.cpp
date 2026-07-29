#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *4.15 (Phone key pads) The international standard letter/number mapping found on the
 * telephone is shown below:
 * Write a program that prompts the user to enter a letter and displays its corresponding number.
 * Enter a letter: A
 * The corresponding number is 2
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a letter: ";
        std::string input;
        if (!(std::cin >> input))
        {
            std::cout << "Invalid input.\n";
            return EXIT_SUCCESS;
        }

        if (input.length() != 1)
        {
            std::cout << "Error: Please enter a single letter.\n";
            return EXIT_SUCCESS;
        }

        char original_char = input[0];
        char letter = static_cast<char>(std::tolower(static_cast<unsigned char>(original_char)));

        if (letter >= 'a' && letter <= 'c')
        {
            std::cout << "The corresponding number is 2\n";
        }
        else if (letter >= 'd' && letter <= 'f')
        {
            std::cout << "The corresponding number is 3\n";
        }
        else if (letter >= 'g' && letter <= 'i')
        {
            std::cout << "The corresponding number is 4\n";
        }
        else if (letter >= 'j' && letter <= 'l')
        {
            std::cout << "The corresponding number is 5\n";
        }
        else if (letter >= 'm' && letter <= 'o')
        {
            std::cout << "The corresponding number is 6\n";
        }
        else if (letter >= 'p' && letter <= 's')
        {
            std::cout << "The corresponding number is 7\n";
        }
        else if (letter >= 't' && letter <= 'v')
        {
            std::cout << "The corresponding number is 8\n";
        }
        else if (letter >= 'w' && letter <= 'z')
        {
            std::cout << "The corresponding number is 9\n";
        }
        else
        {
            std::cout << original_char << " is an invalid input.\n";
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