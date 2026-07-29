#include <iostream>
#include <iomanip>
#include <exception>
/**
 * 1.5 (Compute expressions) Write a program that displays the result of
 * <p>
 * 9.5 * 4.5 - 2.5 * 3
 * 45.5 - 3.5
 */

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        const double numerator = (9.5 * 4.5) - (2.5 * 3.0);
        const double denominator = 45.5 - 3.5;
        if (denominator == 0.0)
        {
            std::cerr << "Error: Division by zero.\n";
            return 3;
        }

        const double solution = numerator / denominator;
        std::cout << std::fixed << std::setprecision(4) << solution << '\n';
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