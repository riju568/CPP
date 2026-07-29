#include <iostream>
#include <stdexcept>
/**

 * **3.27 (Geometry: points in triangle?) Suppose a right triangle is placed in a plane as

 * shown below.

 * The right-angle point is placed at (0, 0), and the other two points

 * are placed at (200, 0), and (0, 100).

 * Write a program that prompts the user to enter

 * a point with x- and y-coordinates and determines whether the point is inside the

 * triangle.

 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        double x = 0.0;
        double y = 0.0;
        std::cout << "Enter a point's x- and y-coordinates: ";
        if (!(std::cin >> x >> y))
        {
            throw std::runtime_error("Please enter valid numeric values for the coordinates.");
        }
        bool isInTriangle = (x >= 0.0) && (y >= 0.0) && (y <= -0.5 * x + 100.0);

        if (isInTriangle)
        {
            std::cout << "The point is in the triangle\n";
        }
        else
        {
            std::cout << "The point is not in the triangle\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}