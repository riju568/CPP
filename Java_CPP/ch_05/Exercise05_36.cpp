#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <exception>
#include <cstdlib>

/**
 * **5.36 (Business application: checking ISBN ) Use loops to simplify Programming
 * Exercise 3.9:
 * Write a program that prompts the user to enter the first 9 digits and
 * displays the 10-digit ISBN (including leading zeros). Your program should
 * read the input as an integer.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        auto trim = [](const std::string &str) -> std::string
        {
            size_t start = str.find_first_not_of(" \t\n\r");
            if (start == std::string::npos)
            {
                return "";
            }
            size_t end = str.find_last_not_of(" \t\n\r");
            return str.substr(start, end - start + 1);
        };

        std::cout << "Enter the first 9 digits of an ISBN-10 number: ";
        std::string line;
        if (!std::getline(std::cin, line))
        {
            std::cout << "Error: An error occurred while reading input.\n";
            return EXIT_SUCCESS;
        }
        line = trim(line);

        if (line.length() != 9)
        {
            std::cout << "Too many numbers entered. Try again, please enter exactly the first NINE digits of the isbn number: \n";
            if (!std::getline(std::cin, line))
            {
                std::cout << "Error: An error occurred while reading input.\n";
                return EXIT_SUCCESS;
            }
            line = trim(line);

            if (line.length() != 9)
            {
                std::cout << "Seriously?...\n";
            }
        }

        std::reverse(line.begin(), line.end());
        int isbn = std::stoi(line);
        int temp = isbn;
        int t = 0;
        int sum = 0;
        int d10 = 0;

        for (int i = 1; i <= 9; ++i)
        {
            int x = temp % 10;

            std::cout << "d" << i << " = " << x << " ->: ";
            t = x * i;

            std::cout << "d" << i << " * " << i << " -> " << x << " * " << i << " = " << t << '\n';
            std::cout << "sum = " << sum << " + " << t << '\n';
            sum += t;
            std::cout << "sum = " << sum << '\n';

            temp /= 10;
        }

        d10 = sum % 11;
        std::cout << "d10 = sum % 11 -> " << d10 << " = " << sum << " % 11\n";

        if (d10 == 10)
        {
            line += "X";
        }
        else
        {
            line += std::to_string(d10);
        }

        std::cout << "The ISBN-10 number is: " << line << '\n';

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