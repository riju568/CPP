#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *4.13 (Vowel or consonant?) Write a program that prompts the user to enter a letter
 * check whether the letter is a vowel or consonant.
 *
 * Here is a sample run:
 * Enter a letter: B
 * B is a consonant
 * Enter a letter grade: a
 * a is a vowel
 * Enter a letter grade: #
 * # is an invalid input
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

        if (input.length() > 1)
        {
            std::cout << input << " is invalid input.\n";
        }
        else
        {
            char ch = input[0];
            if (std::isalpha(static_cast<unsigned char>(ch)))
            {
                char lower_ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));

                if (lower_ch == 'a' || lower_ch == 'e' || lower_ch == 'i' || lower_ch == 'o' || lower_ch == 'u')
                {
                    std::cout << ch << " is a vowel\n";
                }
                else
                {
                    std::cout << ch << " is a consonant\n";
                }
            }
            else
            {
                std::cout << ch << " is an invalid input\n";
            }
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