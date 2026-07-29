#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Listing 8.3 FindNearestPoints.java from (8.6 Case Study: Finding the Closest
 * Pair) Given a set of points, the closest-pair problem is to find the two
 * points that are nearest to each other.
 *
 * In Figure 8.3, for example, points (1, 1) and (2, 0.5) are closest to each
 * other. There are several ways to solve this problem. An intuitive approach is
 * to compute the distances between all pairs of points and find the one with
 * the minimum distance, as implemented in Listing 8.3
 */
double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void findAndDisplayClosestPoints(const std::vector<std::vector<double>>& points) {
    if (points.empty()) {
        throw std::invalid_argument("Points array cannot be empty.");
    }
    if (points.size() < 2) {
        throw std::invalid_argument("Vector must contain at least 2 points.");
    }
    size_t p1 = 0, p2 = 1;
    while (p1 < points.size() && (points[p1].empty() || points[p1].size() < 2)) {
        p1++;
    }
    p2 = p1 + 1;
    while (p2 < points.size() && (points[p2].empty() || points[p2].size() < 2)) {
        p2++;
    }

    if (p1 >= points.size() || p2 >= points.size()) {
        throw std::invalid_argument("Not enough valid points provided.");
    }
    double shortestDistance = distance(points[p1][0], points[p1][1], points[p2][0], points[p2][1]);
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].empty() || points[i].size() < 2) {
            std::cout << "Warning: Skipping malformed data at index " << i << '\n';
            continue;
        }
        for (size_t j = i + 1; j < points.size(); ++j) {
            if (points[j].empty() || points[j].size() < 2) {
                continue;
            }
            double currentDistance = distance(points[i][0], points[i][1], points[j][0], points[j][1]);
            if (shortestDistance > currentDistance) {
                p1 = i;
                p2 = j;
                shortestDistance = currentDistance;
            }
        }
    }
    std::cout << "The closest two points are (" << points[p1][0] << ", " << points[p1][1] 
              << ") and (" << points[p2][0] << ", " << points[p2][1] 
              << ") with a distance of " << shortestDistance << '\n';
}

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int numberOfPoints = 0;
        std::cout << "Enter the number of points (minimum 2): ";
        
        if (!(std::cin >> numberOfPoints)) {
            std::cerr << "Error: Invalid input. Please enter an integer.\n";
            return EXIT_FAILURE;
        }

        if (numberOfPoints < 2) {
            std::cerr << "Error: You must enter at least 2 points to find a closest pair.\n";
            return EXIT_FAILURE;
        }
        std::vector<std::vector<double>> points(numberOfPoints, std::vector<double>(2));
        std::cout << "Enter " << numberOfPoints << " points (x and y coordinates separated by space): ";
        for (int i = 0; i < numberOfPoints; ++i) {
            if (!(std::cin >> points[i][0] >> points[i][1])) {
                std::cerr << "Error: Invalid coordinate format entered. Please use numeric values.\n";
                return EXIT_FAILURE;
            }
        }
        findAndDisplayClosestPoints(points);
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