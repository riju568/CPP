#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * *10.11 (Exercise 10_11 Test Driver) Write a test
 * program that creates a Circle2D object c1 (new Circle2D(2, 2, 5.5)),
 * displays its area and perimeter, and displays the result of c1.contains(3,
 * 3), c1.contains(new Circle2D(4, 5, 10.5)), and c1.overlaps(new
 * Circle2D(3, 5, 2.3)).
 */

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
        std::cout << "Circle2D c1 = new Circle2D(2, 2, 5.5):\n";
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "Circle2D c1's area = " << c1.get_area() << '\n';
        std::cout << "perimeter = " << c1.get_perimeter() << '\n';
        std::cout << std::boolalpha;
        std::cout << "Result of c1.contains(3,3) = " << c1.contains(3.0, 3.0) << '\n';
        std::cout << "Result of c1.contains(new Circle2D(4,5,10.5)) = "  << c1.contains(Circle2D(4.0, 5.0, 10.5)) << '\n';
        std::cout << "Result of c1.overlaps(new Circle2D(3,5,2.3)) = "  << c1.overlaps(Circle2D(3.0, 5.0, 2.3)) << '\n';
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