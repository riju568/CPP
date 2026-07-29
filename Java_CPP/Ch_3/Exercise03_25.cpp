#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
/**

 * *3.25 (Geometry: intersecting point) Two points on line 1 are given as (x1, y1) and (x2,

 * y2) and on line 2 as (x3, y3) and (x4, y4), as shown in Figure 3.8a–b.

 * The intersecting point of the two lines can be found by solving the following

 * linear equation:

 * (y1 - y2)x - (x1 - x2)y = (y1 - y2)x1 - (x1 - x2)y1

 * (y3 - y4)x - (x3 - x4)y = (y3 - y4)x3 - (x3 - x4)y3

 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
        double x3 = 0.0, y3 = 0.0, x4 = 0.0, y4 = 0.0;
        std::cout << "\nEnter x1, y1, x2, y2, x3, y3, x4, y4: ";
        if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4))
        {
            throw std::runtime_error("Invalid input: Please enter valid numeric values matching the prompt.");
        }
        double a = y1 - y2;
        double b = x1 - x2;
        double c = y3 - y4;
        double d = x3 - x4;
        double e = (y1 - y2) * x1 - (x1 - x2) * y1;
        double f = (y3 - y4) * x3 - (x3 - x4) * y3;
        double dxDy = a * d - b * c;
        if (std::abs(dxDy) < 1E-5)
        {
            std::cout << "The two lines are parallel\n";
        }
        else
        {
            double x = (e * d - b * f) / dxDy;
            double y = (a * f - e * c) / dxDy;
            std::cout << std::fixed << std::setprecision(5);
            std::cout << "The intersecting point is at (" << x << ", " << y << ")\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}