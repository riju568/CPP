#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>
/**
 * 2.12 (Physics: finding runway length) Write a program that prompts the user
 * to enter speed v and acceleration a, and displays the minimum runway length.
 */
int main()
{

    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter speed and acceleration: ";
        double speed = 0.0;
        double acceleration = 0.0;
        if (!(std::cin >> speed >> acceleration))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        if (acceleration == 0.0)
        {
            std::cerr << "Error: Acceleration cannot be zero.\n";
            return 4;
        }
        const double length = std::pow(speed, 2.0) / (2.0 * acceleration);
        std::cout << "The minimum runway length for this airplane is " << std::fixed << std::setprecision(3) << length << '\n';
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