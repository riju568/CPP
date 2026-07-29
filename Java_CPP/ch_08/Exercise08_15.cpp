#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>

// Epsilon threshold for safe floating-point zero comparisons
const double EPSILON = 1E-9;

/**
 * *8.15 (Geometry: same line?) Programming Exercise 6.39 gives a method for testing
 * whether three points are on the same line.
 * Write the following method to test whether all the points in the array points are
 * on the same line.
 * public static boolean sameLine(double[][] points)
 * Write a program that prompts the user to enter five points and displays whether
 * they are on the same line. Here are sample runs:
 * Enter five points: 3.4 2 6.5 9.5 2.3 2.3 5.5 5 -5 4
 * The five points are not on the same line
 * <p>
 * From Ex 6.39 via Ex 3.32, if
 * (x1 - x0)*(y2 - y0) - (x2 - x0)*(y1 - y0) == 0
 */

double findDeterminate(const std::vector<std::vector<double>>& pts, size_t index) {
    if (index + 2 >= pts.size() || 
        pts[index].size() < 2 || pts[index + 1].size() < 2 || pts[index + 2].size() < 2) {
        throw std::invalid_argument("Point coordinates are malformed.");
    }
    double x0 = pts[index][0];
    double y0 = pts[index][1];
    double x1 = pts[index + 1][0];
    double y1 = pts[index + 1][1];
    double x2 = pts[index + 2][0];
    double y2 = pts[index + 2][1];
    return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}
bool sameLine(const std::vector<std::vector<double>>& points) {
    if (points.empty() || points.size() < 3) {
        throw std::invalid_argument("Array must contain at least 3 points to evaluate line collinearity.");
    }
    for (size_t i = 0; i < points.size() - 2; ++i) {
        double det = findDeterminate(points, i);
        if (std::abs(det) > EPSILON) {
            return false;
        }
    }
    return true;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter five points (x y coordinates separated by spaces): ";
        std::vector<std::vector<double>> points(5, std::vector<double>(2));
        for (size_t i = 0; i < points.size(); ++i) {
            for (int j = 0; j < 2; ++j) {
                if (!(std::cin >> points[i][j])) {
                    std::cerr << "Error: Invalid numeric input format.\n";
                    return EXIT_FAILURE;
                }
            }
        }
        if (sameLine(points)) {
            std::cout << "The five points are on the same line\n";
        } else {
            std::cout << "The five points are not on the same line\n";
        }
        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Validation Error: " << e.what() << '\n';
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