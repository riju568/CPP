#include <iostream>
#include <exception>
/**
 * 2.7 (Find the number of years)
 * Write a program that prompts the user to enter
 * the minutes (e.g., 1 billion), and displays the number
 * of years and days for the minutes. For simplicity, assume
 * a year has 365 days.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        constexpr long long MIN_IN_HOUR = 60;
        constexpr long long HOURS_IN_DAY = 24;
        constexpr long long DAYS_IN_YEAR = 365;

        std::cout << "Enter the number of minutes: ";

        long long minutes = 0;
        if (!(std::cin >> minutes))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const long long totalDays = minutes / (MIN_IN_HOUR * HOURS_IN_DAY);
        const long long years = totalDays / DAYS_IN_YEAR;
        const long long days = totalDays % DAYS_IN_YEAR;

        std::cout << minutes << " minutes is approximately " << years << " years and " << days << " days\n";
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