#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.5 (Geometry: area of a regular polygon) A regular polygon is an n-sided polygon in
 * which all sides are of the same length and all angles have the same degree.
 * The formula for computing the area of a regular polygon is:
 * Area = (n * s^2) / (4 * tan(PI / n))
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        constexpr double PI = 3.14159265358979323846;

        auto compute_polygon_area = [PI](int n, double s)
        {
            return (n * std::pow(s, 2.0)) / (4.0 * std::tan(PI / static_cast<double>(n)));
        };

        std::cout << "Enter the number of sides: ";
        int num_sides = 0;
        if (!(std::cin >> num_sides) || num_sides < 3)
        {
            std::cout << "The number of sides must be an integer greater than or equal to 3.\n";
            return EXIT_SUCCESS;
        }

        std::cout << "Enter the side: ";
        double length_sides = 0.0;
        if (!(std::cin >> length_sides) || length_sides <= 0.0)
        {
            std::cout << "The length of the sides must be a positive number.\n";
            return EXIT_SUCCESS;
        }

        double area = compute_polygon_area(num_sides, length_sides);

        std::cout << "The area of the polygon is "
                  << std::fixed << std::setprecision(6) << area << '\n';

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