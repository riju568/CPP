#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *4.17 (Days of a month) Write a program that prompts the user to enter a year and the
 * first three letters of a month name (with the first letter in uppercase) and displays
 * the number of days in the month. Here is a sample run:
 * Enter a year: 2001
 * Enter a month: Jan
 * Jan 2001 has 31 days
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a year: ";
        int year = 0;
        if (!(std::cin >> year) || year < 0)
        {
            std::cout << "Invalid input for year. Please enter a valid year.\n";
            return EXIT_SUCCESS;
        }

        std::cout << "Enter a month: ";
        std::string month;
        if (!(std::cin >> month))
        {
            std::cout << "Invalid input for month.\n";
            return EXIT_SUCCESS;
        }

        int days = 0;

        if (month == "Apr" || month == "Jun" || month == "Sep" || month == "Nov")
        {
            days = 30;
        }
        else if (month == "Jan" || month == "Mar" || month == "May" ||
                 month == "Jul" || month == "Aug" || month == "Oct" || month == "Dec")
        {
            days = 31;
        }
        else if (month == "Feb")
        {
            bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            days = is_leap_year ? 29 : 28;
        }
        else
        {
            std::cout << month << " is not a correct month name\n";
            return EXIT_SUCCESS;
        }

        std::cout << month << " " << year << " has " << days << " days\n";

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}