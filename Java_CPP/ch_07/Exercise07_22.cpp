#include <iostream>
#include <string>
#include <cctype>
#include <exception>
#include <cstdlib>

/**
 * 7.22 (Find the number of uppercase letters in a string)
 * Passes a string from the command line and displays the number of uppercase letters.
 */

int main(int argc, char *argv[])
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        if (argc < 2)
        {
            std::cout << "Error: No string provided.\n";
            std::cout << "Usage: ./Exercise07_22 \"YourStringHere\"\n";
            return EXIT_FAILURE;
        }

        std::string str = argv[1];
        int upper_case_count = 0;

        for (char c : str)
        {
            if (std::isupper(static_cast<unsigned char>(c)))
            {
                upper_case_count++;
            }
        }

        std::cout << "The number of uppercase letters is " << upper_case_count << '\n';

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