#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.26 (Financial application: monetary units) Extracts dollars and cents
 * using find and substr methods with proper exception handling and memory management.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter an amount in double, for example 11.56: ";
        std::string num_str;
        if (!(std::cin >> num_str))
        {
            std::cout << "Error: An error occurred while reading input.\n";
            return EXIT_SUCCESS;
        }
        size_t decimal_index = num_str.find('.');
        if (decimal_index == std::string::npos)
        {
            std::cout << "Error: Please include a decimal point (e.g., 11.56 or 11.00).\n";
            return EXIT_SUCCESS;
        }
        std::string dollars = num_str.substr(0, decimal_index);
        std::string cents_str = num_str.substr(decimal_index + 1);
        if (cents_str.length() == 1)
        {
            cents_str += "0";
        }
        else if (cents_str.length() > 2)
        {
            cents_str = cents_str.substr(0, 2);
        }

        int change = 0;
        try
        {
            change = std::stoi(cents_str);
        }
        catch (const std::exception &)
        {
            std::cerr << "Error: Input contains invalid characters. Please enter a valid decimal number.\n";
            return EXIT_SUCCESS;
        }
        int quarters = change / 25;
        change %= 25;
        int dimes = change / 10;
        change %= 10;
        int nickels = change / 5;
        change %= 5;
        int pennies = change;

        // Output results
        std::cout << "Your amount " << num_str << " consists of\n";
        std::cout << "  " << dollars << " dollars\n";
        std::cout << "  " << quarters << " quarters\n";
        std::cout << "  " << dimes << " dimes\n";
        std::cout << "  " << nickels << " nickels\n";
        std::cout << "  " << pennies << " pennies\n";

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