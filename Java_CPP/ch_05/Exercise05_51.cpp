#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *5.51 (Longest common prefix) Write a program that prompts the user to enter two
 * strings and displays the largest common prefix of the two strings. Here are some
 * sample runs:
 * Enter the first string: Welcome to C++
 * Enter the second string: Welcome to programming
 * The common prefix is Welcome to
 * Enter the first string: Atlanta
 * Enter the second string: Macon
 * Atlanta and Macon have no common prefix
 *
 * By: Harry Dulaney
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter string one: \n";
        std::string str1;
        if (!std::getline(std::cin, str1))
        {
            std::cout << "Error: An error occurred while reading input.\n";
            return EXIT_SUCCESS;
        }

        std::cout << "Enter string two: \n";
        std::string str2;
        if (!std::getline(std::cin, str2))
        {
            std::cout << "Error: An error occurred while reading input.\n";
            return EXIT_SUCCESS;
        }
        if (str1.empty() || str2.empty() || str1[0] != str2[0])
        {
            std::cout << str1 << " and " << str2 << " have no common prefix\n";
            return EXIT_SUCCESS;
        }

        size_t index_of_lcp = 0;
        size_t min_length = std::min(str1.length(), str2.length());

        for (size_t i = 0; i < min_length; ++i)
        {
            if (str1[i] == str2[i])
            {
                index_of_lcp = i;
            }
            else
            {
                break;
            }
        }

        std::cout << "The common prefix is " << str1.substr(0, index_of_lcp + 1) << '\n';

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