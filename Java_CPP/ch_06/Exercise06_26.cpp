#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

/**
 * **6.26 (Palindromic prime) A palindromic prime is a prime number and also palindromic.
 * For example, 131 is a prime and also a palindromic prime, as are 313 and 757.
 * Write a program that displays the first 100 palindromic prime numbers.
 * Display 10 numbers per line, separated by exactly one space.
 */

bool check_palindrome(int num)
{
    std::string s = std::to_string(num);
    for (size_t i = 0, j = s.length() - 1; i < s.length() / 2; ++i, --j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

bool is_prime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i <= num / 2; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool is_palindromic_prime(int num)
{
    if (is_prime(num))
    {
        return check_palindrome(num);
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
            if (is_palindromic_prime(i))
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