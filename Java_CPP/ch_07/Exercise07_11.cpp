#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * 7.11 (Statistics: compute deviation) Programming Exercise 5.45 computes the standard deviation of numbers.
 * This exercise uses a different but equivalent formula to
 * compute the standard deviation of n numbers.
 * Your program should contain the following methods (adapted to C++ equivalents):
 * double deviation(const std::vector<double> &x)
 * double mean(const std::vector<double> &x)
 * Write a test program that prompts the user to enter ten numbers and displays the
 * mean and standard deviation.
 */

double mean(const std::vector<double> &x)
{
    if (x.empty())
    {
        return 0.0;
    }
    double sum = 0.0;
    for (double d : x)
    {
        sum += d;
    }
    return sum / static_cast<double>(x.size());
}

double deviation(const std::vector<double> &x)
{
    if (x.size() <= 1)
    {
        return 0.0;
    }
    double m = mean(x);
    double numerator = 0.0;
    double denominator = static_cast<double>(x.size() - 1);

    for (double d : x)
    {
        numerator += std::pow((d - m), 2);
    }
    return std::sqrt(numerator / denominator);
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<double> nums(10);
        std::cout << "Enter 10 numbers: ";

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (!(std::cin >> nums[i]))
            {
                std::cerr << "Error: Invalid double input for element " << i + 1 << ".\n";
                return EXIT_FAILURE;
            }
        }

        double calculated_mean = mean(nums);
        double std = deviation(nums);

        std::cout.precision(2);
        std::cout << std::fixed;
        std::cout << "The mean is " << calculated_mean << '\n';

        std::cout.precision(5);
        std::cout << "The standard deviation is " << std << '\n';

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