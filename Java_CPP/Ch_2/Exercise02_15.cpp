#include <iostream>
#include <cmath>
#include <exception>
/**
 * 2.15 (Geometry: distance of two points) Write a program that prompts the user to enter
 * two points (x1, y1) and (x2, y2) and displays their distance between them.
 * The formula for computing the distance is sqrt[(x2 - x1)^2 + (y2 - y1)^2)]. Note that
 * you can use Math.pow(a, 0.5) to compute sqrt(a). Sample run:
 * <p>
 * Enter x1 and y1: 1.5 -3.4
 * Enter x2 and y2: 4 5
 * The distance between the two points is 8.764131445842194
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter x1 and y1: \n";
        double x1 = 0.0;
        double y1 = 0.0;
        if (!(std::cin >> x1 >> y1))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        std::cout << "Enter x2 and y2: \n";
        double x2 = 0.0;
        double y2 = 0.0;
        if (!(std::cin >> x2 >> y2))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double exs = std::pow(x2 - x1, 2.0);
        const double whys = std::pow(y2 - y1, 2.0);
        const double distance = std::pow(exs + whys, 0.5);

        std::cout << "The distance between the two points is " << distance << '\n';
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