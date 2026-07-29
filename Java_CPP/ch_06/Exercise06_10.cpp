#include <iostream>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * 6.10 (Use the isPrime Method) Listing 6.7 PrimeNumberMethod.java provides
 * the is_prime(int number) method for testing whether a number is prime.
 * Use this method to find the number of prime numbers less than 10000.
 */
bool is_prime(int number)
{
    for (int divisor = 2; divisor <= std::sqrt(number); ++divisor)
    {
        if (number % divisor == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        int number = 2;
        int count = 0;

        while (number < 10000)
        {
            if (is_prime(number))
            {
                count++;
            }
            number++;
        }

        std::cout << "The number of prime numbers less than 10,000 is: " << count << '\n';

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