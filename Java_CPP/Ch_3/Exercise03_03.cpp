#include <iostream>
#include <stdexcept>

/**
 * *3.3 (Algebra: solve 2 * 2 linear equations) A linear equation can be solved using
 * Cramer's rule given in Programming Exercise 1.13. Write a program that prompts
 * the user to enter a, b, c, d, e, and f and displays the result. If ad - bc is 0, report
 * that "The equation has no solution."
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double d = 0.0;
    double e = 0.0;
    double f = 0.0;

    try
    {
        std::cout << "Enter a, b, c, d, e, f: ";
        if (!(std::cin >> a >> b >> c >> d >> e >> f))
        {
            throw std::runtime_error("Invalid input: Please enter valid numeric values.");
        }

        double denominator = (a * d) - (b * c);
        if (denominator == 0.0)
        {
            std::cout << "The equation has no solution.\n";
        }
        else
        {
            double x = (e * d - b * f) / denominator;
            double y = (a * f - e * c) / denominator;
            std::cout << "x is " << x << " and y is " << y << "\n";
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}