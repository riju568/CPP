#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>

/**
 * 5.1 (Count positive and negative numbers and compute the average of numbers)
 * Reads an unspecified number of integers until 0 is entered, counts positive and
 * negative values, and computes total and average with proper resource management
 * and exception handling.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter any integer, positive or negative (the program ends when you enter 0): \n";

        int number = 0;
        if (!(std::cin >> number))
        {
            std::cerr << "Error: Invalid input. Please enter valid integers only.\n";
            return EXIT_SUCCESS;
        }

        if (number == 0)
        {
            std::cout << "No numbers are entered except 0\n";
            return EXIT_SUCCESS;
        }

        int pos = 0;
        int neg = 0;
        double total = 0.0;

        while (number != 0)
        {
            if (number > 0)
            {
                pos++;
            }
            else
            {
                neg++;
            }

            total += number;

            if (!(std::cin >> number))
            {
                std::cerr << "Error: Invalid input. Please enter valid integers only.\n";
                return EXIT_SUCCESS;
            }
        }

        int count = pos + neg;
        double average = total / count;

        std::cout << "The number of positives is: " << pos << '\n';
        std::cout << "The number of negatives is: " << neg << '\n';
        std::cout << "The total is: " << total << '\n';
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "The average is: " << average << '\n';

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