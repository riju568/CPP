#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
/**
 * (Find future dates) Write a program that prompts the user to enter an integer for
 * todays day of the week (Sunday is 0, Monday is 1, �, and Saturday is 6). Also
 * prompt the user to enter the number of days after today for a future day and display
 * the future day of the week.
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        int week_day = 0;
        std::cout << "Enter an integer for today's day of the week (Sunday is 0, Monday is 1, and Saturday is 6): ";
        if (!(std::cin >> week_day))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer.");
        }
        if (week_day < 0 || week_day > 6)
        {
            throw std::out_of_range("Incorrect value....Please enter an integer 0 through 6.");
        }

        int num_days = 0;
        std::cout << "Enter the number of days after today to discover the future day: ";
        if (!(std::cin >> num_days))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer.");
        }
        int future_week_day = (week_day + (num_days % 7)) % 7;
        if (future_week_day < 0)
        {
            future_week_day += 7;
        }

        const std::vector<std::string> days_of_week = {
            "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        std::cout << days_of_week[future_week_day] << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}