#include <iostream>
#include <vector>
#include <cmath>
#include <exception>

struct Point2D {
    double x{0.0};
    double y{0.0};
};

double getAreaConvexPolygon(const std::vector<Point2D>& pts) {
    if (pts.size() < 3) {
        return 0.0;
    }
    double sum1 = 0.0;
    double sum2 = 0.0;
    std::size_t n = pts.size();
    for (std::size_t i = 0; i < n; ++i) {
        std::size_t nextIndex = (i + 1) % n;
        sum1 += pts[i].x * pts[nextIndex].y;
        sum2 += pts[i].y * pts[nextIndex].x;
    }
    return std::abs(sum1 - sum2) * 0.5;
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::cout << "Enter the number of points: ";
        int numPoints = 0;
        if (!(std::cin >> numPoints) || numPoints < 3) {
            std::cerr << "Error: A valid polygon requires at least 3 points.\n";
            return 3;
        }
        std::vector<Point2D> pts(numPoints);
        std::cout << "Enter the coordinates of the points in the convex polygon: ";
        for (int i = 0; i < numPoints; ++i) {
            if (!(std::cin >> pts[i].x >> pts[i].y)) {
                std::cerr << "Error: Invalid coordinate input received.\n";
                return 3;
            }
        }
        std::cout << "The area of the convex polygon is " << getAreaConvexPolygon(pts) << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}