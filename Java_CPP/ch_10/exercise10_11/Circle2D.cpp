#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/* __________________________UML DIAGRAM_____________________________*
 *                                                                   |
 *                           Circle2D                                |
 *-------------------------------------------------------------------|
 *                    -x : double                                    |
 *                    -y : double                                    |
 *                    -radius : double                               |
 *-------------------------------------------------------------------|
 *                  +Circle2D()                                      |
 *                  +Circle2D(x: double, y: double, radius: double)  |
 *                  +get_x() : double                                |
 *                  +get_y() : double                                |
 *                  +get_radius() : double                           |
 *                  +get_area() : double                             |
 *                  +get_perimeter() : double                        |
 *                  +contains(x: double, y: double) : bool           |
 *                  +contains(circle: const Circle2D&) : bool        |
 *                  +overlaps(circle: const Circle2D&) : bool        |
 * _________________________________________________________________ */

/**
 * *10.11 (Geometry: the Circle2D class) Define the Circle2D class that contains:
 * ■ Two double data fields named x and y that specify the center of the circle
 *   with getter methods.
 * ■ A data field radius with a getter method.
 * ■ A no-arg constructor that creates a default circle with (0, 0) for (x, y) and 1
 *   for radius.
 * ■ A constructor that creates a circle with the specified x, y, and radius.
 * ■ A method get_area() that returns the area of the circle.
 * ■ A method get_perimeter() that returns the perimeter of the circle.
 * ■ A method contains(double x, double y) that returns true if the
 *   specified point (x, y) is inside this circle.
 * ■ A method contains(Circle2D circle) that returns true if the specified circle
 *   is inside this circle.
 * ■ A method overlaps(Circle2D circle) that returns true if the specified circle
 *   overlaps with this circle.
 *
 * Draw the UML diagram for the class and then implement the class.
 */




// Cross-platform PI calculation constant
const double PI = std::acos(-1.0);

class Circle2D
{
private:
    double x;
    double y;
    double radius;

    double distance(double point_x, double point_y) const
    {
        return std::sqrt(std::pow(point_x - x, 2) + std::pow(point_y - y, 2));
    }

public:
    Circle2D() : x(0.0), y(0.0), radius(1.0) {}
    Circle2D(double x, double y, double radius) : x(x), y(y), radius(radius)
    {
        if (radius <= 0.0)
        {
            throw std::invalid_argument("Error: Radius must be greater than zero.");
        }
    }

    double get_x() const
    {
        return x;
    }

    double get_y() const
    {
        return y;
    }

    double get_radius() const
    {
        return radius;
    }

    double get_area() const
    {
        return PI * radius * radius;
    }

    double get_perimeter() const
    {
        return 2.0 * PI * radius;
    }

    bool contains(double px, double py) const
    {
        return distance(px, py) < radius;
    }
    bool contains(const Circle2D &circle) const
    {
        double dist_between_centers = distance(circle.get_x(), circle.get_y());
        return dist_between_centers + circle.get_radius() <= radius;
    }
    bool overlaps(const Circle2D &circle) const
    {
        double dist_between_centers = distance(circle.get_x(), circle.get_y());
        return dist_between_centers < (radius + circle.get_radius()) &&
               dist_between_centers > std::abs(radius - circle.get_radius());
    }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        Circle2D c1(2.0, 2.0, 5.5);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Circle c1 details:\n";
        std::cout << "Area: " << c1.get_area() << '\n';
        std::cout << "Perimeter: " << c1.get_perimeter() << "\n\n";
        std::cout << std::boolalpha;
        std::cout << "c1.contains(3, 3): " << c1.contains(3.0, 3.0) << '\n';
        std::cout << "c1.contains(Circle2D(4, 5, 10.5)): " << c1.contains(Circle2D(4.0, 5.0, 10.5)) << '\n';
        std::cout << "c1.overlaps(Circle2D(3, 5, 2.3)):" << c1.overlaps(Circle2D(3.0, 5.0, 2.3)) << '\n';
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}