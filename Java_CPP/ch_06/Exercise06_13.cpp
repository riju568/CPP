#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>

/**
 * *6.13 (Sum series) Write a method to compute the following series:
 * m(i) = 1/2 + 2/3 + ... + i/(i + 1)
 * * Write a test program that displays the following table:
 * i                 m(i)
 * 1                 0.5000
 * 2                 1.1667
 * ...
 * 19                16.4023
 * 20                17.3546
 */

/**
 * Computes the series: m(i) = 1/2 + 2/3 + ... + i/(i + 1)
 */
double m(int i)
{
    double sum = 0.0;
    for (int j = 1; j <= i; ++j)
    {
        sum += static_cast<double>(j) / (j + 1.0);
    }
    return sum;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "i                 m(i)\n";
        std::cout << "__________________________\n";

        for (int i = 1; i <= 20; ++i)
        {
            std::cout << std::left << std::setw(18) << i
                      << std::fixed << std::setprecision(4) << m(i) << '\n';
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