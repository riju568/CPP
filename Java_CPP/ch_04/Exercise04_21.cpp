#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.21 (Check SSN) Validates a Social Security number in the format DDD-DD-DDDD
 * with proper resource management and exception handling.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a Social Security number in the format DDD-DD-DDDD: ";
        std::string user_input;
        if (!std::getline(std::cin, user_input))
        {
            std::cout << "Error: Input cannot be empty.\n";
            return EXIT_SUCCESS;
        }

        // Trim leading and trailing whitespace
        size_t start = user_input.find_first_not_of(" \t\n\r");
        if (start == std::string::npos)
        {
            std::cout << "Error: Input cannot be empty.\n";
            return EXIT_SUCCESS;
        }
        size_t end = user_input.find_last_not_of(" \t\n\r");
        user_input = user_input.substr(start, end - start + 1);

        const std::regex ssn_pattern(R"(^\d{3}-\d{2}-\d{4}$)");

        if (std::regex_match(user_input, ssn_pattern))
        {
            std::cout << user_input << " is a valid social security number.\n";
        }
        else
        {
            std::cout << user_input << " is an invalid social security number.\n";
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