#include <iostream>
#include <exception>
#include <stdexcept>
#include <numbers>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter the radius and length of a cylinder: ";

        double radius = 0.0;
        double length = 0.0;
        if (!(std::cin >> radius >> length))
        {
            throw std::invalid_argument("Invalid input received.");
        }

        const double area = radius * radius * std::numbers::pi;
        const double volume = area * length;

        std::cout << "The area is " << area << '\n';
        std::cout << "The volume is " << volume << '\n';
    }
    catch (const std::exception& e)
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