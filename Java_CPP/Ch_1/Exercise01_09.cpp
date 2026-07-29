#include <iostream>
#include <cmath>
#include <exception>
/**
 * 1.9 (Area and perimeter of a rectangle) Write a program that displays the area and
 * perimeter of a rectangle with the width of 4.5 and height of 7.9 using the
 * following formula: area = width * height
 */
int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        const double width = 4.5;
        const double height = 7.9;
        double area = width * height;
        area = std::round(area * 100.0) / 100.0;
        const double perimeter = 2.0 * (width + height);
        std::cout << "The area of a rectangle with a width of 4.5 and a height of 7.9 is " << area << '\n';
        std::cout << "Perimeter is " << perimeter << '\n';
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