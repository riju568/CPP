#include <iostream>
#include <iomanip>
#include <exception>
/**
 * (Population projection)
 * <p>
 * One birth every 7 seconds
 * One death every 13 seconds
 * One new immigrant every 45 seconds
 * Write a program to display the population for each of
 * the next five years.
 * Current population is 312,032,486 and a year is 365 days.
 */
namespace
{
    constexpr double changeToYears(double valueInSeconds)
    {
        const double secondsInYear = 60.0 * 60.0 * 24.0 * 365.0;
        return secondsInYear / valueInSeconds;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        const double birthInSeconds = 7.0;
        const double deathInSeconds = 13.0;
        const double immigrationInSeconds = 45.0;
        const double birthsPerYear = changeToYears(birthInSeconds);
        const double deathsPerYear = changeToYears(deathInSeconds);
        const double immigratePerYear = changeToYears(immigrationInSeconds);

        double currentPopulation = 312032486.0;

        for (int i = 1; i <= 5; ++i)
        {
            currentPopulation += birthsPerYear - deathsPerYear + immigratePerYear;

            std::cout << "The population in year " << i << " will be ";
            std::cout << std::fixed << std::setprecision(0) << currentPopulation << '\n';
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}