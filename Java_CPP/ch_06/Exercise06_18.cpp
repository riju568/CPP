#include <iostream>
#include <string>
#include <cctype>
#include <exception>
#include <cstdlib>

/**
 * **6.18 (Check password) Some websites impose certain rules for passwords. Write a
 * method that checks whether a string is a valid password. Suppose the password
 * rules are as follows:
 * ■ A password must have at least eight characters.
 * ■ A password consists of only letters and digits.
 * ■ A password must contain at least two digits.
 * Write a program that prompts the user to enter a password and displays Valid
 * Password if the rules are followed or Invalid Password otherwise
 */
bool validate_password(const std::string &pword)
{
    if (pword.length() < 8)
    {
        return false;
    }

    int count_digits = 0;
    for (char c : pword)
    {
        if (std::isdigit(static_cast<unsigned char>(c)))
        {
            count_digits++;
        }
        else if (!std::isalpha(static_cast<unsigned char>(c)))
        {
            return false; // Not a digit or a letter
        }
    }

    return count_digits >= 2;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter the password to check: \n";
        std::string pwd;
        if (!(std::cin >> pwd))
        {
            std::cerr << "Error: Invalid input.\n";
            return EXIT_SUCCESS;
        }

        std::cout << (validate_password(pwd) ? "Valid Password" : "Invalid Password") << '\n';

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