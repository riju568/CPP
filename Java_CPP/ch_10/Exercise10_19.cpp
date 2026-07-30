#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

using u128 = unsigned __int128;
static bool is_small_prime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}
class BigInt
{
private:
    std::string digits; 

public:
    BigInt(unsigned long long val = 0)
    {
        if (val == 0) digits = "0";
        while (val > 0)
        {
            digits.push_back(static_cast<char>('0' + (val % 10)));
            val /= 10;
        }
    }
    BigInt(std::string str, bool reversed = false)
    {
        digits = std::move(str);
        if (!reversed)
        {
            std::reverse(digits.begin(), digits.end());
        }
    }
    [[nodiscard]] std::string to_string() const
    {
        std::string res = digits;
        std::reverse(res.begin(), res.end());
        return res;
    }
    static BigInt pow2_minus_1(int p)
    {
        std::vector<int> res;
        res.push_back(1);

        for (int i = 0; i < p; ++i)
        {
            int carry = 0;
            for (std::size_t j = 0; j < res.size(); ++j)
            {
                int prod = res[j] * 2 + carry;
                res[j] = prod % 10;
                carry = prod / 10;
            }
            if (carry > 0) res.push_back(carry);
        }
        res[0] -= 1;

        std::string str;
        for (int d : res) str.push_back(static_cast<char>('0' + d));
        return BigInt(str, true);
    }
};
static bool is_mersenne_prime(int p)
{
    if (p == 2) return true;
    if (p < 64)
    {
        u128 m_p = (static_cast<u128>(1) << p) - 1;
        u128 s = 4;
        for (int i = 0; i < p - 2; ++i)
        {
            u128 sq = s * s - 2;
            s = (sq & m_p) + (sq >> p);
            if (s >= m_p) s -= m_p;
        }
        return s == 0;
    }
    return p == 89;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << std::left << std::setw(6) << "p" 
                  << std::setw(35) << "2^p - 1" << "\n";
        std::cout << "---------------------------------------------\n";

        for (int p = 2; p <= 100; ++p)
        {
            // Mersenne numbers can only be prime if the exponent p is prime
            if (!is_small_prime(p)) continue;

            if (is_mersenne_prime(p))
            {
                BigInt mersenne = BigInt::pow2_minus_1(p);
                std::cout << std::left << std::setw(6) << p 
                          << std::setw(35) << mersenne.to_string() << "\n";
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