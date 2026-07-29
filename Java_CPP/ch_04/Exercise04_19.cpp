#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.19 (Business: check ISBN-10) Rewrite the Programming Exercise 3.9 by entering the
 * ISBN number as a string.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter the first 9 digits of an ISBN as a string: ";
        std::string isbn;
        if (!(std::cin >> isbn))
        {
            std::cout << "Invalid input.\n";
            return EXIT_SUCCESS;
        }

        bool is_valid = (isbn.length() == 9);
        if (is_valid)
        {
            for (char ch : isbn)
            {
                if (!std::isdigit(static_cast<unsigned char>(ch)))
                {
                    is_valid = false;
                    break;
                }
            }
        }

        if (!is_valid)
        {
            std::cout << "Invalid input. Please enter exactly 9 numeric digits.\n";
            return EXIT_SUCCESS;
        }

        int sum = 0;
        for (int i = 0; i < 9; ++i)
        {
            int num = isbn[i] - '0';
            sum += num * (i + 1);
        }

        int d10 = sum % 11;
        std::cout << "The ISBN-10 number is " << isbn;
        if (d10 == 10)
        {
            std::cout << 'X';
        }
        else
        {
            std::cout << d10;
        }
        std::cout << '\n';

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