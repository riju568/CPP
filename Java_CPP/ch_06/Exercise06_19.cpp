#include <iostream>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * *6.19 (The MyTriangle class) Create a class named MyTriangle that contains the
 * following two methods:
 * bool is_valid(double side1, double side2, double side3)
 * double area(double side1, double side2, double side3)
 *
 * Write a test program that reads three sides for a triangle and computes the area if
 * the input is valid. Otherwise, it displays that the input is invalid.
 */

struct MyTriangle
{

    static constexpr bool is_valid(double side1, double side2, double side3)
    {
        return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
    }

    static double area(double side1, double side2, double side3)
    {
        double s = (side1 + side2 + side3) / 2.0;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

double find_side(double x1, double y1, double x2, double y2)
{
    return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        double x1 = -1.356;
        double y1 = 1.743;
        double x2 = -1.377;
        double y2 = 1.929;
        double x3 = -1.432;
        double y3 = 1.711;

        double s1 = find_side(x1, y1, x2, y2);
        double s2 = find_side(x2, y2, x3, y3);
        double s3 = find_side(x1, y1, x3, y3);

        if (MyTriangle::is_valid(s1, s2, s3))
        {
            std::cout << "The area of the triangle is: " << MyTriangle::area(s1, s2, s3) << '\n';
        }
        else
        {
            std::cout << "The input for sides, is invalid\n";
        }

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