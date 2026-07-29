#include <iostream>
#include <cmath>
#include <iomanip>
#include <exception>
#include <cstdlib>
/**
 * 4.4 (Geometry: area of a hexagon) The area of a hexagon can be computed using the
 * following formula (s is the length of a side):
 * Area = (6 * s^2) / (4 * tan(PI / 6))
 * Write a program that prompts the user to enter the side of a hexagon and displays
 * its area.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter the side: ";
        double side = 0.0;
        if (!(std::cin >> side))
        {
            std::cout << "Please enter a valid numeric value for the side length.\n";
            return EXIT_SUCCESS;
        }
        if (side < 0)
        {
            std::cout << "The side length must be a non-negative number.\n";
            return EXIT_SUCCESS;
        }
        constexpr double PI = 3.14159265358979323846;
        double area = (6.0 * (side * side)) / (4.0 * std::tan(PI / 6.0));
        std::cout << "The area of the hexagon is "
                  << std::fixed << std::setprecision(2) << area << '\n';
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