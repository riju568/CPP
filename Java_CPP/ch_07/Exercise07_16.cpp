#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <exception>
#include <cstdlib>

/**
 * 7.16 (Execution time) Write a program that randomly generates an array of 100,000
 * integers and a key.
 * 1.) Estimate the execution time of linear search.
 * 2.) Sort the array and estimate the execution time of binary search.
 */

int assign_random_key(const std::vector<int> &list)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, static_cast<int>(list.size()) - 1);
    return list[dis(gen)];
}

std::vector<int> generate_array_of_random_integers(int len)
{
    std::vector<int> res(len);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1'000'000);

    for (int i = 0; i < len; ++i)
    {
        res[i] = dis(gen);
    }
    return res;
}

int binary_search(const std::vector<int> &list, int key)
{
    int low = 0;
    int high = static_cast<int>(list.size()) - 1;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (key < list[mid])
        {
            high = mid - 1;
        }
        else if (key == list[mid])
        {
            return mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return (low * -1) - 1;
}

int linear_search(const std::vector<int> &list, int key)
{
    for (size_t i = 0; i < list.size(); ++i)
    {
        if (key == list[i])
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void print_array(const std::vector<int> &array)
{
    for (size_t i = 0; i < std::min(static_cast<size_t>(1000), array.size()); ++i)
    {
        std::cout << array[i] << " ";
        if (i % 20 == 0 && i > 0)
        {
            std::cout << '\n';
        }
    }
    std::cout << "\n..........\n";
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<int> randoms = generate_array_of_random_integers(100'000);
        int search_key_random = assign_random_key(randoms);

        // Estimate execution time of linear search using high_resolution_clock
        auto start_time = std::chrono::high_resolution_clock::now();
        int lin_sear_res = linear_search(randoms, search_key_random);
        auto end_time = std::chrono::high_resolution_clock::now();
        
        auto execution_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

        std::cout << "Linear search took: " << execution_time << " ms\n";
        std::cout << "The method returned index# : " << lin_sear_res << '\n';
        std::cout << "Search key was " << search_key_random << " and value at index# " << lin_sear_res << " is " << randoms[lin_sear_res] << "\n\n";

        // Sort array and estimate execution time of binary search
        std::sort(randoms.begin(), randoms.end());
        search_key_random = assign_random_key(randoms);

        auto start_time2 = std::chrono::high_resolution_clock::now();
        int bi_sear_res = binary_search(randoms, search_key_random);
        auto end_time2 = std::chrono::high_resolution_clock::now();
        
        auto execution_time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time2 - start_time2).count();

        std::cout << "Binary search took " << execution_time2 << " ms\n";
        std::cout << "The method returned index# : " << bi_sear_res << '\n';
        std::cout << "Search key was " << search_key_random << " and value at index# " << bi_sear_res << " is " << randoms[bi_sear_res] << '\n';
        
        print_array(randoms);

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