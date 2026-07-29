#include <iostream>
#include <exception>
#include <cstdlib>

/**
 * *6.16 (Number of days in a year) Write a method that returns the number of days in a
 * year using the following header:
 * int number_of_days_in_a_year(int year)
 * Write a test program that displays the number of days in year from 2000 to 2020.
 */

constexpr bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

constexpr int number_of_days_in_a_year(int year)
{
    return is_leap_year(year) ? 366 : 365;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Year          Total Days\n";
        std::cout << "__________________________\n";

        for (int yr = 2000; yr <= 2020; ++yr)
        {
            std::cout << yr << "              " << number_of_days_in_a_year(yr) << '\n';
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