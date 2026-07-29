#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>
/**
 * 2.16 (Geometry: area of a hexagon) Write a program that prompts the user
 * to enter the side of a hexagon and displays its area.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter the side: ";
        double side = 0.0;
        if (!(std::cin >> side))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double area = ((3.0 * std::sqrt(3.0)) / 2.0) * std::pow(side, 2.0);
        std::cout << "The area of the hexagon is " << std::fixed << std::setprecision(4) << area << '\n';
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