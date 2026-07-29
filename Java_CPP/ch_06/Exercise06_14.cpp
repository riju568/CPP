#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * *6.14 (Estimate pi) pi can be computed using the following series:
 * m(i) = 4(1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 ... + (-1)^(i+1) / (2i - 1))
 * Write a method that returns m(i) for a given i and write a test program that displays the following table:
 * i                m(i)
 * 1                4.0000
 * 101              3.1515
 * 201              3.1466
 * 301              3.1449
 * 401              3.1441
 * 501              3.1436
 * 601              3.1433
 * 701              3.1430
 * 801              3.1428
 * 901              3.1427
 */
double pi(int num)
{
    double res = 0.0;
    for (int i = 1; i <= num; ++i)
    {
        res += std::pow(-1.0, i + 1) / (2 * i - 1);
    }
    return res * 4.0;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "i               m(i)\n";
        std::cout << "----------------------\n";

        for (int i = 1; i < 1000; i += 100)
        {
            std::cout << std::left << std::setw(16) << i
                      << std::fixed << std::setprecision(4) << pi(i) << '\n';
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