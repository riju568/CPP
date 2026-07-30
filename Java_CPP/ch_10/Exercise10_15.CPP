#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <exception>
#include <cstdlib>

/**
 * *10.15 (Geometry: the bounding rectangle) A bounding rectangle is the minimum rectangle
 * that encloses a set of points in a two-dimensional plane, as shown in
 * Figure 10.24d. Write a method that returns a bounding rectangle for a set of
 * points in a two-dimensional plane, as follows:
 * public static MyRectangle2D getRectangle(double[][] points)
 * <p>
 * The Rectangle2D class is defined in Programming Exercise 10.13.
 * Write a test program that prompts the user to enter five points and displays the bounding
 * rectangle’s center, width, and height. Here is a sample run:
 * Enter five points: 1.0 2.5 3 4 5 6 7 8 9 10
 * The bounding rectangle's center (5.0, 6.25), width 8.0, height 7.5
 * <p>
 * About Bounding Rectangle:
 * The top of the rectangle is determined by the y-coordinate of the top-most point - point B
 * The bottom of the rectangle is determined by the y-coordinate of the lowest point - point D
 * The left side of the rectangle is determined by the x-coordinate of the leftmost point - point A
 * The right of the rectangle is determined by the x-coordinate of the rightmost point - point C
 */
class MyRectangle2D
{
private:
    double x;
    double y;
    double width;
    double height;

public:
    MyRectangle2D() : x(0), y(0), width(1), height(1) {}
    MyRectangle2D(double x, double y, double width, double height)
        : x(x), y(y), width(width), height(height) {}
    [[nodiscard]] double get_x() const noexcept { return x; }
    [[nodiscard]] double get_y() const noexcept { return y; }
    [[nodiscard]] double get_width() const noexcept { return width; }
    [[nodiscard]] double get_height() const noexcept { return height; }
    void set_x(double new_x) noexcept { x = new_x; }
    void set_y(double new_y) noexcept { y = new_y; }
    void set_width(double new_w) noexcept { width = new_w; }
    void set_height(double new_h) noexcept { height = new_h; }
};
struct Point
{
    double x;
    double y;
};
MyRectangle2D get_rectangle(const std::vector<Point> &points)
{
    if (points.empty())
    {
        return MyRectangle2D();
    }

    double min_x = points[0].x;
    double max_x = points[0].x;
    double min_y = points[0].y;
    double max_y = points[0].y;
    for (const auto &p : points)
    {
        min_x = std::min(min_x, p.x);
        max_x = std::max(max_x, p.x);
        min_y = std::min(min_y, p.y);
        max_y = std::max(max_y, p.y);
    }
    double width = max_x - min_x;
    double height = max_y - min_y;
    double center_x = min_x + (width / 2.0);
    double center_y = min_y + (height / 2.0);

    return MyRectangle2D(center_x, center_y, width, height);
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        constexpr std::size_t num_points = 5;
        std::vector<Point> points(num_points);
        std::cout << "Enter five points: ";
        for (std::size_t i = 0; i < num_points; ++i)
        {
            if (!(std::cin >> points[i].x >> points[i].y))
            {
                std::cerr << "Invalid input received.\n";
                return EXIT_FAILURE;
            }
        }
        MyRectangle2D rect = get_rectangle(points);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\nThe bounding rectangle's center ("  << rect.get_x() << ", " << rect.get_y() << "), width: "  << rect.get_width() << ", height: " << rect.get_height() << '\n';
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}