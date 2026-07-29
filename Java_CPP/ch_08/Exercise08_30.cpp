#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * *8.30 (Algebra: solve linear equations) Write a method that solves the following
 * 2 * 2 system of linear equations:
 * a00x + a01y = b0
 * a10x + a11y = b1
 * x =
 * b0a11 - b1a01
 * a00a11 - a01a10
 * y =
 * b1a00 - b0a10
 * a00a11 - a01a10
 * The method header is
 * public static double[] linearEquation(double[][] a, double[] b)
 * The method returns null if a00a11 - a01a10 is 0.
 * <p>
 * Write a test program that
 * prompts the user to enter a00, a01, a10, a11, b0, and b1, and displays the result. If
 * a00a11 - a01a10 is 0, report that “The equation has no solution.” A sample run is
 * similar to Programming Exercise 3.3.
 */
std::vector<double> linearEquation(const std::vector<std::vector<double>>& a, const std::vector<double>& b) {
    if (a.size() != 2 || a[0].size() != 2 || b.size() != 2) {
        throw std::invalid_argument("Matrix 'a' must be 2x2 and vector 'b' must have 2 elements.");
    }
    double denominator = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
    if (std::abs(denominator) < 1e-14) {
        return {};
    }

    double x = ((b[0] * a[1][1]) - (b[1] * a[0][1])) / denominator;
    double y = ((b[1] * a[0][0]) - (b[0] * a[1][0])) / denominator;

    return {x, y};
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::vector<std::vector<double>> a(2, std::vector<double>(2));
        std::vector<double> b(2);
        std::cout << "Enter a00, a01, a10, a11, b0, and b1: ";
        // Reading coefficient matrix 'a'
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < a[i].size(); ++j) {
                if (!(std::cin >> a[i][j])) {
                    throw std::invalid_argument("Invalid input format.");
                }
            }
        }
        for (size_t i = 0; i < b.size(); ++i) {
            if (!(std::cin >> b[i])) {
                throw std::invalid_argument("Invalid input format.");
            }
        }
        std::vector<double> res = linearEquation(a, b);
        if (res.empty()) {
            std::cout << "The equation has no solution.\n";
        } else {
            std::cout << "Value of x is " << res[0] << '\n';
            std::cout << "Value of y is " << res[1] << '\n';
        }
        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    } 
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}