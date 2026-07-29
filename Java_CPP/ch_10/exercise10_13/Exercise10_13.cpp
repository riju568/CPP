#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * *10.13 (Exercise 10_13 Test Driver) Write a test program that creates a MyRectangle2D
 * object r1 (new MyRectangle2D(2, 2, 5.5, 4.9)), displays its area and perimeter, and
 * displays the result of:
 * - r1.contains(3, 3)
 * - r1.contains(new MyRectangle2D(4, 5, 10.5, 3.2))
 * - r1.overlaps(new MyRectangle2D(3, 5, 2.3, 5.4))
 */

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

    double get_area() const { return width * height; }
    double get_perimeter() const  { return 2.0 * (width + height);   }
    bool contains(double px, double py) const  { return (std::abs(px - x) <= width / 2.0) && (std::abs(py - y) <= height / 2.0);  }
    bool contains(const MyRectangle2D &r) const { return (std::abs(r.get_x() - x) + r.get_width() / 2.0 <= width / 2.0) &&(std::abs(r.get_y() - y) + r.get_height() / 2.0 <= height / 2.0); }
    bool overlaps(const MyRectangle2D &r) const
    {
        return (std::abs(r.get_x() - x) < (width + r.get_width()) / 2.0) && (std::abs(r.get_y() - y) < (height + r.get_height()) / 2.0) &&  !contains(r);
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
        std::cout << "And the result of: r1.overlaps(new MyRectangle2D(3, 5, 2.3, 5.4)) = "  << r1.overlaps(MyRectangle2D(3.0, 5.0, 2.3, 5.4)) << '\n';
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