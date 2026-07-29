#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>
/**
 * 4.2 (Geometry: great circle distance) The great circle distance is the
 * distance between two points on the surface of a sphere. Let (x1, y1)
 * and (x2, y2) be the geographical latitude and longitude of two points.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        constexpr double RADIUS = 6371.01;
        constexpr double PI = 3.14159265358979323846;
        auto to_radians = [PI](double deg)
        {
            return deg * (PI / 180.0);
        };
        std::cout << "Enter point 1 (latitude and longitude) in degrees: ";
        double x_one = 0.0, y_one = 0.0;
        if (!(std::cin >> x_one >> y_one))
        {
            std::cout << "Please enter valid numeric values matching the prompt.\n";
            return EXIT_SUCCESS;
        }
        std::cout << "Enter point 2 (latitude and longitude) in degrees: ";
        double x_two = 0.0, y_two = 0.0;
        if (!(std::cin >> x_two >> y_two))
        {
            std::cout << "Please enter valid numeric values matching the prompt.\n";
            return EXIT_SUCCESS;
        }
        double x_one_rad = to_radians(x_one);
        double y_one_rad = to_radians(y_one);
        double x_two_rad = to_radians(x_two);
        double y_two_rad = to_radians(y_two);
        double cos_central_angle = std::sin(x_one_rad) * std::sin(x_two_rad) +
                                   std::cos(x_one_rad) * std::cos(x_two_rad) * std::cos(y_one_rad - y_two_rad);
        cos_central_angle = std::clamp(cos_central_angle, -1.0, 1.0);

        double distance = RADIUS * std::acos(cos_central_angle);

        std::cout << "The distance between the two points is: "
                  << std::fixed << std::setprecision(6) << distance << " km\n";

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