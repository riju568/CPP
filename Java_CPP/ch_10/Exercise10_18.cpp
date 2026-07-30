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
 * 10.18 (Large prime numbers) Write a program that finds five prime numbers larger
 * than Long.MAX_VALUE.
 */
static u128 power_mod(u128 base, u128 exp, u128 mod)
{
    u128 res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

static bool miller_rabin_test(u64 n, u64 a)
{
    if (n % a == 0)
        return false;

    u64 d = n - 1;
    int s = 0;
    while ((d & 1) == 0)
    {
        d >>= 1;
        ++s;
    }
    u128 x = power_mod(a, d, n);
    if (x == 1 || x == n - 1)
        return true;

    for (int r = 1; r < s; ++r)
    {
        x = (x * x) % n;
        if (x == n - 1)
            return true;
    }
    return false;
}

static bool is_prime(u64 n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    static const u64 bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (u64 a : bases)
    {
        if (n <= a)
            break;
        if (!miller_rabin_test(n, a))
            return false;
    }
    return true;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        constexpr u64 max_long = std::numeric_limits<long long>::max();
        u64 current = max_long + 1;

        if (current % 2 == 0)
            ++current;

        std::vector<u64> primes;
        primes.reserve(5);

        while (primes.size() < 5)
        {
            if (is_prime(current))
            {
                primes.push_back(current);
            }
            current += 2;
        }

        std::cout << "The first 5 prime numbers larger than Long.MAX_VALUE (" << max_long << ") are:\n[\n";
        for (std::size_t i = 0; i < primes.size(); ++i)
        {
            std::cout << "  " << primes[i] << (i + 1 < primes.size() ? ",\n" : "\n");
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