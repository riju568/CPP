#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>

double findSide(double x1, double y1, double x2, double y2) {
    return std::hypot(x1 - x2, y1 - y2);
}
bool onSameLine(const std::vector<std::vector<double>>& pts) {
    double determinant = (pts[1][0] - pts[0][0]) * (pts[2][1] - pts[0][1]) 
                         - (pts[2][0] - pts[0][0]) * (pts[1][1] - pts[0][1]);

    return std::abs(determinant) < 1e-14;
}
double getTriangleArea(const std::vector<std::vector<double>>& points) {
    if (points.size() != 3 || points[0].size() != 2) {
        throw std::invalid_argument("Points array must be 3x2.");
    }
    if (onSameLine(points)) {
        return 0.0;
    }
    double s1 = findSide(points[0][0], points[0][1], points[1][0], points[1][1]);
    double s2 = findSide(points[1][0], points[1][1], points[2][0], points[2][1]);
    double s3 = findSide(points[0][0], points[0][1], points[2][0], points[2][1]);
    double s = (s1 + s2 + s3) / 2.0;
    return std::sqrt(s * (s - s1) * (s - s2) * (s - s3));
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::vector<std::vector<double>> points(3, std::vector<double>(2));
        std::cout << "Enter x1, y1, x2, y2, x3, y3: ";
        for (size_t i = 0; i < points.size(); ++i) {
            for (size_t j = 0; j < points[i].size(); ++j) {
                if (!(std::cin >> points[i][j])) {
                    throw std::invalid_argument("Invalid input format.");
                }
            }
        }

        double result = getTriangleArea(points);
        if (result == 0.0) {
            std::cout << "The three points are on the same line\n";
        } else {
            std::cout.precision(2);
            std::cout << std::fixed;
            std::cout << "The area of the triangle is " << result << '\n';
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