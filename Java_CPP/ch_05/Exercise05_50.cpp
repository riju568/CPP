#include <iostream>
#include <string>
#include <cctype>
#include <exception>
#include <cstdlib>

/**
 * 5.50 (Count uppercase letters) Write a program that prompts
 * the user to enter a string and displays the number of the upper-case
 * letters in the string.
 * By: Harry Dulaney
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a string with some uppercase letters: \n";

        std::string to_be_evaluated;
        if (!std::getline(std::cin, to_be_evaluated))
        {
            std::cout << "Error: An error occurred while reading input.\n";
            return EXIT_SUCCESS;
        }

        int number_of_uppercase = 0;
        size_t x = 0;

        while (x < to_be_evaluated.length())
        {
            if (std::isupper(static_cast<unsigned char>(to_be_evaluated[x])))
            {
                number_of_uppercase++;
            }
            x++;
        }

        std::cout << "The number of upper case letters is: " << number_of_uppercase << '\n';

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