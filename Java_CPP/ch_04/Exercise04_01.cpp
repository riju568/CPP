#include <iostream>
#include <cmath>
#include <iomanip>
#include <exception>
#include <cstdlib>
/**
 * 4.1 (Geometry: area of a pentagon) Write a program that prompts
 * the user to enter the length from the center of a pentagon
 * to a vertex and computes the area of the pentagon, as shown in the
 * following figure.
 */


int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter the length from the center of the pentagon to the vertex: ";
        double r = 0.0;
        if (!(std::cin >> r))
        {
            std::cout << "Please enter a valid numeric value for the length.\n";
            return EXIT_SUCCESS;
        }
        if (r < 0)
        {
            std::cout << "The length from the center to a vertex must be a non-negative number.\n";
            return EXIT_SUCCESS;
        }
        constexpr double PI = 3.14159265358979323846;
        double s = 2.0 * r * std::sin(PI / 5.0);
        double area = (5.0 * (s * s)) / (4.0 * std::tan(PI / 5.0));
        std::cout << "The area of the pentagon is: "
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