#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Returns the rightmost lowest point in a set of points.
 * Lowest y-coordinate takes precedence; if tied, the highest x-coordinate (rightmost) is chosen.
 */
std::vector<double> getRightmostLowestPoint(const std::vector<std::vector<double>>& points) {
    if (points.empty() || points[0].empty()) {
        throw std::invalid_argument("Points array cannot be empty.");
    }
    std::vector<double> rightmostLowest = points[0];

    for (size_t i = 1; i < points.size(); ++i) {
        if (points[i][1] < rightmostLowest[1]) {
            rightmostLowest = points[i];
        } 
        else if (points[i][1] == rightmostLowest[1]) {
            if (points[i][0] > rightmostLowest[0]) {
                rightmostLowest = points[i];
            }
        }
    }

    return rightmostLowest;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<std::vector<double>> pts(6, std::vector<double>(2));
        std::cout << "Enter 6 points: ";

        for (int p = 0; p < 6; ++p) {
            for (int n = 0; n < 2; ++n) {
                if (!(std::cin >> pts[p][n])) {
                    throw std::invalid_argument("Invalid input format.");
                }
            }
        }

        std::vector<double> result = getRightmostLowestPoint(pts);
        std::cout.precision(1);
        std::cout << std::fixed;
        std::cout << "The rightmost lowest point is (" << result[0] << ", " << result[1] << ")\n";

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