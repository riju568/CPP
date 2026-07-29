#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.22 (Check substring) Prompts the user to enter two strings and
 * reports whether the second string is a substring of the first string.
 * Refactored with proper exception handling.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter string s1: ";
        std::string s1;
        if (!std::getline(std::cin, s1))
        {
            std::cout << "Error: An error occurred while reading input.\n";
            return EXIT_SUCCESS;
        }
        std::cout << "Enter string s2: ";
        std::string s2;
        if (!std::getline(std::cin, s2))
        {
            std::cout << "Error: An error occurred while reading input.\n";
            return EXIT_SUCCESS;
        }
        if (s1.find(s2) != std::string::npos)
        {
            std::cout << s2 << " is a substring of " << s1 << '\n';
        }
        else
        {
            std::cout << s2 << " is not a substring of " << s1 << '\n';
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