#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <string>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 10.17 (Square numbers) Find the first ten square numbers that are greater than
 * Long.MAX_VALUE. A square number is a number in the form of n2. For example, 4, 9, and 16 are square numbers.
 * Find an efficient approach to run your program fast.
 */

static std::string multiply_big_int_strings(const std::string &num1, const std::string &num2)
{
    std::size_t len1 = num1.size();
    std::size_t len2 = num2.size();
    std::vector<int> result(len1 + len2, 0);

    for (int i = static_cast<int>(len1) - 1; i >= 0; --i)
    {
        for (int j = static_cast<int>(len2) - 1; j >= 0; --j)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    std::string str_res;
    for (int num : result)
    {
        if (!(str_res.empty() && num == 0))
        {
            str_res.push_back(static_cast<char>(num + '0'));
        }
    }

    return str_res.empty() ? "0" : str_res;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        constexpr unsigned long long max_long = std::numeric_limits<long long>::max();
        auto start_root = static_cast<unsigned long long>(std::sqrt(max_long)) + 1;
        std::cout << "Long.MAX_VALUE = " << max_long << '\n';
        std::cout << "The first 10 square numbers greater than Long.MAX_VALUE are:\n[\n";
        for (int i = 0; i < 10; ++i)
        {
            unsigned long long current_root = start_root + i;
            std::string root_str = std::to_string(current_root);
            std::string square_str = multiply_big_int_strings(root_str, root_str);
            std::cout << "  " << square_str << (i < 9 ? ",\n" : "\n");
        }
        std::cout << "]\n";
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}