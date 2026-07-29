#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stdexcept>
/**
 * *3.34 (Geometry: point on line segment) Programming Exercise 3.32 shows how to test
 * whether a point is on an unbounded line. Revise Programming Exercise 3.32 to
 * test whether a point is on a line segment. Write a program that prompts the user
 * to enter the three points for p0, p1, and p2 and displays whether p2 is on the line
 * segment from p0 to p1.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        double x0 = 0.0, y0 = 0.0;
        double x1 = 0.0, y1 = 0.0;
        double x2 = 0.0, y2 = 0.0;
        std::cout << "Enter three points for p0, p1, and p2: ";
        if (!(std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2)) {
            throw std::runtime_error("Please enter valid numeric values matching the prompt.");
        }

        double determinant = ((x1 - x0) * (y2 - y0)) - ((x2 - x0) * (y1 - y0));
        bool isOnLine = std::abs(determinant) < 1E-5;
        bool isWithinXBounds = x2 >= std::min(x0, x1) && x2 <= std::max(x0, x1);
        bool isWithinYBounds = y2 >= std::min(y0, y1) && y2 <= std::max(y0, y1);

        std::string segmentStatus;
        if (isOnLine && isWithinXBounds && isWithinYBounds) {
            segmentStatus = "is on the line segment";
        } else {
            segmentStatus = "is not on the line segment";
        }
        std::printf("(%.1f, %.1f) %s from (%.1f, %.1f) to (%.1f, %.1f)\n", 
                    x2, y2, segmentStatus.c_str(), x0, y0, x1, y1);

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}