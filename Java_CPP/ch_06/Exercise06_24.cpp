#include <iostream>
#include <string>
#include <chrono>
#include <exception>
#include <cstdlib>

/**
 * **6.24 (Display current date and time) Listing 2.7, ShowCurrentTime.java, displays the
 * current time. Improve this example to display the current date and time.
 * The calendar example in Listing 6.12, PrintCalendar.java, should give you some ideas on
 * how to find the year, month, and day.
 */

// Global variables to hold state during calendar calculations (matching Java implementation)
static int days_elapsed_current_year = 0;
static int days_elapsed_current_month = 0;

constexpr bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

constexpr int number_of_days_in_a_year(int year)
{
    return is_leap_year(year) ? 366 : 365;
}

constexpr int get_number_of_days_in_month(int year, int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12)
    {
        return 31;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    if (month == 2)
    {
        return is_leap_year(year) ? 29 : 28;
    }
    return 0;
}

int get_year(int total_days)
{
    int year = 1970;
    while (total_days >= number_of_days_in_a_year(year))
    {
        total_days -= number_of_days_in_a_year(year);
        year++;
    }
    days_elapsed_current_year = total_days + 1; // 1-based day index in current year
    return year;
}

int get_current_month(int year, int days_elapsed_in_year)
{
    int month = 1;
    while (days_elapsed_in_year > get_number_of_days_in_month(year, month))
    {
        days_elapsed_in_year -= get_number_of_days_in_month(year, month);
        month++;
    }
    days_elapsed_current_month = days_elapsed_in_year;
    return month;
}

std::string get_current_date(long long millis)
{
    long long seconds = millis / 1000;
    long long min = seconds / 60;
    long long hours = min / 60;
    long long days = hours / 24;

    int year = get_year(static_cast<int>(days));
    int month = get_current_month(year, days_elapsed_current_year);

    return std::to_string(month) + "/" + std::to_string(days_elapsed_current_month) + "/" + std::to_string(year);
}

std::string get_current_time(long long millis)
{
    long long seconds = millis / 1000;
    long long current_second = seconds % 60;

    long long min = seconds / 60;
    long long current_min = min % 60;

    long long hours = min / 60;
    long long current_hour = hours % 24;

    return std::to_string(current_hour) + ":" + std::to_string(current_min) + ":" + std::to_string(current_second) + "(GMT)";
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        long long current_time_millis = std::chrono::duration_cast<std::chrono::milliseconds>(
                                           std::chrono::system_clock::now().time_since_epoch())
                                           .count();

        std::string time = get_current_time(current_time_millis);
        std::string date = get_current_date(current_time_millis);

        std::cout << "The current date is " << date << ". And the current time is " << time << '\n';

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