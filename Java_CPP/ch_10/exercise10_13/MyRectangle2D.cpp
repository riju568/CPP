#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <exception>
#include <cstdlib>


/**
 * *10.13 (Geometry: the MyRectangle2D class) Define the MyRectangle2D class that contains:
 * ■ Two double data fields named x and y that specify the center of the rectangle with getter and setter methods.
 * ■ The data fields width and height with getter and setter methods.
 * ■ A no-arg constructor that creates a default rectangle with (0, 0) for (x, y) and 1 for both width and height.
 * ■ A constructor that creates a rectangle with the specified x, y, width, and height.
 * ■ A method get_area() that returns the area of the rectangle.
 * ■ A method get_perimeter() that returns the perimeter of the rectangle.
 * ■ A method contains(double x, double y) that returns true if the specified point (x, y) is inside this rectangle.
 * ■ A method contains(const MyRectangle2D& r) that returns true if the specified rectangle is inside this rectangle.
 * ■ A method overlaps(const MyRectangle2D& r) that returns true if the specified rectangle overlaps with this rectangle.
 */

class MyPoint
{
private:
    double x;
    double y;

public:
    MyPoint() : x(0.0), y(0.0) {}
    MyPoint(double x, double y) : x(x), y(y) {}

    double get_x() const { return x; }
    double get_y() const { return y; }
    void set_x(double x_val) { x = x_val; }
    void set_y(double y_val) { y = y_val; }

    double distance(const MyPoint &p) const
    {
        return std::sqrt(std::pow(p.x - x, 2) + std::pow(p.y - y, 2));
    }
};

class MyRectangle2D
{
private:
    double x;
    double y;
    double width;
    double height;

public:
    MyRectangle2D() : x(0.0), y(0.0), width(1.0), height(1.0) {}

    MyRectangle2D(double x, double y, double width, double height)
        : x(x), y(y), width(width), height(height)
    {
        if (width <= 0.0 || height <= 0.0)
        {
            throw std::invalid_argument("Error: Width and height must be greater than zero.");
        }
    }
    double get_x() const { return x; }
    void set_x(double x_val) { x = x_val; }

    double get_y() const { return y; }
    void set_y(double y_val) { y = y_val; }

    double get_width() const { return width; }
    void set_width(double w)
    {
        if (w <= 0.0)
        {
            throw std::invalid_argument("Error: Width must be greater than zero.");
        }
        width = w;
    }

    double get_height() const { return height; }
    void set_height(double h)
    {
        if (h <= 0.0)
        {
            throw std::invalid_argument("Error: Height must be greater than zero.");
        }
        height = h;
    }

    double get_area() const
    {
        return width * height;
    }

    double get_perimeter() const
    {
        return 2.0 * (width + height);
    }

    bool contains(double px, double py) const
    {
        return (std::abs(px - x) <= width / 2.0) && (std::abs(py - y) <= height / 2.0);
    }

    bool contains(const MyRectangle2D &r) const
    {
        return (std::abs(r.get_x() - x) + r.get_width() / 2.0 <= width / 2.0) && (std::abs(r.get_y() - y) + r.get_height() / 2.0 <= height / 2.0);
    }

    bool overlaps(const MyRectangle2D &r) const
    {
        return (std::abs(r.get_x() - x) < (width + r.get_width()) / 2.0) && (std::abs(r.get_y() - y) < (height + r.get_height()) / 2.0) && !contains(r);
    }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        MyRectangle2D r1(2.0, 2.0, 5.5, 4.9);
        std::cout << std::fixed << std::setprecision(3);
        std::cout << "MyRectangle2D r1's area = " << r1.get_area() << '\n';
        std::cout << "Perimeter = " << r1.get_perimeter() << '\n';
        std::cout << std::boolalpha;
        std::cout << "The result of: r1.contains(3, 3) = " << r1.contains(3.0, 3.0) << '\n';
        std::cout << "The result of: r1.contains(new MyRectangle2D(4, 5, 10.5, 3.2)) = " << r1.contains(MyRectangle2D(4.0, 5.0, 10.5, 3.2)) << '\n';
        std::cout << "And the result of: r1.overlaps(new MyRectangle2D(3, 5, 2.3, 5.4)) = " << r1.overlaps(MyRectangle2D(3.0, 5.0, 2.3, 5.4)) << '\n';
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