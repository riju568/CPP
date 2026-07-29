#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.20 (Process a string) Write a program that prompts the user to enter a string
 * and displays its length and its first character with proper resource and exception handling.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a string: ";
        std::string s;
        if (!std::getline(std::cin, s))
        {
            std::cout << "Error: An error occurred while reading input.\n";
            return EXIT_SUCCESS;
        }

        if (!s.empty())
        {
            std::cout << "Length is " << s.length() << ", First char is " << s[0] << '\n';
        }
        else
        {
            std::cout << "Error: You entered an empty string.\n";
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