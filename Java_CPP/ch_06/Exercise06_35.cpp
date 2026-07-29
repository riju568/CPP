#include <iostream>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * 6.35 (Geometry: area of a pentagon) The area of a pentagon can be computed using the
 * following formula:
 * Area = 5 * s^2 / (4 * tan(PI/5))
 * Write a method that returns the area of a pentagon using the following header:
 * double area(double side)
 * Write a main method that prompts the user to enter the side of a pentagon and
 * displays its area. Here is a sample run:
 * Enter the side: 5.5
 * The area of the pentagon is 52.04444136781625
 */

double area(double side)
{
    const double PI = std::acos(-1.0);
    return (5.0 * std::pow(side, 2)) / (4.0 * std::tan(PI / 5.0));
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter the side: ";
        double s = 0.0;
        if (std::cin >> s)
        {
            std::cout << "The area of the pentagon is " << area(s) << '\n';
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}