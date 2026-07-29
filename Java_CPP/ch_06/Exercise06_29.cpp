#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * **6.29 (Twin primes) Twin primes are a pair of prime numbers that differ by 2.
 * For example, 3 and 5 are twin primes, 5 and 7 are twin primes, and 11 and 13 are twin primes.
 * Write a program to find all twin primes less than 1,000. Display the output as follows:
 * (3, 5)
 * (5, 7)
 * ...
 */

bool is_prime(int num)
{
    if (num < 2)
    {
        return false;
    }
    bool prime = true;
    for (int i = 2; i <= (num / 2); ++i)
    {
        if (num % i == 0)
        {
            prime = false;
            break;
        }
    }
    return prime;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        int primes[1000] = {0};
        for (int i = 2; i < 1000; ++i)
        {
            if (is_prime(i))
            {
                primes[i] = 1;
            }
        }

        int twin_primes[1000][2] = {0};
        int j = 0;
        for (int i = 2; i < 1000; ++i)
        {
            if (primes[i] > 0)
            {
                if (i + 2 < 1000 && primes[i + 2] > 0)
                {
                    twin_primes[j][0] = i;
                    twin_primes[j][1] = i + 2;
                    j++;
                }
            }
        }

        for (int i = 0; i < 1000; ++i)
        {
            if (twin_primes[i][0] == 0)
            {
                break;
            }
            std::cout << "(" << twin_primes[i][0] << ", " << twin_primes[i][1] << ")\n";
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