#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>
/**
 * 3.1 (Algebra: solve quadratic equations) The two roots of a quadratic equation
 * ax2 + bx + c = 0 can be obtained using the following formula:
 * r1 = -b + 2b2 - 4ac / 2a
 * and r2 = -b - 2b2 - 4ac / 2a
 * b2 - 4ac is called the discriminant of the quadratic equation. If it is positive, the
 * equation has two real roots. If it is zero, the equation has one root. If it is negative,
 * the equation has no real roots.
 * Write a program that prompts the user to enter values for a, b, and c and displays
 * the result based on the discriminant. If the discriminant is positive, display two
 * roots. If the discriminant is 0, display one root. Otherwise, display �The equation
 * has no real roots�.
 * Note that you can use Math.pow(x, 0.5) to compute SQRT(x). Here are some
 * sample runs.
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    try
    {
        std::cout << "Enter values for a, b, and c: ";
        if (!(std::cin >> a >> b >> c))
        {
            throw std::runtime_error("Invalid input: Please enter valid numeric values.");
        }
        if (a == 0.0)
        {
            throw std::invalid_argument("Coefficient 'a' cannot be zero in a quadratic equation.");
        }
        double discriminant = (b * b) - (4.0 * a * c);
        if (discriminant < 0.0)
        {
            std::cout << "The equation has no real roots.\n";
        }
        else if (discriminant > 0.0)
        {
            double r1 = (-b + std::sqrt(discriminant)) / (2.0 * a);
            double r2 = (-b - std::sqrt(discriminant)) / (2.0 * a);
            std::cout << "Two real roots: " << r1 << ", " << r2 << "\n";
        }
        else
        {
            double r = -b / (2.0 * a);
            std::cout << "One real root: " << r << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}