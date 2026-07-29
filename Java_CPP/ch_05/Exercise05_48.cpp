#include <iostream>
#include <string>
#include <cctype>
#include <exception>
#include <cstdlib>

/**
 * *5.48 (Process string)
 * Write a program that prompts the user to enter a string and displays the characters at odd positions.
 * Here is a sample run:
 * Enter a string: Beijing Chicago
 * BiigCiao
 *
 * By: Harry Dulaney
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a string: ";
        std::string user_str;
        if (!std::getline(std::cin, user_str))
        {
            std::cout << "Error: An error occurred while reading input.\n";
            return EXIT_SUCCESS;
        }

        user_str = "h" + user_str; // Account for the interpretation of 'odd positions' [i.e., index 0 is position 1]
        std::string res;

        for (size_t i = 0; i < user_str.length(); ++i)
        {
            if (std::isalpha(static_cast<unsigned char>(user_str[i])))
            {
                switch (i % 2)
                {
                case 0:
                    break;
                default:
                    res += user_str[i];
                    break;
                }
            }
        }

        std::cout << res << '\n';

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