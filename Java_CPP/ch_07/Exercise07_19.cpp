#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * 7.19 (Sorted?) Write the method that returns true if the list is already sorted
 * in increasing order.
 * bool is_sorted(const std::vector<int> &list)
 */

bool is_sorted(const std::vector<int> &list)
{
    if (list.empty())
    {
        return true;
    }
    for (size_t i = 0; i < list.size() - 1; ++i)
    {
        if (list[i] > list[i + 1])
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

        std::cout << "Enter list size: ";
        int size = 0;
        if (!(std::cin >> size))
        {
            std::cout << "Invalid input: Expected an integer for the list size.\n";
            return EXIT_FAILURE;
        }

        if (size < 0)
        {
            std::cout << "The list size cannot be negative.\n";
            return EXIT_SUCCESS;
        }

        std::vector<int> nums(size);
        std::cout << "Enter the elements of the list: ";
        for (int i = 0; i < size; ++i)
        {
            if (!(std::cin >> nums[i]))
            {
                std::cout << "Invalid input: Fewer elements provided than specified.\n";
                return EXIT_FAILURE;
            }
        }

        if (is_sorted(nums))
        {
            std::cout << "The list is already sorted\n";
        }
        else
        {
            std::cout << "The list is not sorted\n";
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