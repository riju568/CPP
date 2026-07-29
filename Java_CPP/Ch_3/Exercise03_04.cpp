#include <iostream>
#include <random>
#include <string>
#include <stdexcept>
/**
 * (Random month) Write a program that randomly generates an integer
 * between 1 and 12 and displays the English month name January,
 * February, ..., December for the number 1, 2, ..., 12, accordingly.
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Welcome :)! To the random month generator!\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 12);

        int random_month = dis(gen);
        std::string month_name = "";

        switch (random_month)
        {
        case 1:
            month_name = "January";
            break;
        case 2:
            month_name = "February";
            break;
        case 3:
            month_name = "March";
            break;
        case 4:
            month_name = "April";
            break;
        case 5:
            month_name = "May";
            break;
        case 6:
            month_name = "June";
            break;
        case 7:
            month_name = "July";
            break;
        case 8:
            month_name = "August";
            break;
        case 9:
            month_name = "September";
            break;
        case 10:
            month_name = "October";
            break;
        case 11:
            month_name = "November";
            break;
        case 12:
            month_name = "December";
            break;
        default:
            throw std::out_of_range("Generated month value is out of bounds.");
        }

        std::cout << "The program generated: " << random_month << " for " << month_name << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}