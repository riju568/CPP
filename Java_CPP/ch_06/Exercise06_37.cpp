#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

/**
 * 6.37 (Format an integer) Write a method with the following header to
 * format the integer with the specified width.
 * std::string format(int number, int width)
 * The method returns a string for the number with one or more prefix 0s.
 * The size of the string is the width. For example, format(34, 4) returns 0034
 * and format(34, 5) returns 00034. If the number is longer than the width,
 * the method returns the string representation for the number.
 * For example, format(34, 1) returns 34.
 */

std::string format(int number, int width)
{
    std::string str = std::to_string(number);
    if (static_cast<int>(str.length()) < width)
    {
        std::string zeros(width - str.length(), '0');
        return zeros + str;
    }
    return str;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Please enter an integer: \n";
        int number = 0;
        if (std::cin >> number)
        {
            std::cout << "Enter the width expressed in integer format: \n";
            int width = 0;
            if (std::cin >> width)
            {
                std::cout << "The formatted number is: " << format(number, width) << '\n';
            }
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