#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <exception>
#include <cstdlib>

/**
 * ** 6.33 (Current date and time) Invoking System.currentTimeMillis() returns the
 * elapsed time in milliseconds since midnight of January 1, 1970. Write a program
 * that displays the date and time. Here is a sample run:
 * Current date and time is May 16, 2012 10:34:23
 */

std::string month_name(int m)
{
    switch (m)
    {
        case 1:  return "January";
        case 2:  return "February";
        case 3:  return "March";
        case 4:  return "April";
        case 5:  return "May";
        case 6:  return "June";
        case 7:  return "July";
        case 8:  return "August";
        case 9:  return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Error";
    }
}

std::string get_current_date_time(const std::string &time_zone_id)
{
    auto now = std::chrono::system_clock::now();
    std::time_t time_t_now = std::chrono::system_clock::to_time_t(now);

    long long offset_seconds = 0;
    if (time_zone_id == "EST")
    {
        offset_seconds = -5 * 3600; // EST is UTC-5
    }
    else if (time_zone_id == "GMT" || time_zone_id == "UTC")
    {
        offset_seconds = 0;
    }

    std::time_t adjusted_time = time_t_now + offset_seconds;
    std::tm *tm_ptr = std::gmtime(&adjusted_time);

    if (!tm_ptr)
    {
        return "Error";
    }

    int month = tm_ptr->tm_mon + 1;
    int day = tm_ptr->tm_mday;
    int year = tm_ptr->tm_year + 1900;
    int hour = tm_ptr->tm_hour;
    int minute = tm_ptr->tm_min;
    int second = tm_ptr->tm_sec;

    char buffer[128];
    std::snprintf(buffer, sizeof(buffer), "%s %d, %d %02d:%02d:%02d",
                  month_name(month).c_str(), day, year, hour, minute, second);
    return std::string(buffer);
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Current date and time is " << get_current_date_time("GMT") << " GMT\n";
        std::cout << "Current date and time is " << get_current_date_time("EST") << " EST\n";

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