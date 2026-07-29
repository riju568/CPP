#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <stdexcept>
/**
 * *3.32 (Geometry: point position) Given a directed line from point p0(x0, y0) to p1(x1,
 * y1), you can use the following condition to decide whether a point p2(x2, y2) is
 * on the left of the line, on the right, or on the same line.
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
        double determinant = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
        std::string positionDesc;
        if (std::abs(determinant) < 1E-5) {
            positionDesc = "on the line from";
        } else if (determinant > 0) {
            positionDesc = "on the left side of the line from";
        } else {
            positionDesc = "on the right side of the line from";
        }
        std::printf("(%.1f, %.1f) is %s (%.1f, %.1f) to (%.1f, %.1f)\n", 
                    x2, y2, positionDesc.c_str(), x0, y0, x1, y1);

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}