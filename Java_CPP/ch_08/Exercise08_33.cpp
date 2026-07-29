#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <cstdlib>
/**
 * *8.33 (Geometry: polygon subareas) A convex 4-vertex polygon is divided into four
 * triangles, as shown in Figure 8.9.
 * <p>
 * Write a program that prompts the user to enter the coordinates of four vertices and
 * displays the areas of the four triangles in increasing order.
 * <p>
 * Here is a sample run:
 * Enter x1, y1, x2, y2, x3, y3, x4, y4:
 * -2.5 2 4 4 3 -2 -2 -3.5
 * The areas are 6.17 7.96 8.08 10.42
 */
double findSide(double x1, double y1, double x2, double y2) {
    return std::hypot(x1 - x2, y1 - y2);
}

bool onSameLine(const std::vector<std::vector<double>>& pts) {
    double determinant = (pts[1][0] - pts[0][0]) * (pts[2][1] - pts[0][1]) 
                         - (pts[2][0] - pts[0][0]) * (pts[1][1] - pts[0][1]);

    return std::abs(determinant) < 1e-14;
}

double getTriangleArea(const std::vector<std::vector<double>>& points) {
    if (onSameLine(points)) {
        return 0.0;
    }
    double s1 = findSide(points[0][0], points[0][1], points[1][0], points[1][1]);
    double s2 = findSide(points[1][0], points[1][1], points[2][0], points[2][1]);
    double s3 = findSide(points[2][0], points[2][1], points[0][0], points[0][1]);
    double s = (s1 + s2 + s3) / 2.0;
    return std::sqrt(s * (s - s1) * (s - s2) * (s - s3));
}
std::vector<double> solveForIntersectionPoint(const std::vector<std::vector<double>>& pts) {
    double x1 = pts[0][0], y1 = pts[0][1];
    double x2 = pts[2][0], y2 = pts[2][1];
    double x3 = pts[1][0], y3 = pts[1][1];
    double x4 = pts[3][0], y4 = pts[3][1];
    double a = y1 - y2;
    double b = -(x1 - x2);
    double c = y3 - y4;
    double d = -(x3 - x4);
    double e = (y1 - y2) * x1 - (x1 - x2) * y1;
    double f = (y3 - y4) * x3 - (x3 - x4) * y3;
    double D = a * d - b * c;
    double Dx = e * d - b * f;
    double Dy = a * f - e * c;
    if (std::abs(D) < 1e-14) {
        return {0.0, 0.0}; 
    }
    double x = Dx / D;
    double y = Dy / D;

    return {x, y};
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::vector<std::vector<double>> pts(4, std::vector<double>(2));
        std::cout << "Enter x1, y1, x2, y2, x3, y3, x4, y4: ";

        for (int pt = 0; pt < 4; ++pt) {
            for (int xy = 0; xy < 2; ++xy) {
                if (!(std::cin >> pts[pt][xy])) {
                    throw std::invalid_argument("Invalid input format.");
                }
            }
        }
        std::vector<double> intersectionPoint = solveForIntersectionPoint(pts);
        std::vector<double> areas(4);
        std::vector<std::vector<double>> t1 = { pts[0], pts[1], intersectionPoint };
        areas[0] = getTriangleArea(t1);
        std::vector<std::vector<double>> t2 = { pts[1], pts[2], intersectionPoint };
        areas[1] = getTriangleArea(t2);
        std::vector<std::vector<double>> t3 = { pts[2], pts[3], intersectionPoint };
        areas[2] = getTriangleArea(t3);
        std::vector<std::vector<double>> t4 = { pts[3], pts[0], intersectionPoint };
        areas[3] = getTriangleArea(t4);
        std::sort(areas.begin(), areas.end());
        std::cout << "The areas are: ";
        for (double val : areas) {
            std::cout.precision(2);
            std::cout << std::fixed << val << " ";
        }
        std::cout << '\n';

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