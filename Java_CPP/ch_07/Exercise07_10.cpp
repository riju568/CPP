#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * 7.10 (Find the index of the smallest element) Write a method that returns the index of
 * the smallest element in an array of numbers. If the number of such elements is
 * greater than 1, return the smallest index. Use the following header (adapted to C++ equivalents):
 * int index_of_smallest_element(const std::vector<double> &array)
 * Write a test program that prompts the user to enter ten numbers, invokes this
 * method to return the index of the smallest element, and displays the index.
 */

int index_of_smallest_element(const std::vector<double> &array)
{
    if (array.empty())
    {
        return -1;
    }

    double smallest = array[0];
    int small_idx = 0;

    for (size_t i = 1; i < array.size(); ++i)
    {
        if (array[i] < smallest)
        {
            smallest = array[i];
            small_idx = static_cast<int>(i);
        }
    }
    return small_idx;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::cout << "Enter ten numbers:\n";

        std::vector<double> nums(10);
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (!(std::cin >> nums[i]))
            {
                std::cerr << "Error: Invalid double input for element " << i + 1 << ".\n";
                return EXIT_FAILURE;
            }
        }

        int x = index_of_smallest_element(nums);
        if (x != -1)
        {
            std::cout << "Index of the smallest element is " << x << " with a value of " << nums[x] << '\n';
        }

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