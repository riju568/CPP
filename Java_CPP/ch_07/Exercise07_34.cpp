#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <exception>
#include <cstdlib>

/**
 * **7.34 (Sort characters in a string) Sorts characters in a string 
 * in ascending order using Bubble Sort.
 */

void trim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
std::string sortString(std::string s)
{
    if (s.empty())
    {
        return "";
    }

    bool swapped = true;
    for (size_t i = 1; i < s.length() && swapped; ++i)
    {
        swapped = false; // Reset swap flag for this pass
        for (size_t j = 0; j < s.length() - i; ++j)
        {
            if (s[j] > s[j + 1])
            {
                swap(s[j], s[j + 1]);
                swapped = true;
            }
        }
    }

    return s;
}

int main()
{
    try
    {
        // Optimize standard I/O operations for cross-platform execution
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a string: ";
        std::string str;
        if (!std::getline(std::cin, str))
        {
            std::cerr << "Error reading input. Please try again.\n";
            return EXIT_FAILURE;
        }

        trim(str);

        std::string sortedStr = sortString(str);
        std::cout << "Sorted result -> " << sortedStr << '\n';

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}