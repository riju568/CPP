#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>

/**
 * 6.9 (Conversions between feet and meters) Write a class that contains the following
 * two methods:
 * Convert from feet to meters
 * double foot_to_meter(double foot)
 * Convert from meters to feet
 * double meter_to_foot(double meter)
 * The formula for the conversion is:
 * meter = 0.305 * foot
 * foot = 3.279 * meter
 */

constexpr double foot_to_meter(double foot)
{
    return 0.305 * foot;
}

constexpr double meter_to_foot(double meter)
{
    return 3.279 * meter;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Feet                Meters              |            Meters                      Feet\n";
        std::cout << "___________________________________________________________________________________\n";

        for (int f = 1, m = 20; f <= 10; ++f, m += 5)
        {
            double feet = static_cast<double>(f);
            double meters = static_cast<double>(m);

            if (f <= 9)
            {
                std::cout << ' ';
            }

            std::cout << std::fixed << std::setprecision(1) << feet
                      << "                "
                      << std::setprecision(3) << foot_to_meter(feet)
                      << "              |            "
                      << std::setprecision(1) << meters
                      << "                  "
                      << std::setprecision(3) << meter_to_foot(meters)
                      << '\n';
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