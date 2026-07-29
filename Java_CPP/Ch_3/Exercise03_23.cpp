#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>
/**

 * 3.23 (Geometry: point in a rectangle?)

 * Write a program that prompts the user to enter a point (x, y) and checks whether the point is within the rectangle

 * centered at (0, 0) with width 10 and height 5.

 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        double x2 = 0.0;
        double y2 = 0.0;
        std::cout << "\nEnter a point with two coordinates: ";
        if (!(std::cin >> x2 >> y2))
        {
            throw std::runtime_error("Invalid input: Please enter valid numeric coordinates.");
        }
        double rectWidth = 10.0;
        double rectHeight = 5.0;
        bool isWithinHorizontal = std::abs(x2) <= rectWidth / 2.0;
        bool isWithinVertical = std::abs(y2) <= rectHeight / 2.0;
        std::string res = "";
        if (isWithinHorizontal && isWithinVertical)
        {
            res = "is in the rectangle";
        }
        else
        {
            res = "is not in the rectangle";
        }
        std::cout << "Point (" << x2 << ", " << y2 << ") " << res << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}