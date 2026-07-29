#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * **7.31 (Merge two sorted lists) Merges two sorted lists into a new sorted list
 * using at most list1.size() + list2.size() comparisons.
 */

std::vector<int> merge(const std::vector<int> &list1, const std::vector<int> &list2)
{
    std::vector<int> result;
    result.reserve(list1.size() + list2.size());

    size_t idx1 = 0; // Pointer for list1
    size_t idx2 = 0; // Pointer for list2
    while (idx1 < list1.size() && idx2 < list2.size())
    {
        if (list1[idx1] <= list2[idx2])
        {
            result.push_back(list1[idx1++]);
        }
        else
        {
            result.push_back(list2[idx2++]);
        }
    }
    while (idx1 < list1.size())
    {
        result.push_back(list1[idx1++]);
    }
    while (idx2 < list2.size())
    {
        result.push_back(list2[idx2++]);
    }
    return result;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter list1: ";
        int n1 = 0;
        if (!(std::cin >> n1))
        {
            std::cerr << "Invalid input! Please enter integer values only.\n";
            return EXIT_FAILURE;
        }
        if (n1 < 0)
        {
            std::cerr << "List size cannot be negative.\n";
            return EXIT_FAILURE;
        }

        std::vector<int> list1(n1);
        for (int i = 0; i < n1; ++i)
        {
            if (!(std::cin >> list1[i]))
            {
                std::cerr << "Invalid input! Fewer elements provided than specified for list 1.\n";
                return EXIT_FAILURE;
            }
        }

        std::cout << "Enter list2: ";
        int n2 = 0;
        if (!(std::cin >> n2))
        {
            std::cerr << "Invalid input! Please enter integer values only.\n";
            return EXIT_FAILURE;
        }
        if (n2 < 0)
        {
            std::cerr << "List size cannot be negative.\n";
            return EXIT_FAILURE;
        }

        std::vector<int> list2(n2);
        for (int i = 0; i < n2; ++i)
        {
            if (!(std::cin >> list2[i]))
            {
                std::cerr << "Invalid input! Fewer elements provided than specified for list 2.\n";
                return EXIT_FAILURE;
            }
        }

        std::vector<int> mergedList = merge(list1, list2);

        std::cout << "The merged list is ";
        for (size_t i = 0; i < mergedList.size(); ++i)
        {
            std::cout << mergedList[i] << (i + 1 < mergedList.size() ? " " : "");
        }
        std::cout << '\n';

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