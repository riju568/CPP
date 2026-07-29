#include <iostream>
#include <vector>
#include <random>
#include <exception>
#include <cstdlib>

/**
 * 7.7 (Count single digits) Write a program that generates 100 random
 * integers between 0 and 9 and displays the count for each number.
 */

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<int> counts(10, 0);
        
        // Modern C++ random number generation
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 9);

        for (int i = 0; i < 100; ++i)
        {
            int random_num = dis(gen);
            counts[random_num]++;
        }

        for (size_t i = 0; i < counts.size(); ++i)
        {
            std::cout << counts[i] << " counts of " << i << '\n';
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