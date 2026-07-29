#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * 7.20 (Revise selection sort) In Section 7.11, you used selection sort to sort an array.
 * The selection-sort method repeatedly finds the smallest number in the current array and
 * swaps it with the first. Write a new sort method that sorts the array from the other
 * end, repeatedly finding the largest number in the current array and swapping it with the last.
 * Write a test program that reads in ten double numbers, invokes the method, 
 * and displays the sorted numbers.
 */

void selection_sort(std::vector<double> &arr)
{
    if (arr.empty() || arr.size() <= 1)
    {
        return;
    }

    for (int i = static_cast<int>(arr.size()) - 1; i > 0; --i)
    {
        double current_max = arr[0];
        int current_index = 0;

        for (int j = 1; j <= i; ++j)
        {
            if (arr[j] > current_max)
            {
                current_max = arr[j];
                current_index = j;
            }
        }

        if (current_index != i)
        {
            arr[current_index] = arr[i];
            arr[i] = current_max;
        }
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<double> numbers(10);
        std::cout << "Enter ten decimal numbers: ";

        for (size_t i = 0; i < numbers.size(); ++i)
        {
            if (!(std::cin >> numbers[i]))
            {
                std::cerr << "Error: Invalid double input for element " << i + 1 << ".\n";
                return EXIT_FAILURE;
            }
        }

        selection_sort(numbers);

        std::cout << "The sorted numbers are: ";
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            std::cout << numbers[i] << (i + 1 < numbers.size() ? " " : "");
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