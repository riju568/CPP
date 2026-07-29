#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *6.23 (Occurrences of a specified character) Write a method that finds the number of
 * occurrences of a specified character in a string using the following header:
 * int count(const std::string &str, char a)
 * For example, count("Welcome", 'e') returns 2.
 *
 * Write a test program that prompts the user to enter a string followed by a character
 * and displays the number of occurrences of the character in the string.
 */

int count(const std::string &str, char a)
{
    int occurrences = 0;
    for (char ch : str)
    {
        if (ch == a)
        {
            occurrences++;
        }
    }
    return occurrences;
}
std::string trim_right(const std::string &str)
{
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter a string followed by a character: ";
        std::string input;
        if (std::getline(std::cin, input))
        {
            if (input.empty())
            {
                std::cout << "Error: Input cannot be empty.\n";
                return EXIT_SUCCESS;
            }

            char c = input.back();
            std::string s = input.substr(0, input.length() - 1);
            s = trim_right(s);

            std::cout << "The character " << c << " occurs " << count(s, c) << " times in " << s << '\n';
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