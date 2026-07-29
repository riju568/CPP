#include <iostream>
#include <exception>
/**
 * 2.2 (Compute the volume of a cylinder) Write a program that reads in the radius
 * and length of a cylinder and computes the area and volume using the following
 * formulas:
 * area = radius * radius * pi
 * volume = area * length
 * <p>
 * Here is a sample run:
 * * Enter the radius and length of a cylinder: 5.5 12
 * * The area is 95.0331
 * * The volume is 1140.4
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter the radius and length of a cylinder: ";

        double radius = 0.0;
        double length = 0.0;
        if (!(std::cin >> radius >> length))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double pi = 3.14159265358979323846;
        const double area = radius * radius * pi;
        const double volume = area * length;
        std::cout << "The area is " << area << '\n';
        std::cout << "The volume is " << volume << '\n';
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