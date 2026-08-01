#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <exception>

class CalendarWrapper {
private:
    int year;
    int month;

public:
    CalendarWrapper() {
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        year = localTime->tm_year + 1900;
        month = localTime->tm_mon + 1; // tm_mon is 0-indexed
    }

    explicit CalendarWrapper(const std::string& monthStr) {
        month = std::stoi(monthStr);
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        year = localTime->tm_year + 1900;
    }

    CalendarWrapper(const std::string& monthStr, const std::string& yearStr) {
        month = std::stoi(monthStr);
        year = std::stoi(yearStr);
    }

    void printMonth() const {
        printMonthTitle(year, month);
        printMonthBody(year, month);
    }

    static void printMonthTitle(int y, int m) {
        std::cout << "          " << getMonthName(m) << " " << y << "\n";
        std::cout << "-----------------------------\n";
        std::cout << " Sun Mon Tue Wed Thu Fri Sat\n";
    }

    static std::string getMonthName(int m) {
        switch (m) {
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

    static void printMonthBody(int y, int m) {
        int startDay = getStartDay(y, m);
        int numberOfDaysInMonth = getNumberOfDaysInMonth(y, m);

        for (int i = 0; i < startDay; ++i) {
            std::cout << "    ";
        }

        for (int i = 1; i <= numberOfDaysInMonth; ++i) {
            std::cout << std::setw(4) << i;
            if ((i + startDay) % 7 == 0) {
                std::cout << "\n";
            }
        }
        std::cout << "\n";
    }

    static int getStartDay(int y, int m) {
        const int START_DAY_FOR_JAN_1_1800 = 3;
        int totalNumberOfDays = getTotalNumberOfDays(y, m);
        return (totalNumberOfDays + START_DAY_FOR_JAN_1_1800) % 7;
    }

    static int getTotalNumberOfDays(int y, int m) {
        int total = 0;
        for (int i = 1800; i < y; ++i) {
            total += isLeapYear(i) ? 366 : 365;
        }
        for (int i = 1; i < m; ++i) {
            total += getNumberOfDaysInMonth(y, i);
        }
        return total;
    }

    static int getNumberOfDaysInMonth(int y, int m) {
        if (m == 1 || m == 3 || m == 5 || m == 7 ||
            m == 8 || m == 10 || m == 12) {
            return 31;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        if (m == 2) {
            return isLeapYear(y) ? 29 : 28;
        }
        return 0;
    }

    static bool isLeapYear(int y) {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        CalendarWrapper calendarWrapper;
        if (argc >= 3) {
            calendarWrapper = CalendarWrapper(argv[1], argv[2]);
        } else if (argc == 2) {
            calendarWrapper = CalendarWrapper(argv[1]);
        } else {
            calendarWrapper = CalendarWrapper();
        }

        calendarWrapper.printMonth();
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}