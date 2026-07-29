#include <iostream>
#include <exception>
/**
 * 2.11 (Population projection) Rewrite Programming Exercise 1.11 to prompt the user
 * to enter the number of years and displays the population after the number of years.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        long long currentPopulation = 312032486;
        std::cout << "Enter the number of years: ";
        int numberOfYears = 0;
        if (!(std::cin >> numberOfYears))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double secondsInYear = 365.0 * 24.0 * 60.0 * 60.0;
        const double birthsPerYear = secondsInYear / 7.0;
        const double deathsPerYear = secondsInYear / 13.0;
        const double immigrantsPerYear = secondsInYear / 45.0;

        const double netChangePerYear = birthsPerYear + immigrantsPerYear - deathsPerYear;
        const long long futurePopulation = currentPopulation + static_cast<long long>(netChangePerYear * numberOfYears);

        std::cout << "The population in " << numberOfYears << " years is " << futurePopulation << '\n';
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