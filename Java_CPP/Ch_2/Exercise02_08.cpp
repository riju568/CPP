#include <iostream>
#include <chrono>
#include <exception>
/**
 * 2.8 (Current time) Listing 2.7 ShowCurrentTime.java
 * gives a program that displays the current time in GMT.
 * Revise the program so that it prompts the user to enter the
 * time zone offset to GMT and displays the time in the specified
 * time zone.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter the time zone offset to GMT: ";

        int offset = 0;
        if (!(std::cin >> offset))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const auto now = std::chrono::system_clock::now();
        const auto duration = now.time_since_epoch();
        const long long totalMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
        const long long totalSeconds = totalMilliseconds / 1000;
        const long long currentSecond = totalSeconds % 60;
        const long long totalMinutes = totalSeconds / 60;
        const long long currentMinute = totalMinutes % 60;
        const long long totalHours = totalMinutes / 60;
        long long currentHour = totalHours % 24;
        currentHour = (currentHour + offset + 24) % 24;
        std::cout << "The current time is " << currentHour << ":"
                  << currentMinute << ":" << currentSecond << '\n';
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