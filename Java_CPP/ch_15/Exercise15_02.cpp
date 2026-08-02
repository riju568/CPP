#include <iostream>
#include <exception>
#include <stdexcept>
#include <numbers>

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
            throw std::runtime_error("Invalid input received. Please enter numeric values.");
        }

        if (radius < 0.0 || length < 0.0)
        {
            throw std::domain_error("Radius and length must be non-negative values.");
        }
        const double pi = std::numbers::pi;
        const double area = radius * radius * pi;
        const double volume = area * length;
        std::cout << "The area is " << area << '\n';
        std::cout << "The volume is " << volume << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown, non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}