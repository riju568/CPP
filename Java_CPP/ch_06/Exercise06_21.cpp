#include <iostream>
#include <string>
#include <cctype>
#include <exception>
#include <cstdlib>

/**
 * *6.21 (Phone keypads) The international standard letter/number mapping for telephones
 * is shown in Programming Exercise 4.15. Write a method that returns a number,
 * given an uppercase letter, as follows:
 * int get_number(char uppercase_letter)
 *
 * Write a test program that prompts the user to enter a phone number as a string.
 * The input number may contain letters. The program translates a letter (uppercase
 * or lowercase) to a digit and leaves all other characters intact.
 */
int get_number(char uppercase_letter)
{
    char lower_case_letter = static_cast<char>(std::tolower(static_cast<unsigned char>(uppercase_letter)));

    if (lower_case_letter >= 'a' && lower_case_letter <= 'c')
    {
        return 2;
    }
    else if (lower_case_letter >= 'd' && lower_case_letter <= 'f')
    {
        return 3;
    }
    else if (lower_case_letter >= 'g' && lower_case_letter <= 'i')
    {
        return 4;
    }
    else if (lower_case_letter >= 'j' && lower_case_letter <= 'l')
    {
        return 5;
    }
    else if (lower_case_letter >= 'm' && lower_case_letter <= 'o')
    {
        return 6;
    }
    else if (lower_case_letter >= 'p' && lower_case_letter <= 's')
    {
        return 7;
    }
    else if (lower_case_letter >= 't' && lower_case_letter <= 'v')
    {
        return 8;
    }
    else if (lower_case_letter >= 'w' && lower_case_letter <= 'z')
    {
        return 9;
    }
    return -1;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a phone, containing letters, as a string: ";
        std::string num;
        if (std::cin >> num)
        {
            std::string result;
            result.reserve(num.length());

            for (char ch : num)
            {
                if (std::isalpha(static_cast<unsigned char>(ch)))
                {
                    result += std::to_string(get_number(ch));
                }
                else
                {
                    result += ch;
                }
            }
            std::cout << result << '\n';
        }

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