#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Computes the Euclidean distance between two 3D points (x1, y1, z1) and (x2, y2, z2).
 */
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return std::sqrt(
        std::pow(x2 - x1, 2) + 
        std::pow(y2 - y1, 2) + 
        std::pow(z2 - z1, 2)
    );
}

/**
 * Finds and displays the two closest points in a 3D coordinate space.
 */
void findDistance3D(const std::vector<std::vector<double>>& points) {
    if (points.empty()) {
        throw std::invalid_argument("Points array cannot be empty.");
    }
    if (points.size() < 2) {
        throw std::invalid_argument("Array must contain at least 2 points to find a closest pair.");
    }

    size_t p1 = 0, p2 = 1; // Indices of the two closest points
    
    // Validate initial points have 3 dimensions (x, y, z)
    if (points[p1].empty() || points[p1].size() < 3 || points[p2].empty() || points[p2].size() < 3) {
        throw std::invalid_argument("Points must contain 3 coordinates (x, y, z).");
    }

    double shortestDistance = distance(
        points[p1][0], points[p1][1], points[p1][2], 
        points[p2][0], points[p2][1], points[p2][2]
    );

    // Compute distance for every unique pair of points
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].empty() || points[i].size() < 3) {
            std::cout << "Warning: Skipping malformed point data at index " << i << '\n';
            continue;
        }

        for (size_t j = i + 1; j < points.size(); ++j) {
            if (points[j].empty() || points[j].size() < 3) {
                continue;
            }

            double currentDistance = distance(
                points[i][0], points[i][1], points[i][2], 
                points[j][0], points[j][1], points[j][2]
            );

            if (shortestDistance > currentDistance) {
                p1 = i;
                p2 = j;
                shortestDistance = currentDistance;
            }
        }
    }

    // Display results
    std::cout << "The closest two points in 3D space are (" 
              << points[p1][0] << ", " << points[p1][1] << ", " << points[p1][2] << ") and (" 
              << points[p2][0] << ", " << points[p2][1] << ", " << points[p2][2] 
              << ") with a distance of " << shortestDistance << '\n';
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<std::vector<double>> points = {
            { -1, 0, 3 }, 
            { -1, -1, -1 }, 
            { 4, 1, 1 }, 
            { 2, 0.5, 9 }, 
            { 3.5, 2, -1 },
            { 3, 1.5, 3 }, 
            { -1.5, 4, 2 }, 
            { 5.5, 4, -0.5 }
        };

        findDistance3D(points);

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