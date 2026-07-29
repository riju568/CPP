#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * 7.6 (Revise Listing 5.15, PrimeNumber.java)
 * Listing 5.15 determines whether a number n is prime by checking whether 2, 3, 4, 5, 6, ..., n/2 is a divisor.
 * If a divisor is found, n is not prime. A more efficient approach is to check whether any of the
 * prime numbers less than or equal to sqrt(n) can divide n evenly. If not, n is prime.
 * Rewrite Listing 5.15 to display the first 50 prime numbers using this approach.
 */

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        const int NUMBER_OF_PRIMES = 50;
        const int NUMBER_OF_PRIMES_PER_LINE = 10;
        std::vector<int> primes(NUMBER_OF_PRIMES);
        int count = 0;
        int number = 2;

        std::cout << "The first 50 prime numbers are \n\n";

        while (count < NUMBER_OF_PRIMES)
        {
            bool is_prime = true;

            for (int i = 0; i < count; ++i)
            {
                int prime = primes[i];
                if (prime * prime > number)
                {
                    break;
                }
                if (number % prime == 0)
                {
                    is_prime = false;
                    break;
                }
            }

            if (is_prime)
            {
                primes[count] = number;
                count++;

                if (count % NUMBER_OF_PRIMES_PER_LINE == 0)
                {
                    std::cout << number << '\n';
                }
                else
                {
                    std::cout << number << " ";
                }
            }

            number++;
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