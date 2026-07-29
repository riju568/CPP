#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <map>

/**
 * 7.3 (Count occurrence of numbers) Write a program that reads the integers between 1
 * and 100 and counts the occurrences of each. Assume the input ends with 0.
 */

void count_occurrences(const std::vector<int> &list)
{
    // Using a map to count occurrences while preserving sorted order of keys (1 to 100)
    std::map<int, int> occurrences;

    for (int num : list)
    {
        if (num >= 1 && num <= 100)
        {
            occurrences[num]++;
        }
    }

    for (const auto &pair : occurrences)
    {
        int num = pair.first;
        int count = pair.second;
        std::cout << num << " occurs " << count << (count > 1 ? " times" : " time") << '\n';
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::cout << "Enter the integers between 1 and 100 (enter 0 to end):\n";
        std::vector<int> valid_nums;
        int temp = 0;

        while (true)
        {
            if (!(std::cin >> temp))
            {
                std::cerr << "Error: Invalid integer input.\n";
                return EXIT_FAILURE;
            }

            if (temp == 0)
            {
                break;
            }

            if (temp >= 1 && temp <= 100)
            {
                valid_nums.push_back(temp);
            }
        }

        count_occurrences(valid_nums);

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