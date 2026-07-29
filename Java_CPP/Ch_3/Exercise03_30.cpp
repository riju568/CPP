#include <iostream>
#include <chrono>
#include <cstdio>
#include <stdexcept>
/**
 * *3.30 (Current time) Revise Programming Exercise 2.8 to display the hour using a
 * 12-hour clock. Here is a sample run:
 * Enter the time zone offset to GMT: -5
 * The current time is 4:50:34 AM
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        int offset = 0;
        std::cout << "Enter the time zone offset to GMT: ";
        if (!(std::cin >> offset))
        {
            throw std::runtime_error("Please enter a valid integer for the time zone offset.");
        }
        auto now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        long long timeInMillis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
        long long secondsSinceJan1st1970 = timeInMillis / 1000;
        long long second = secondsSinceJan1st1970 % 60;
        long long minutesSinceJan1st1970 = secondsSinceJan1st1970 / 60;
        long long minute = minutesSinceJan1st1970 % 60;
        long long hoursSinceJan1st1970 = minutesSinceJan1st1970 / 60;
        long long totalHours = (hoursSinceJan1st1970 + offset) % 24;
        if (totalHours < 0)
        {
            totalHours += 24;
        }

        bool pm = totalHours >= 12;
        long long hour = totalHours % 12;
        if (hour == 0)
        {
            hour = 12; 
        }

        std::printf("The current time is %lld:%02lld:%02lld %s\n", hour, minute, second, (pm ? "PM" : "AM"));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}