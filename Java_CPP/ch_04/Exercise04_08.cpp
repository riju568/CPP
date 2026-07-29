#include <iostream>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.8 (Find the character of an ASCII code) Write a program that receives an ASCII code
 * (an integer between 0 and 127) and displays its character.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter an ASCII code: ";
        int ascii_code = 0;
        if (!(std::cin >> ascii_code) || ascii_code < 0 || ascii_code > 127)
        {
            std::cout << "Please enter a valid ASCII code (an integer between 0 and 127).\n";
            return EXIT_SUCCESS;
        }
        char output = static_cast<char>(ascii_code);
        std::cout << "The character for ASCII code " << ascii_code << " is " << output << '\n';
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