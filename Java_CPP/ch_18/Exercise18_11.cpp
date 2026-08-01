#include <iostream>
#include <cmath>
#include <exception>

long long sumDigits(long long n)
{
    n = std::abs(n); // Handle negative inputs safely
    if (n == 0)
    {
        return 0;
    }
    return (n % 10) + sumDigits(n / 10);
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter an integer: ";
        long long num = 0;

        if (!(std::cin >> num))
        {
            throw std::runtime_error("Invalid integer input.");
        }

        std::cout << "Sum of the digits in " << num << " is " << sumDigits(num) << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}