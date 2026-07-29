#include <iostream>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.9 (Find the Unicode of a character) Write a program that receives a character and
 * displays its Unicode.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a character: ";
        char ch = '\0';
        if (!(std::cin >> ch))
        {
            std::cout << "Please enter a valid character.\n";
            return EXIT_SUCCESS;
        }

        int unicode_val = static_cast<int>(static_cast<unsigned char>(ch));

        std::cout << "The Unicode for the character " << ch << " is " << unicode_val << '\n';

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