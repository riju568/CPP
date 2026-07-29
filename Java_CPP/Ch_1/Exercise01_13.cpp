#include <iostream>
#include <iomanip>
#include <exception>
/**
 * (Algebra: solve 2 x 2 linear equations)
 * Write a program that solves the following
 * equation and displays the value for x and y:
 * 3.4x+50.2y=44.5
 * 2.1x+.55y=5.9
 * (Using Cramer's rule to solve 2 x 2 linear equations)
 */
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        const double a = 3.4;
        const double b = 50.2;
        const double c = 2.1;
        const double d = 0.55;
        const double e = 44.5;
        const double f = 5.9;
        const double determinant = (a * d) - (b * c);
        if (determinant == 0.0)
        {
            std::cerr << "Error: The equation has no unique solution (determinant is zero).\n";
            return 3;
        }
        const double x = ((e * d) - (b * f)) / determinant;
        const double y = ((a * f) - (e * c)) / determinant;
        std::cout << "The value for x is: " << std::fixed << std::setprecision(2) << x << '\n';
        std::cout << "The value of y is: " << std::fixed << std::setprecision(2) << y << '\n';
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