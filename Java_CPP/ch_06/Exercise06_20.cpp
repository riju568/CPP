#include <iostream>
#include <string>
#include <cctype>
#include <exception>
#include <cstdlib>

/**
 * *6.20 (Count the letters in a string) Write a method that counts the number of letters in
 * a string using the following header:
 * int count_letters(const std::string &s)
 * Write a test program that prompts the user to enter a string and displays the number of letters in the string.
 */
int count_letters(const std::string &s)
{
    int count = 0;
    for (char c : s)
    {
        if (std::isalpha(static_cast<unsigned char>(c)))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a string:\n";
        std::string s;
        if (std::getline(std::cin, s))
        {
            std::cout << "Number of letters: " << count_letters(s) << '\n';
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