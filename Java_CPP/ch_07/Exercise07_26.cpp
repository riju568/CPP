#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * 7.26 (Strictly identical arrays) Checks if two lists of integers 
 * are strictly identical (same length and corresponding elements).
 */

// Returns true if list1 and list2 are strictly identical.
bool equals(const std::vector<int> &list1, const std::vector<int> &list2)
{
    if (list1.size() != list2.size())
    {
        return false;
    }

    for (size_t i = 0; i < list1.size(); ++i)
    {
        if (list1[i] != list2[i])
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

        std::cout << "Enter list1: ";
        int length1 = 0;
        if (!(std::cin >> length1))
        {
            std::cout << "Invalid input: Expected an integer for list1 length.\n";
            return EXIT_FAILURE;
        }
        if (length1 < 0)
        {
            std::cout << "List length cannot be negative.\n";
            return EXIT_SUCCESS;
        }

        std::vector<int> list1(length1);
        for (int i = 0; i < length1; ++i)
        {
            if (!(std::cin >> list1[i]))
            {
                std::cout << "Invalid input: Fewer elements provided than specified for list1.\n";
                return EXIT_FAILURE;
            }
        }

        std::cout << "Enter list2: ";
        int length2 = 0;
        if (!(std::cin >> length2))
        {
            std::cout << "Invalid input: Expected an integer for list2 length.\n";
            return EXIT_FAILURE;
        }
        if (length2 < 0)
        {
            std::cout << "List length cannot be negative.\n";
            return EXIT_SUCCESS;
        }

        std::vector<int> list2(length2);
        for (int i = 0; i < length2; ++i)
        {
            if (!(std::cin >> list2[i]))
            {
                std::cout << "Invalid input: Fewer elements provided than specified for list2.\n";
                return EXIT_FAILURE;
            }
        }

        if (equals(list1, list2))
        {
            std::cout << "The lists are strictly identical\n";
        }
        else
        {
            std::cout << "The lists are NOT strictly identical\n";
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