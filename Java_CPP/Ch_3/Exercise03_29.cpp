#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>
/**
 * **3.29 (Geometry: two circles) Write a program that prompts the user to enter the center
 * coordinates and radius of two circles and determines whether the second circle is
 * inside the first or overlaps with the first, as shown in Figure 3.10.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        double x1 = 0.0, y1 = 0.0, r1 = 0.0;
        double x2 = 0.0, y2 = 0.0, r2 = 0.0;
        std::cout << "\nEnter circle1's center x-, y-coordinates, and radius: ";
        if (!(std::cin >> x1 >> y1 >> r1))
        {
            throw std::runtime_error("Please enter valid numeric values matching the prompt.");
        }
        std::cout << "\nEnter circle2's center x-, y-coordinates, and radius: ";
        if (!(std::cin >> x2 >> y2 >> r2))
        {
            throw std::runtime_error("Please enter valid numeric values matching the prompt.");
        }
        double distBetweenCenters = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        std::string result;
        if (distBetweenCenters <= std::abs(r1 - r2))
        {
            result = "is inside circle1";
        }
        else if (distBetweenCenters <= r1 + r2)
        {
            result = "overlaps circle1";
        }
        else
        {
            result = "does not overlap circle1 and is not inside circle1";
        }

        std::cout << "circle2 " << result << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}