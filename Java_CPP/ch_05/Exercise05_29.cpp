#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

/**
 * 5.29 (Display calendars) Prompts the user for a year and the starting 
 * day of the year (0 = Sunday, 1 = Monday, ..., 6 = Saturday), then prints 
 * the formatted monthly calendar table for each month.
 */

bool isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}
std::string getMonthName(int month) {
    switch (month) {
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
        default: return "";
    }
}


int getNumberOfDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);

    try {
        std::cout << "Enter a year: ";
        int year = 0;
        if (!(std::cin >> year) || year < 0) {
            std::cerr << "Error: Invalid year entered.\n";
            return 1;
        }

        std::cout << "Enter the first day of the year (0 for Sun, 1 for Mon, ..., 6 for Sat): ";
        int startDay = 0;
        if (!(std::cin >> startDay) || startDay < 0 || startDay > 6) {
            std::cerr << "Error: First day must be between 0 and 6.\n";
            return 1;
        }

        std::cout << '\n';

        for (int month = 1; month <= 12; ++month) {
            std::string monthName = getMonthName(month);
            int days = getNumberOfDaysInMonth(month, year);

            std::cout << "          " << monthName << ' ' << year << "\n";
            std::cout << "-----------------------------\n";
            std::cout << " Sun Mon Tue Wed Thu Fri Sat\n";

            // Print leading spaces for alignment before day 1
            for (int i = 0; i < startDay; ++i) {
                std::cout << "    ";
            }
            for (int day = 1; day <= days; ++day) {
                std::cout << std::setw(4) << day;

                if ((day + startDay) % 7 == 0) {
                    std::cout << '\n';
                }
            }
            if ((days + startDay) % 7 != 0) {
                std::cout << '\n';
            }
            std::cout << "\n\n";
            startDay = (startDay + days) % 7;
        }

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}