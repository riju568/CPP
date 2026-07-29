#include <iostream>
#include <string>
#include <stdexcept>
/**
 * 3.28 (Geometry: two rectangles) Write a program that prompts
 * the user to enter the center x-, y-coordinates, width, and
 * height of two rectangles and determines whether the second
 * rectangle is inside the first or overlaps with the first, as shown
 * in Figure 3.9.
 *
 */
bool checkIfinside(double x1top, double x2top, double x1bottom, double x2bottom,
                   double y1top, double y2top, double y1bottom, double y2bottom)
{
    return (x2top <= x1top && x2bottom >= x1bottom && y2top <= y1top && y2bottom >= y1bottom);
}

bool checkIfoverlaps(double x1top, double x2top, double x1bottom, double x2bottom,
                     double y1top, double y2top, double y1bottom, double y2bottom)
{
    return !(x1top < x2bottom || x1bottom > x2top || y1top < y2bottom || y1bottom > y2top);
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        double recOneX = 0.0, recOneY = 0.0, recOnewidth = 0.0, recOneheight = 0.0;
        double recTwoX = 0.0, recTwoY = 0.0, recTwowidth = 0.0, recTwoheight = 0.0;

        std::cout << "Please enter rectangle one's center point x and y coordinates followed by its width and height:\n";
        if (!(std::cin >> recOneX >> recOneY >> recOnewidth >> recOneheight))
        {
            throw std::runtime_error("Please enter valid numeric values matching the prompt.");
        }

        std::cout << "Please enter rectangle two's center point x and y coordinates followed by its width and height:\n";
        if (!(std::cin >> recTwoX >> recTwoY >> recTwowidth >> recTwoheight))
        {
            throw std::runtime_error("Please enter valid numeric values matching the prompt.");
        }

        double recOnetopX = recOneX + recOnewidth / 2.0;
        double recOnetopY = recOneY + recOneheight / 2.0;
        double recOnebottomX = recOneX - recOnewidth / 2.0;
        double recOnebottomY = recOneY - recOneheight / 2.0;

        double recTwotopX = recTwoX + recTwowidth / 2.0;
        double recTwotopY = recTwoY + recTwoheight / 2.0;
        double recTwobottomX = recTwoX - recTwowidth / 2.0;
        double recTwobottomY = recTwoY - recTwoheight / 2.0;

        bool isInside = checkIfinside(recOnetopX, recTwotopX, recOnebottomX, recTwobottomX,
                                      recOnetopY, recTwotopY, recOnebottomY, recTwobottomY);

        bool overlap = checkIfoverlaps(recOnetopX, recTwotopX, recOnebottomX, recTwobottomX,
                                       recOnetopY, recTwotopY, recOnebottomY, recTwobottomY);

        if (isInside)
        {
            std::cout << "Rectangle two is inside of rectangle one\n";
        }
        else if (overlap)
        {
            std::cout << "Rectangle two overlaps rectangle one\n";
        }
        else
        {
            std::cout << "Rectangle two does not overlap rectangle one and is not inside of rectangle one\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}