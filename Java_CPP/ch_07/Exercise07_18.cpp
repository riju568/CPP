#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * 7.18 (Bubble sort) Write a sort method that uses the bubble-sort algorithm.
 * Write a test program that reads in ten double numbers, invokes the method, 
 * and displays the sorted numbers.
 */

void bubble_sort(std::vector<double> &arr)
{
    if (arr.empty() || arr.size() <= 1)
    {
        return;
    }

    bool swapped = false;
    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
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

        bubble_sort(numbers);

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