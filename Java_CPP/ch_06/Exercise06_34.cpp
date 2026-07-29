#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * **6.34 (Print calendar) Programming Exercise 3.21 uses Zeller’s congruence to calculate the day of the week.
 * Simplify Listing 6.12, PrintCalendar.java, using Zeller’s
 * algorithm to get the start day of the month.
 */

bool is_leap_year(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int last_day_of_month(int month, int year)
{
    int last_day = 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        last_day = 31;
    }
    else if (month == 2)
    {
        if (is_leap_year(year))
        {
            last_day = 29;
        }
        else
        {
            last_day = 28;
        }
    }
    else
    {
        last_day = 30;
    }
    return last_day;
}

int zellers_algo(int day_of_month, int month, int year)
{
    if (month == 1 || month == 2)
    {
        month = month + 12;
        year--;
    }
    int q = day_of_month;
    int m = month;
    int j = year / 100;
    int k = year % 100;
    return (q + (26 * (m + 1) / 10) + k + k / 4 + j / 4 + (5 * j)) % 7;
}

void print_calendar_header(int month, int year)
{
    const std::string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    std::cout << "\t\t" << months[month - 1] << "\t" << year << '\n';
    std::cout << "---------------------------\n";
    std::cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat\n";
}

void print_first_day(int month, int year)
{
    int first_day = zellers_algo(1, month, year);

    std::string leading_tabs = "1";

    for (int i = 1; i < first_day; ++i)
    {
        leading_tabs = "\t" + leading_tabs;
    }
    if (first_day == 0)
    {
        leading_tabs = "\t\t\t\t\t\t1";
    }

    std::cout << leading_tabs << "\t";
}

void print_calendar(int month, int year)
{
    int last_day = last_day_of_month(month, year);

    for (int i = 2; i <= last_day; ++i)
    {
        int printed_day = zellers_algo(i, month, year);
        if (printed_day == 1)
        {
            std::cout << '\n';
        }
        std::cout << i << "\t";
    }
    std::cout << '\n';
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        int year = 0;
        int month = 0;

        std::cout << "Enter year: ";
        if (std::cin >> year)
        {
            std::cout << "Enter month as number between 1 and 12: ";
            if (std::cin >> month)
            {
                print_calendar_header(month, year);
                print_first_day(month, year);
                print_calendar(month, year);
            }
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