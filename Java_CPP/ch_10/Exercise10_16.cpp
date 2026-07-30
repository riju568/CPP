#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 10.16 (Divisible by 2 or 3) Find the first ten numbers with 50 decimal digits that are
 * divisible by 2 or 3.
 */
static void increment_big_int_string(std::string &s)
{
    int carry = 1;
    for (int i = static_cast<int>(s.length()) - 1; i >= 0 && carry > 0; --i)
    {
        int sum = (s[i] - '0') + carry;
        s[i] = static_cast<char>('0' + (sum % 10));
        carry = sum / 10;
    }
    if (carry > 0)
    {
        s.insert(s.begin(), '1');
    }
}
static std::string divide_big_int_string(const std::string &num, int divisor)
{
    std::string result;
    int remainder = 0;

    for (char c : num)
    {
        int current = remainder * 10 + (c - '0');
        result += static_cast<char>('0' + (current / divisor));
        remainder = current % divisor;
    }
    std::size_t start = result.find_first_not_of('0');
    return (start != std::string::npos) ? result.substr(start) : "0";
}
static int remainder_big_int_string(const std::string &num, int divisor)
{
    int remainder = 0;
    for (char c : num)
    {
        remainder = (remainder * 10 + (c - '0')) % divisor;
    }
    return remainder;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::string big_num(50, '0');
        big_num[0] = '1';
        int count = 0;
        while (count < 10)
        {
            int rem2 = remainder_big_int_string(big_num, 2);
            int rem3 = remainder_big_int_string(big_num, 3);

            if (rem2 == 0 || rem3 == 0)
            {
                if (rem2 == 0)
                {
                    std::cout << big_num << " divided by 2 = "  << divide_big_int_string(big_num, 2) << '\n';
                }
                if (rem3 == 0)
                {
                    std::cout << big_num << " divided by 3 = " 
                              << divide_big_int_string(big_num, 3) << '\n';
                }
                ++count;
            }

            increment_big_int_string(big_num);
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}