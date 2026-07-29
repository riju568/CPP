#include <iostream>
#include <string>
#include <stdexcept>
/**
 * **3.21 (Science: day of the week) Zeller’s congruence is an algorithm
 * developed by Christian Zeller to calculate the day of the week.
 * <p>
 * The formula is h = ¢q + 26(m10+ 1) + k + 4k + 4j + 5j≤ % 7 where ■ h is the day of the
 * week (0: Saturday, 1: Sunday, 2: Monday, 3: Tuesday, 4: Wednesday, 5:
 * Thursday, 6: Friday). ■ q is the day of the month. ■ m is the month (3:
 * March, 4: April, …, 12: December). January and February are counted as months
 * 13 and 14 of the previous year. ■ j is the century (i.e., year 100 ). ■ k is
 * the year of the century (i.e., year % 100).
 * <p>
 * Note that the division in the formula performs an integer division.
 * <p>
 * Write a program that prompts the user to enter a year, month, and day of the month, and displays the name of the
 * day of the week. Here are some sample runs:
 * <p>
 * Enter year: (e.g., 2012): 2015
 * Enter month: 1-12: 1
 * Enter the day of the month: 1-31: 21
 * <p>
 * 25 Day of the week is Sunday
 * <p>
 * Enter year: (e.g., 2012): 2012 Enter month: 1-12: 5
 * Enter the day of the month: 1-31: 12
 * <p>
 * Day of the week is Saturday
 * <p>
 * <p>
 * (Hint: January and February
 * are counted as 13 and 14 in the formula, so you need to convert the user
 * input 1 to 13 and 2 to 14 for the month and change the year to the previous
 * year.)
 *
 *
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try {
        int year = 0;
        int temp = 0;
        int q = 0;

        std::cout << "Enter year: (e.g., 2012): ";
        if (!(std::cin >> year)) {
            throw std::runtime_error("Invalid input: Please enter a valid integer for the year.");
        }

        std::cout << "\nEnter month: 1-12: ";
        if (!(std::cin >> temp)) {
            throw std::runtime_error("Invalid input: Please enter a valid integer for the month.");
        }

        if (temp < 1 || temp > 12) {
            throw std::out_of_range("Month must be an integer between 1 and 12.");
        }
        int m = 0;
        if (temp == 1) {
            m = 13;
            year -= 1;
        } else if (temp == 2) {
            m = 14;
            year -= 1;
        } else {
            m = temp;
        }
        int k = year % 100;
        int j = year / 100;
        std::cout << "\nEnter the day of the month: 1-31: ";
        if (!(std::cin >> q)) {
            throw std::runtime_error("Invalid input: Please enter a valid integer for the day.");
        }
        if (q < 1 || q > 31) {
            throw std::out_of_range("Day of the month must be an integer between 1 and 31.");
        }
        int h = (q + ((26 * (m + 1)) / 10) + k + (k / 4) + (j / 4) + (5 * j)) % 7;
        std::string day_of_week = "";
        switch (h) {
            case 0:
                day_of_week += "Saturday";
                break;
            case 1:
                day_of_week += "Sunday";
                break;
            case 2:
                day_of_week += "Monday";
                break;
            case 3:
                day_of_week += "Tuesday";
                break;
            case 4:
                day_of_week += "Wednesday";
                break;
            case 5:
                day_of_week += "Thursday";
                break;
            case 6:
                day_of_week += "Friday";
                break;
        }

        std::cout << "\nDay of the week is " << day_of_week << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}