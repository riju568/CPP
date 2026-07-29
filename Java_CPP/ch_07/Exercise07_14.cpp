#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * 7.14 (Computing gcd) Write a method that returns the gcd of an
 * unspecified number of integers.
 * int gcd(const std::vector<int> &numbers)
 * Write a test program that prompts the user to enter five numbers,
 * invokes the method to find the gcd of these numbers, and displays the gcd.
 */

int compute_gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return std::abs(a);
}

int gcd(const std::vector<int> &numbers)
{
    if (numbers.empty())
    {
        return 0;
    }

    int result = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i)
    {
        result = compute_gcd(result, numbers[i]);
        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<int> nums_to_find(5);
        std::cout << "Please enter 5 numbers now to find their GCD:\n";

        for (size_t i = 0; i < nums_to_find.size(); ++i)
        {
            if (!(std::cin >> nums_to_find[i]))
            {
                std::cerr << "Error: Invalid integer input for element " << i + 1 << ".\n";
                return EXIT_FAILURE;
            }
        }

        std::cout << "The GCD of these 5 integers is " << gcd(nums_to_find) << '\n';

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