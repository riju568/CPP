#include <iostream>
#include <vector>
#include <cmath>
#include <exception>

struct Point {
    double x;
    double y;
};

int main() {
    try {
        std::vector<Point> points;
        points.reserve(201); // Memory safety & efficiency optimization

        double scaleFactor = 0.0125;
        for (int x = -100; x <= 100; ++x) {
            double px = static_cast<double>(x) + 200.0;
            double py = 200.0 - (scaleFactor * x * x);
            points.push_back({px, py});
        }

        std::cout << "Successfully calculated " << points.size() << " points for f(x) = x^2.\n";
    } catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception occurred.\n";
        return 2;
    }
    return 0;
}