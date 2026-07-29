#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * **7.32 (Partition of a list) Partitions the list using the
 * first element, called a pivot.
 */

// Helper function to swap two elements in a vector
void swap(std::vector<int>& list, size_t i, size_t j)
{
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

// Partitions the list using the first element as a pivot in linear O(N) time
int partition(std::vector<int>& list)
{
    if (list.empty())
    {
        return -1;
    }

    int pivot = list[0];
    int low = 1;
    int high = static_cast<int>(list.size()) - 1;

    // Two-pointer scan: takes at most list.size() comparisons total
    while (high > low)
    {
        while (low <= high && list[low] <= pivot)
        {
            low++;
        }
        while (low <= high && list[high] > pivot)
        {
            high--;
        }

        if (high > low)
        {
            swap(list, low, high);
        }
    }

    while (high > 0 && list[high] >= pivot)
    {
        high--;
    }

    // Place the pivot into its correct partition index
    if (pivot > list[high])
    {
        list[0] = list[high];
        list[high] = pivot;
        return high;
    }
    else
    {
        return 0;
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter list: ";
        int length = 0;
        if (!(std::cin >> length))
        {
            std::cerr << "Invalid input! Please enter integer values only.\n";
            return EXIT_FAILURE;
        }
        if (length <= 0)
        {
            std::cout << "List size must be greater than 0.\n";
            return EXIT_SUCCESS;
        }
        std::vector<int> list(length);
        for (int i = 0; i < length; ++i)
        {
            if (!(std::cin >> list[i]))
            {
                std::cerr << "Invalid input! Fewer elements provided than specified.\n";
                return EXIT_FAILURE;
            }
        }

        int indexOfPivot = partition(list);

        std::cout << "After the partition, the list is ";
        for (size_t i = 0; i < list.size(); ++i)
        {
            std::cout << list[i] << (i + 1 < list.size() ? " " : "");
        }
        std::cout << "\nPivot point index is " << indexOfPivot << '\n';
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