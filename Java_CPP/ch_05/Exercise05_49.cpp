#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *5.49 (Count vowels and consonants) Assume letters A, E, I, O, and U as the vowels.
 * Write a program that prompts the user to enter a string and displays the number
 * of vowels and consonants in the string.
 *
 * Enter a string: Programming is fun
 * The number of vowels is 5
 * The number of consonants is 11
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        const std::string vowel_string = "AEIOU";

        std::cout << "Enter a string: ";
        std::string s;
        if (!std::getline(std::cin, s))
        {
            std::cout << "Error: An error occurred while reading input.\n";
            return EXIT_SUCCESS;
        }

        // Convert string to uppercase
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::toupper(c);
        });

        int vowels = 0;
        int consonants = 0;

        for (char ch : s)
        {
            if (std::isalpha(static_cast<unsigned char>(ch)))
            {
                if (vowel_string.find(ch) != std::string::npos)
                {
                    ++vowels;
                }
                else
                {
                    ++consonants;
                }
            }
        }

        std::cout << "The number of vowels is " << vowels << '\n';
        std::cout << "The number of consonants is " << consonants << '\n';

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