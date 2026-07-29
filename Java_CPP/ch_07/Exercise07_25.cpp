#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * 7.25 (Algebra: solve quadratic equations) Solves a quadratic equation 
 * ax^2 + bx + c = 0, storing real roots in an array and returning the count.
 */

int solve_quadratic(const std::vector<double> &eqn, std::vector<double> &roots)
{
    if (eqn.empty() || eqn.size() < 3 || roots.empty())
    {
        return 0;
    }

    double a = eqn[0];
    double b = eqn[1];
    double c = eqn[2];

    // Handle edge case where 'a' is 0 (not a true quadratic equation)
    if (a == 0)
    {
        if (b == 0)
        {
            return 0; // No solution or infinite solutions
        }
        roots[0] = -c / b;
        return 1; // Linear equation root
    }

    double discriminant = (b * b) - (4 * a * c);

    if (discriminant < 0)
    {
        return 0;
    }
    else if (discriminant == 0)
    {
        roots[0] = -b / (2 * a);
        return 1;
    }
    else
    {
        double sqrt_disc = std::sqrt(discriminant);
        roots[0] = (-b + sqrt_disc) / (2 * a);
        roots[1] = (-b - sqrt_disc) / (2 * a);
        return 2;
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter values for a, b, and c: ";
        double a = 0, b = 0, c = 0;
        
        if (!(std::cin >> a >> b >> c))
        {
            std::cout << "Invalid input: Expected three decimal numbers.\n";
            return EXIT_FAILURE;
        }

        std::vector<double> values = {a, b, c};
        std::vector<double> root_vals(2, 0.0);

        int num_roots = solve_quadratic(values, root_vals);
        std::cout << "The number of real roots is " << num_roots << '\n';
        
        if (num_roots > 0)
        {
            std::cout << "The real root values are: ";
            for (int i = 0; i < num_roots; ++i)
            {
                std::cout << root_vals[i] << " ";
            }
            std::cout << '\n';
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