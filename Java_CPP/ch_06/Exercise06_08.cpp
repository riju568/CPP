#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>

/**
 * 6.8 (Conversions between Celsius and Fahrenheit) Write a class that contains the following two methods:
 * double celsius_to_fahrenheit(double celsius)
 * double fahrenheit_to_celsius(double fahrenheit)
 * The formula for the conversion is:
 * fahrenheit = (9.0 / 5) * celsius + 32
 * celsius = (5.0 / 9) * (fahrenheit - 32)
 */

constexpr double celsius_to_fahrenheit(double celsius)
{
    return (9.0 / 5.0) * celsius + 32.0;
}

constexpr double fahrenheit_to_celsius(double fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Celsius     Fahrenheit    |     Fahrenheit    Celsius   \n";
        std::cout << "-------------------------------------------------------\n";

        double celsius = 40.0;
        double fahrenheit = 120.0;

        while (celsius >= 31.0 && fahrenheit >= 30.0)
        {
            std::cout << std::left << std::setw(12) << std::fixed << std::setprecision(1) << celsius
                      << std::left << std::setw(14) << std::fixed << std::setprecision(1) << celsius_to_fahrenheit(celsius)
                      << " |"
                      << std::right << std::setw(10) << std::fixed << std::setprecision(1) << fahrenheit
                      << std::right << std::setw(15) << std::fixed << std::setprecision(2) << fahrenheit_to_celsius(fahrenheit)
                      << '\n';

            celsius -= 1.0;
            fahrenheit -= 10.0;
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