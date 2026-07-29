#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * *10.12 (Exercise 10_12 Test Driver) Write a test program that creates a Triangle2D
 * object t1 using the constructor
 * new Triangle2D(new MyPoint(2.5, 2), new MyPoint(4.2, 3), new MyPoint(5, 3.5)),
 * displays its area and perimeter, and displays the result of:
 * - t1.contains(3, 3)
 * - t1.contains(new Triangle2D(new MyPoint(2.9, 2), new MyPoint(4, 1), new MyPoint(1, 3.4)))
 * - t1.overlaps(new Triangle2D(new MyPoint(2, 5.5), new MyPoint(4, -3), new MyPoint(2, 6.5)))
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

    double distance(const MyPoint &p) const
    {
        return std::sqrt(std::pow(p.x - x, 2) + std::pow(p.y - y, 2));
    }
};

class Triangle2D
{
private:
    MyPoint p1;
    MyPoint p2;
    MyPoint p3;

    static double calculate_area(const MyPoint &pt1, const MyPoint &pt2, const MyPoint &pt3)
    {
        return std::abs(pt1.get_x() * (pt2.get_y() - pt3.get_y()) +
                        pt2.get_x() * (pt3.get_y() - pt1.get_y()) +
                        pt3.get_x() * (pt1.get_y() - pt2.get_y())) / 2.0;
    }

    int orientation(const MyPoint &p, const MyPoint &q, const MyPoint &r) const
    {
        double val = (q.get_y() - p.get_y()) * (r.get_x() - q.get_x()) -
                     (q.get_x() - p.get_x()) * (r.get_y() - q.get_y());
        if (std::abs(val) < 1e-9) return 0; // Collinear
        return (val > 0) ? 1 : 2;           // 1: Clockwise, 2: Counterclockwise
    }

    bool on_segment(const MyPoint &p, const MyPoint &q, const MyPoint &r) const
    {
        return (q.get_x() <= std::max(p.get_x(), r.get_x()) && q.get_x() >= std::min(p.get_x(), r.get_x()) &&
                q.get_y() <= std::max(p.get_y(), r.get_y()) && q.get_y() >= std::min(p.get_y(), r.get_y()));
    }

    bool segments_intersect(const MyPoint &a1, const MyPoint &a2, const MyPoint &b1, const MyPoint &b2) const
    {
        int o1 = orientation(a1, a2, b1);
        int o2 = orientation(a1, a2, b2);
        int o3 = orientation(b1, b2, a1);
        int o4 = orientation(b1, b2, a2);

        if (o1 != o2 && o3 != o4) return true;

        if (o1 == 0 && on_segment(a1, b1, a2)) return true;
        if (o2 == 0 && on_segment(a1, b2, a2)) return true;
        if (o3 == 0 && on_segment(b1, a1, b2)) return true;
        if (o4 == 0 && on_segment(b1, a2, b2)) return true;

        return false;
    }

public:
    Triangle2D() : p1(0, 0), p2(0, 2), p3(2, 0) {}

    Triangle2D(const MyPoint &p1, const MyPoint &p2, const MyPoint &p3)
        : p1(p1), p2(p2), p3(p3)
    {
        if (get_area() <= 1e-9)
        {
            throw std::invalid_argument("Error: The three points are collinear and do not form a valid triangle.");
        }
    }

    MyPoint get_p1() const { return p1; }
    MyPoint get_p2() const { return p2; }
    MyPoint get_p3() const { return p3; }

    double get_area() const
    {
        return calculate_area(p1, p2, p3);
    }

    double get_perimeter() const
    {
        return p1.distance(p2) + p2.distance(p3) + p3.distance(p1);
    }

    bool contains(const MyPoint &p) const
    {
        double total_area = get_area();
        double a1 = calculate_area(p, p1, p2);
        double a2 = calculate_area(p, p2, p3);
        double a3 = calculate_area(p, p3, p1);

        return std::abs(total_area - (a1 + a2 + a3)) < 1e-5;
    }

    bool contains(const Triangle2D &t) const
    {
        return contains(t.get_p1()) && contains(t.get_p2()) && contains(t.get_p3());
    }

    bool overlaps(const Triangle2D &t) const
    {
        MyPoint edges1[3][2] = {{p1, p2}, {p2, p3}, {p3, p1}};
        MyPoint edges2[3][2] = {{t.get_p1(), t.get_p2()}, {t.get_p2(), t.get_p3()}, {t.get_p3(), t.get_p1()}};

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (segments_intersect(edges1[i][0], edges1[i][1], edges2[j][0], edges2[j][1]))
                {
                    return true;
                }
            }
        }

        return contains(t) || t.contains(*this) || contains(t.get_p1()) || t.contains(p1);
    }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        Triangle2D t1(MyPoint(2.5, 2), MyPoint(4.2, 3), MyPoint(5, 3.5));

        std::cout << "For the Triangle2D, 't1' ";
        std::cout << "Area = " << t1.get_area() << '\n';
        std::cout << " Perimeter = " << t1.get_perimeter() << '\n';

        std::cout << std::boolalpha;
        std::cout << "Result of t1.contains(3,3) = "
                  << t1.contains(MyPoint(3, 3)) << '\n';

        std::cout << "Result of t1.contains(new Triangle2D(new MyPoint(2.9, 2), new MyPoint(4, 1), MyPoint(1, 3.4))) = "
                  << t1.contains(Triangle2D(MyPoint(2.9, 2), MyPoint(4, 1), MyPoint(1, 3.4))) << '\n';

        std::cout << "Result of t1.overlaps(new Triangle2D(new MyPoint(2, 5.5), new MyPoint(4, -3), MyPoint(2, 6.5))) = "
                  << t1.overlaps(Triangle2D(MyPoint(2, 5.5), MyPoint(4, -3), MyPoint(2, 6.5))) << '\n';

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