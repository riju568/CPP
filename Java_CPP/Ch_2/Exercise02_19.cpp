#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>
/**
 * 2.19 (Geometry: area of a triangle) Write a program that prompts the user
 * to enter three points (x1, y1), (x2, y2), (x3, y3) of a triangle and
 * displays its area.
 */
int main()
{

    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter the coordinates of three points separated by spaces\nlike x1 y1 x2 y2 x3 y3: ";
        double x1 = 0.0;
        double y1 = 0.0;
        double x2 = 0.0;
        double y2 = 0.0;
        double x3 = 0.0;
        double y3 = 0.0;
        if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double side1 = std::sqrt(std::pow(x2 - x1, 2.0) + std::pow(y2 - y1, 2.0));
        const double side2 = std::sqrt(std::pow(x3 - x2, 2.0) + std::pow(y3 - y2, 2.0));
        const double side3 = std::sqrt(std::pow(x1 - x3, 2.0) + std::pow(y1 - y3, 2.0));
        const double s = (side1 + side2 + side3) / 2.0;
        const double area = std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
        std::cout << "The area of the triangle is " << std::fixed << std::setprecision(1) << area << '\n';
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