#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <exception>
#include <cstdlib>
using u128 = unsigned __int128;
using u64 = unsigned long long;
/**
 * 10.21 (Divisible by 5 or 6) Find the first ten numbers greater than Long.MAX_VALUE
 * that are divisible by 5 or 6.
 */

static std::string u128_to_string(u128 val)
{
    if (val == 0) return "0";
    std::string str;
    while (val > 0)
    {
        str.push_back(static_cast<char>('0' + (val % 10)));
        val /= 10;
    }
    std::reverse(str.begin(), str.end());
    return str;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        constexpr u64 max_long = std::numeric_limits<long long>::max();
        u128 test_number = static_cast<u128>(max_long);
        int count = 0;
        while (count < 10)
        {
            ++test_number;
            bool div5 = (test_number % 5 == 0);
            bool div6 = (test_number % 6 == 0);

            if (div5 || div6)
            {
                std::string num_str = u128_to_string(test_number);
                if (div5)
                {
                    std::cout << num_str << " divided by 5 = " 
                              << u128_to_string(test_number / 5) << '\n';
                }
                if (div6)
                {
                    std::cout << num_str << " divided by 6 = " 
                              << u128_to_string(test_number / 6) << '\n';
                }
                ++count;
            }
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}static std::string u128_to_string(u128 val)
{
    if (val == 0) return "0";
    std::string str;
    while (val > 0)
    {
        str.push_back(static_cast<char>('0' + (val % 10)));
        val /= 10;
    }
    std::reverse(str.begin(), str.end());
    return str;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        constexpr u64 max_long = std::numeric_limits<long long>::max();
        u128 test_number = static_cast<u128>(max_long);
        int count = 0;
        while (count < 10)
        {
            ++test_number;
            bool div5 = (test_number % 5 == 0);
            bool div6 = (test_number % 6 == 0);
            if (div5 || div6)
            {
                std::string num_str = u128_to_string(test_number);

                if (div5)
                {
                    std::cout << num_str << " divided by 5 = " 
                              << u128_to_string(test_number / 5) << '\n';
                }
                if (div6)
                {
                    std::cout << num_str << " divided by 6 = " 
                              << u128_to_string(test_number / 6) << '\n';
                }
                ++count;
            }
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}