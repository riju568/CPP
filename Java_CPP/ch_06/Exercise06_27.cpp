#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * **6.27 (Emirp) An emirp (prime spelled backward) is a non-palindromic prime number
 * whose reversal is also a prime. For example, 17 is a prime and 71 is a prime, so 17
 * and 71 are emirps. Write a program that displays the first 100 emirps. Display 10
 * numbers per line, separated by exactly one space, as follows:
 * 13 17 31 37 71 73 79 97 107 113
 * 149 157 167 179 199 311 337 347 359 389
 * ...
 */

bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool check_palindrome(const std::string &num)
{
    for (size_t i = 0, j = num.length() - 1; i < num.length() / 2; ++i, --j)
    {
        if (num[i] != num[j])
        {
            return false;
        }
    }
    return true;
}

bool is_emirp(int n)
{
    if (is_prime(n))
    {
        std::string s = std::to_string(n);
        if (check_palindrome(s))
        {
            return false;
        }
        else
        {
            std::string reversed_s = s;
            std::reverse(reversed_s.begin(), reversed_s.end());
            int rev_num = std::stoi(reversed_s);
            return is_prime(rev_num);
        }
    }
    return false;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        int count = 1;
        int i = 2;

        while (count <= 100)
        {
            if (is_emirp(i))
            {
                std::cout << i << ' ';
                if (count % 10 == 0)
                {
                    std::cout << '\n';
                }
                count++;
            }
            ++i;
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