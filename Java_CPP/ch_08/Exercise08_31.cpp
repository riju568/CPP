
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>


/**
 * 8.31 (Geometry: intersecting point) Write a method that returns the
 * intersecting point of two lines. The intersecting point of the two
 * lines can be found by using the formula shown in Programming
 * Exercise 3.25. Assume that (x1, y1) and (x2, y2) are the two points on
 * line 1 and (x3, y3) and (x4, y4) are on line 2............
 * The points are stored in a 4-by-2 two-dimensional array points with
 * (points[0][0], points[0][1]) for (x1, y1). The method returns the
 * intersecting point or null if the two lines are parallel. Write a
 * program that prompts the user to enter four points and displays the
 * intersecting point.
 */


/**
 * Returns the intersecting point of two lines given a 4-by-2 array of points.
 * Line 1 passes through points[0] and points[1].
 * Line 2 passes through points[2] and points[3].
 * Returns an empty vector if the lines are parallel.
 */
std::vector<double> getIntersectingPoint(const std::vector<std::vector<double>>& points) {
    if (points.size() != 4 || points[0].size() != 2) {
        throw std::invalid_argument("Points array must be 4x2.");
    }
    double a1 = points[0][1] - points[1][1];
    double b1 = points[1][0] - points[0][0];
    double c1 = a1 * points[0][0] + b1 * points[0][1];
    double a2 = points[2][1] - points[3][1];
    double b2 = points[3][0] - points[2][0];
    double c2 = a2 * points[2][0] + b2 * points[2][1];
    double determinant = a1 * b2 - a2 * b1;
    if (std::abs(determinant) < 1e-14) {
        return {};
    }
    double x = (c1 * b2 - c2 * b1) / determinant;
    double y = (a1 * c2 - a2 * c1) / determinant;
    return {x, y};
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::vector<std::vector<double>> points(4, std::vector<double>(2));
        std::cout << "Enter x1, y1, x2, y2, x3, y3, x4, y4: ";
        for (size_t i = 0; i < points.size(); ++i) {
            for (size_t j = 0; j < points[i].size(); ++j) {
                if (!(std::cin >> points[i][j])) {
                    throw std::invalid_argument("Invalid input format.");
                }
            }
        }
        std::vector<double> intersectingPoints = getIntersectingPoint(points);
        if (!intersectingPoints.empty()) {
            std::cout << "The intersecting point is at: ( " 
                      << intersectingPoints[0] << ", " 
                      << intersectingPoints[1] << " )\n";
        } else {
            std::cout << "The two lines are parallel\n";
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