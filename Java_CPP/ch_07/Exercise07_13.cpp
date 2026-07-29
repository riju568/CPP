#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *7.13 (Random number chooser) Write a method that returns a random number between
 * 1 and 54, excluding the numbers passed in the argument.
 * int get_random(const std::vector<int> &numbers)
 */

int get_random(const std::vector<int> &numbers)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 54);

    while (true)
    {
        int random_int = dis(gen);
        bool is_excluded = false;

        for (int num : numbers)
        {
            if (random_int == num)
            {
                is_excluded = true;
                break;
            }
        }

        if (!is_excluded)
        {
            return random_int;
        }
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<int> excluded = {12, 13, 47};
        std::cout << "Random number is " << get_random(excluded) << '\n';

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