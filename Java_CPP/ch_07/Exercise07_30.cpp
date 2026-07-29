#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * *7.30 (Pattern recognition: consecutive four equal numbers) Tests whether 
 * the array has four consecutive numbers with the same value.
 */

// Tests whether the vector has four consecutive numbers with the same value.
bool isConsecutiveFour(const std::vector<int>& values)
{
    if (values.size() < 4)
    {
        return false;
    }

    int lastNum = values[0];
    int count = 1;

    for (size_t j = 1; j < values.size(); ++j)
    {
        if (values[j] == lastNum)
        {
            count++;
        }
        else
        {
            lastNum = values[j];
            count = 1;
        }

        if (count == 4)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    try
    {
        // Optimize standard I/O operations for cross-platform execution
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter the number of values: ";
        int len = 0;
        if (!(std::cin >> len))
        {
            std::cerr << "Invalid input! Please enter integer values only.\n";
            return EXIT_FAILURE;
        }

        if (len <= 0)
        {
            std::cout << "The list size must be greater than 0.\n";
            return EXIT_SUCCESS;
        }

        std::vector<int> nums(len);
        std::cout << "Enter the values: ";
        for (int i = 0; i < len; ++i)
        {
            if (!(std::cin >> nums[i]))
            {
                std::cerr << "Invalid input! Fewer elements provided than specified.\n";
                return EXIT_FAILURE;
            }
        }

        if (isConsecutiveFour(nums))
        {
            std::cout << "The list has consecutive fours.\n";
        }
        else
        {
            std::cout << "The list does not have consecutive fours.\n";
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}