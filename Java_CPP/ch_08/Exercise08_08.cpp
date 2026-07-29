#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * **8.8 (All closest pairs of points) Revise Listing 8.3,
 * FindNearestPoints.java, to display all closest pairs of points with the same
 * minimum distance.
 * 
 * Here is a sample run:
 * 
 * Enter the number of points: 8 Enter 8 points: 0 0 1 1 -1 -1 2 2 -2 -2 -3 -3
 * -4 -4 5 5
 * 
 * The closest two points are (0.0, 0.0) and (1.0, 1.0)
 * 
 * The closest two points are (0.0, 0.0) and (-1.0, -1.0)
 * 
 * The closest two points are (1.0, 1.0) and (2.0, 2.0)
 * 
 * The closest two points are (-1.0, -1.0) and (-2.0, -2.0)
 * 
 * The closest two points are (-2.0, -2.0) and (-3.0, -3.0)
 * 
 * The closest two points are (-3.0, -3.0) and (-4.0, -4.0)
 * 
 * Their distance is 1.4142135623730951
 *
 */
const double EPSILON = 1E-9;
double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void findAllClosestPairs(const std::vector<std::vector<double>>& points) {
    if (points.empty() || points.size() < 2) {
        throw std::invalid_argument("Points array must contain at least 2 elements.");
    }
    double shortestDist = distance(points[0][0], points[0][1], points[1][0], points[1][1]);
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].empty() || points[i].size() < 2) continue;

        for (size_t j = i + 1; j < points.size(); ++j) {
            if (points[j].empty() || points[j].size() < 2) continue;

            double currentDist = distance(points[i][0], points[i][1], points[j][0], points[j][1]);
            if (currentDist < shortestDist) {
                shortestDist = currentDist;
            }
        }
    }

    // Second pass: Print all pairs whose distance matches the minimum distance (using EPSILON safety)
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].empty() || points[i].size() < 2) continue;

        for (size_t j = i + 1; j < points.size(); ++j) {
            if (points[j].empty() || points[j].size() < 2) continue;

            double d = distance(points[i][0], points[i][1], points[j][0], points[j][1]);
            if (std::abs(d - shortestDist) < EPSILON) {
                std::cout << "The closest two points are (" << points[i][0] << ", " << points[i][1] << ") and ("
                          << points[j][0] << ", " << points[j][1] << ")\n";
            }
        }
    }

    std::cout << "Their distance is " << shortestDist << '\n';
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter the number of points: ";
        int numberOfPoints = 0;
        if (!(std::cin >> numberOfPoints)) {
            std::cerr << "Error: Invalid integer input.\n";
            return EXIT_FAILURE;
        }

        if (numberOfPoints < 2) {
            std::cerr << "Error: You must enter at least 2 points.\n";
            return EXIT_FAILURE;
        }

        std::vector<std::vector<double>> points(numberOfPoints, std::vector<double>(2));
        std::cout << "Enter " << numberOfPoints << " points (x y coordinates separated by spaces): ";

        for (int i = 0; i < numberOfPoints; ++i) {
            if (!(std::cin >> points[i][0] >> points[i][1])) {
                std::cerr << "Error: Invalid coordinate format entered. Please use numeric values.\n";
                return EXIT_FAILURE;
            }
        }
        findAllClosestPairs(points);
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