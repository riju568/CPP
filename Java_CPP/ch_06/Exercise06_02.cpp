#include <iostream>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * 6.2 (Sum the digits in an integer) Write a method that computes the
 * sum of the digits in an integer. Use the following method header:
 * int sum_digits(long long n)
 * For example, sum_digits(234) returns 9 (2 + 3 + 4).
 */
int sum_digits(long long n)
{
    int summed = 0;
    long long num1 = std::abs(n);

    while (num1 != 0)
    {
        summed += static_cast<int>(num1 % 10);
        num1 /= 10;
    }

    return summed;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter an integer with multiple digits: \n";
        long long number = 0;
        if (!(std::cin >> number))
        {
            std::cerr << "Error: Invalid input. Please enter a valid integer.\n";
            return EXIT_SUCCESS;
        }

        std::cout << sum_digits(number) << '\n';

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