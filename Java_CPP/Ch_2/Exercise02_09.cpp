#include <iostream>
#include <iomanip>
#include <exception>
/**
 * 2.9 (Physics: acceleration) Average acceleration is defined as the change of velocity
 * divided by the time taken to make the change,
 * as shown in the following formula:
 * a = (v1 - v0) / t
 *
 * Write a program that prompts the user to enter the starting velocity v0 in meters/
 * second, the ending velocity v1 in meters/second, and the time span t in seconds,
 * and displays the average acceleration.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter v0, v1, and t: ";

        double v0 = 0.0;
        double v1 = 0.0;
        double t = 0.0;
        if (!(std::cin >> v0 >> v1 >> t))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        if (t == 0.0)
        {
            std::cerr << "Error: Time span t cannot be zero.\n";
            return 4;
        }
        const double acceleration = (v1 - v0) / t;
        std::cout << "The average acceleration is " << std::fixed << std::setprecision(4) << acceleration << '\n';
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