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
        std::vector<Point> sinePoints;
        std::vector<Point> cosinePoints;
        sinePoints.reserve(401);
        cosinePoints.reserve(401);

        double scaleFactor = 50.0;
        const double pi = 3.14159265358979323846;

        for (int x = -200; x <= 200; ++x) {
            double px = static_cast<double>(x) + 200.0;
            
            double sineY = 200.0 - scaleFactor * std::sin((static_cast<double>(x) / 100.0) * 2.0 * pi);
            sinePoints.push_back({px, sineY});

            double cosineY = 200.0 - scaleFactor * std::cos((static_cast<double>(x) / 100.0) * 2.0 * pi);
            cosinePoints.push_back({px, cosineY});
        }

        std::cout << "Sine and Cosine wave points generated safely without memory leaks.\n";
    } catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception occurred.\n";
        return 2;
    }
    return 0;
}