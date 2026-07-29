#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 7.15 (Eliminate duplicates) Write a method that returns
 * a new array by eliminating the duplicate values in the array.
 * std::vector<int> eliminate_duplicates(const std::vector<int> &list)
 * Write a test program that reads in ten integers, invokes the method,
 * and displays the numbers separated by exactly one space.
 */

std::vector<int> eliminate_duplicates(const std::vector<int> &list)
{
    std::vector<int> list2;
    for (int val : list)
    {
        bool dup = false;
        for (int k : list2)
        {
            if (k == val)
            {
                dup = true;
                break;
            }
        }
        if (!dup)
        {
            list2.push_back(val);
        }
    }
    return list2;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<int> list(10);
        std::cout << "Enter ten integers:\n";

        for (size_t i = 0; i < list.size(); ++i)
        {
            if (!(std::cin >> list[i]))
            {
                std::cerr << "Error: Invalid integer input for element " << i + 1 << ".\n";
                return EXIT_FAILURE;
            }
        }

        std::sort(list.begin(), list.end());
        std::vector<int> finished_array = eliminate_duplicates(list);

        std::cout << "The number of distinct integers is: " << finished_array.size() << '\n';
        std::cout << "The distinct integers are: ";

        for (size_t i = 0; i < finished_array.size(); ++i)
        {
            std::cout << finished_array[i] << (i + 1 < finished_array.size() ? " " : "");
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