#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <algorithm>

/**
 * 7.5 (Print distinct numbers) Write a program that reads in ten numbers and
 * displays the number of distinct numbers and the distinct numbers in their
 * input order and separated by exactly one space (i.e., if a number appears
 * multiple times, it is displayed only once).
 */

bool is_distinct(const std::vector<int> &a, int size, int number)
{
    for (int i = 0; i < size; ++i)
    {
        if (a[i] == number)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<int> nums(10);
        int counter = 0;

        std::cout << "Enter ten integers separated by spaces: ";

        for (int i = 0; i < 10; ++i)
        {
            int check_num = 0;
            if (!(std::cin >> check_num))
            {
                std::cerr << "Error: Invalid integer input for element " << i + 1 << ".\n";
                return EXIT_FAILURE;
            }

            if (is_distinct(nums, counter, check_num))
            {
                nums[counter] = check_num;
                counter++;
            }
        }

        std::cout << "The count of distinct numbers are " << counter << '\n';
        std::cout << "The distinct numbers are";

        for (int i = 0; i < counter; ++i)
        {
            std::cout << " " << nums[i];
        }
        std::cout << '\n';

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