#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * **6.28 (Mersenne prime) A prime number is called a Mersenne prime if it can be written
 * in the form 2^p - 1 for some positive integer p. Write a program that finds all
 * Mersenne primes with p <= 31 and displays the output.
 */

bool is_prime(long long n)
{
    if (n < 2)
    {
        return false;
    }
    for (long long i = 2; i <= std::sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

std::string mersenne_prime(int p)
{
    // Using long long to prevent potential overflow for larger powers up to 31 ($2^{31}-1$)
    long long pow_val = 1;
    for (int i = 0; i < p; ++i)
    {
        pow_val *= 2;
    }
    long long check_num = pow_val - 1;

    if (is_prime(check_num))
    {
        return std::to_string(p) + "   " + std::to_string(check_num) + "\n";
    }
    return "";
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "p   2^p-1\n";
        for (int p = 2; p <= 31; ++p)
        {
            std::cout << mersenne_prime(p);
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