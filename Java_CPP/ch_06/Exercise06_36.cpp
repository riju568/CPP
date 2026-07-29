#include <iostream>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * 6.36 (Geometry: area of a regular polygon) A regular polygon is an n-sided polygon
 * in which all sides are of the same length and all angles have the same degree (i.e.,
 * the polygon is both equilateral and equiangular).
 *
 * Write a method that returns the area of a regular polygon using the following header:
 * double area(int n, double side)
 *
 * Write a main method that prompts the user to enter the number of sides and the
 * side of a regular polygon and displays its area. Here is a sample run:
 * Enter the number of sides: 5
 * Enter the side: 6.5
 * The area of the polygon is 72.69017017488385
 */

double area(int n, double side)
{
    const double PI = std::acos(-1.0);
    return (n * std::pow(side, 2)) / (4.0 * std::tan(PI / n));
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        int num_sides = 0;
        double side = 0.0;

        std::cout << "Enter the number of sides: ";
        if (std::cin >> num_sides)
        {
            std::cout << "Enter the side: ";
            if (std::cin >> side)
            {
                std::cout << "The area of the polygon is " << area(num_sides, side) << '\n';
            }
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