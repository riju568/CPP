#include <iostream>
#include <string>
#include <stdexcept>
/**
 * *3.11 (Find the number of days in a month) Write a program that prompts the
 * user to enter the month and year and displays the number of days in the
 * month. For example, if the user entered month 2 and year 2012, the program
 * should display that February 2012 had 29 days. If the user entered month 3
 * and year 2015, the program should display that March 2015 had 31 days.
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        int month = 0;
        int year = 0;

        std::cout << "Enter the month as an integer from 1 to 12: ";
        if (!(std::cin >> month))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer for the month.");
        }
        if (month < 1 || month > 12)
        {
            throw std::out_of_range("Month must be an integer between 1 and 12.");
        }
        std::cout << "Enter the year: ";
        if (!(std::cin >> year))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer for the year.");
        }

        if (year < 0)
        {
            throw std::out_of_range("Year cannot be a negative value.");
        }

        const std::string common_output = "The number of days in the month is ";
        std::string days = "";

        switch (month)
        {
        case 1:
            days = "31";
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                days = "29";
            }
            else
            {
                days = "28";
            }
            break;
        case 3:
            days = "31";
            break;
        case 4:
            days = "30";
            break;
        case 5:
            days = "31";
            break;
        case 6:
            days = "30";
            break;
        case 7:
            days = "31";
            break;
        case 8:
            days = "31";
            break;
        case 9:
            days = "30";
            break;
        case 10:
            days = "31";
            break;
        case 11:
            days = "30";
            break;
        case 12:
            days = "31";
            break;
        }

        std::cout << common_output << days << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}