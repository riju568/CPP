#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.7 (Corner point coordinates) Suppose a pentagon is centered at (0, 0) with one point
 * at the 0 o’clock position. Write a program that prompts the user to enter the radius
 * of the bounding circle of a pentagon and displays the coordinates of the five corner points.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        constexpr double PI = 3.14159265358979323846;
        std::cout << "Enter the radius of the bounding circle: ";
        double radius = 0.0;
        if (!(std::cin >> radius) || radius <= 0.0)
        {
            std::cout << "Please enter a valid positive numeric value for the radius.\n";
            return EXIT_SUCCESS;
        }
        std::cout << "The coordinates of five points on the pentagon are:\n";
        for (int i = 0; i < 5; ++i)
        {
            double angle = (PI / 2.0) + (2.0 * PI / 5.0) * i;
            double x = radius * std::cos(angle);
            double y = radius * std::sin(angle);
            if (std::abs(x) < 1e-10)
                x = 0.0;
            if (std::abs(y) < 1e-10)
                y = 0.0;

            std::cout << "(" << std::fixed << std::setprecision(4)
                      << x << ", " << y << ")\n";
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}