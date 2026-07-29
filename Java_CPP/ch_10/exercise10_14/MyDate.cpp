#include <iostream>
#include <ctime>
#include <chrono>
#include <stdexcept>
#include <exception>
#include <cstdlib>
/**
 * *10.14 (The MyDate class) Design a class named MyDate. The class contains:
 * ■ The data fields year, month, and day that represent a date. month is 0-based (0 for Jan).
 * ■ A no-arg constructor that creates a MyDate object for the current date.
 * ■ A constructor that constructs a MyDate object with a specified elapsed time since Jan 1, 1970 UTC in milliseconds.
 * ■ A constructor that constructs a MyDate object with the specified year, month, and day.
 * ■ Getter methods for year, month, and day.
 * ■ A method named set_date(long long elapsed_time) that sets a new date for the object using elapsed time.
 */

class MyDate
{
private:
    int year;
    int month; // 0-based (0 = January, 11 = December)
    int day;

public:
    MyDate()
    {
        std::time_t current_time = std::time(nullptr);
        set_date_from_timestamp(current_time);
    }
    MyDate(long long elapsed_time)
    {
        set_date(elapsed_time);
    }
    MyDate(int year, int month, int day) : year(year), month(month), day(day) {}
    int get_year() const { return year; }
    void set_year(int y) { year = y; }
    int get_month() const { return month; }
    void set_month(int m) { month = m; }
    int get_day() const { return day; }
    void set_day(int d) { day = d; }
    void set_date(long long elapsed_time)
    {
        std::time_t seconds = static_cast<std::time_t>(elapsed_time / 1000);
        set_date_from_timestamp(seconds);
    }

private:
    void set_date_from_timestamp(std::time_t timestamp)
    {
        std::tm *time_info = std::gmtime(&timestamp);
        if (time_info == nullptr) { throw std::runtime_error("Error: Failed to process timestamp."); }
        year = time_info->tm_year + 1900;
        month = time_info->tm_mon; // 0-based month
        day = time_info->tm_mday;
    }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        MyDate my_date1;
        MyDate my_date2(34355555133101LL);
        MyDate my_date3(561555550000LL);
        std::cout << "MyDate1:\n year=" << my_date1.get_year() << "\n month=" << my_date1.get_month() << "\n day=" << my_date1.get_day() << "\n\n";
        std::cout << "MyDate2:\n year=" << my_date2.get_year() << "\n month=" << my_date2.get_month() << "\n day=" << my_date2.get_day() << "\n\n";
        std::cout << "MyDate3:\n year=" << my_date3.get_year() << "\n month=" << my_date3.get_month() << "\n day=" << my_date3.get_day() << '\n';
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