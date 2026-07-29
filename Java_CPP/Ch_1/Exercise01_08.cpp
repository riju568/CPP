#include <iostream>
#include <exception>
/**
 * 1.8 (Area and perimeter of a circle) Write a program that displays
 * the area and perimeter of a circle that has a radius of 5.5 using
 * the following formula:
 * perimeter = 2 * radius * pi
 * area = radius * radius * pi
 */
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        const double radius = 5.5;
        const double pi = 3.14159265358979323846;
        const double perimeter = 2.0 * radius * pi;
        const double area = radius * radius * pi;
        std::cout << "Area of a circle with radius 5.5 is: " << area << '\n';
        std::cout << "Perimeter of a circle with radius 5.5 is: " << perimeter << '\n';
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