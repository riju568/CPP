#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 7.27 (Identical arrays) Checks if two lists of integers are identical 
 * (have the same contents regardless of order).
 */

// Returns true if list1 and list2 are identical (contain the same elements).
// Creates sorted copies of the input vectors to perform the check without mutating originals.
bool equals(const std::vector<int> &list1, const std::vector<int> &list2)
{
    if (list1.size() != list2.size())
    {
        return false;
    }

    std::vector<int> sorted1 = list1;
    std::vector<int> sorted2 = list2;

    std::sort(sorted1.begin(), sorted1.end());
    std::sort(sorted2.begin(), sorted2.end());

    return sorted1 == sorted2;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter list 1: ";
        int l1_size = 0;
        if (!(std::cin >> l1_size))
        {
            std::cout << "Invalid input: Expected an integer for list 1 size.\n";
            return EXIT_FAILURE;
        }
        if (l1_size < 0)
        {
            std::cout << "List size cannot be negative.\n";
            return EXIT_SUCCESS;
        }

        std::vector<int> l1(l1_size);
        for (int i = 0; i < l1_size; ++i)
        {
            if (!(std::cin >> l1[i]))
            {
                std::cout << "Invalid input: Fewer elements provided than specified for list 1.\n";
                return EXIT_FAILURE;
            }
        }

        std::cout << "Enter list 2: ";
        int l2_size = 0;
        if (!(std::cin >> l2_size))
        {
            std::cout << "Invalid input: Expected an integer for list 2 size.\n";
            return EXIT_FAILURE;
        }
        if (l2_size < 0)
        {
            std::cout << "List size cannot be negative.\n";
            return EXIT_SUCCESS;
        }

        std::vector<int> l2(l2_size);
        for (int i = 0; i < l2_size; ++i)
        {
            if (!(std::cin >> l2[i]))
            {
                std::cout << "Invalid input: Fewer elements provided than specified for list 2.\n";
                return EXIT_FAILURE;
            }
        }

        if (equals(l1, l2))
        {
            std::cout << "Two lists are identical\n";
        }
        else
        {
            std::cout << "The two lists are not identical\n";
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