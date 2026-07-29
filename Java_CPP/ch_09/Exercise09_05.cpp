#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

/**
 * *9.5 (Use the GregorianCalendar class) Java API has the GregorianCalendar class
 * in the java.util package, which you can use to obtain the year, month, and day of a
 * date. The no-arg constructor constructs an instance for the current date,
 * and the methods get(GregorianCalendar.YEAR), get(GregorianCalendar.MONTH),
 * and get(GregorianCalendar.DAY_OF_MONTH) return the year, month, and day.
 * Write a program to perform two tasks:
 * ■ Display the current year, month, and day.
 * ■ The GregorianCalendar class has the setTimeInMillis(long), which
 * can be used to set a specified elapsed time since January 1, 1970. Set the value
 * to 1234567898765L and display the year, month, and day.
 */


int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::time_t currentTime = std::time(nullptr);
        std::tm* currentInfo = std::localtime(&currentTime);
        if (currentInfo != nullptr) {
            int year = 1900 + currentInfo->tm_year;
            int month = currentInfo->tm_mon; // 0-indexed to match Java's GregorianCalendar.MONTH (0 = Jan)
            int day = currentInfo->tm_mday;
            std::cout << "Display the current year, month, and day: \n";
            std::cout << "Year: " << year << ", Month: " << month << ", Day of month: " << day << '\n';
        }
        std::cout << "Setting GregorianCalendar.setTimeInMillis(long) to 1234567898765L\n";
        const long long elapsedTimeMs = 1234567898765LL;
        std::time_t specifiedTime = static_cast<std::time_t>(elapsedTimeMs / 1000);
        std::tm* specifiedInfo = std::localtime(&specifiedTime);
        if (specifiedInfo != nullptr) {
            int year = 1900 + specifiedInfo->tm_year;
            int month = specifiedInfo->tm_mon; // 0-indexed
            int day = specifiedInfo->tm_mday;

            std::cout << "Year: " << year << ", Month: " << month << ", Day of month: " << day << '\n';
        }

        return EXIT_SUCCESS;
    } 
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}