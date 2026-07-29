#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 7.9 (Find the smallest element) Write a method that finds the smallest element in an
 * array of double values using the following header (adapted to C++ equivalents):
 * double min(const std::vector<double> &array)
 * Write a test program that prompts the user to enter ten numbers, invokes this
 * method to return the minimum value, and displays the minimum value.
 */

double min(const std::vector<double> &array)
{
    if (array.empty())
    {
        return 0.0;
    }
    double minimum = array[0];
    for (size_t i = 1; i < array.size(); ++i)
    {
        minimum = std::min(minimum, array[i]);
    }
    return minimum;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::vector<double> a(10);
        std::cout << "Enter ten numbers:\n";

        for (size_t i = 0; i < 10; ++i)
        {
            if (!(std::cin >> a[i]))
            {
                std::cerr << "Error: Invalid double input for element " << i + 1 << ".\n";
                return EXIT_FAILURE;
            }
        }
        std::cout << "The minimum number is: " << min(a) << '\n';
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