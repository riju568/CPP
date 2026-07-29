#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * 7.8 (Average an array) Write two overloaded methods that return the average
 * of an array with the following headers (adapted to C++ equivalents):
 * int average(const std::vector<int> &array)
 * double average(const std::vector<double> &array)
 * Write a test program that prompts the user to enter ten double values,
 * invokes this method, and displays the average value.
 */

int average(const std::vector<int> &array)
{
    if (array.empty())
    {
        return 0;
    }
    int sum = 0;
    for (int value : array)
    {
        sum += value;
    }
    return sum / static_cast<int>(array.size());
}

double average(const std::vector<double> &array)
{
    if (array.empty())
    {
        return 0.0;
    }
    double sum = 0.0;
    for (double value : array)
    {
        sum += value;
    }
    return sum / static_cast<double>(array.size());
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<double> values(10);
        std::cout << "Please enter ten double values:\n";

        for (size_t i = 0; i < 10; ++i)
        {
            if (!(std::cin >> values[i]))
            {
                std::cerr << "Error: Invalid double input for element " << i + 1 << ".\n";
                return EXIT_FAILURE;
            }
        }

        double to_print = average(values);
        std::cout << to_print << '\n';

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