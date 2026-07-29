#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *4.14 (Convert letter grade to number) Write a program that prompts the user to enter a
 * letter grade A, B, C, D, or F and displays its corresponding numeric value 4, 3, 2,
 * 1, or 0. Here is a sample run:
 * Enter a letter grade: B
 * The numeric value for grade B is 3
 * Enter a letter grade: T
 * T is an invalid grade
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a letter grade: ";
        std::string input;
        if (!(std::cin >> input))
        {
            std::cout << "Invalid input.\n";
            return EXIT_SUCCESS;
        }

        if (input.length() != 1)
        {
            std::cout << input << " is an invalid grade\n";
        }
        else
        {
            char letter_grade = input[0];
            switch (letter_grade)
            {
            case 'A':
                std::cout << "The numeric value for grade " << letter_grade << " is 4\n";
                break;
            case 'B':
                std::cout << "The numeric value for grade " << letter_grade << " is 3\n";
                break;
            case 'C':
                std::cout << "The numeric value for grade " << letter_grade << " is 2\n";
                break;
            case 'D':
                std::cout << "The numeric value for grade " << letter_grade << " is 1\n";
                break;
            case 'F':
                std::cout << "The numeric value for grade " << letter_grade << " is 0\n";
                break;
            default:
                std::cout << letter_grade << " is an invalid grade\n";
                break;
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