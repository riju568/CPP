#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <exception>
#include <memory>

struct Point {
    double x;
    double y;
};

class CirclePolygonSimulator {
private:
    const double radius = 80.0;
    const double width = 200.0;
    const double height = 200.0;
    const double centerX = 100.0;
    const double centerY = 100.0;

    Point randomPointOnCircle() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(0.0, 1.0);

        double angle = dist(gen) * 2.0 * 3.14159265358979323846;
        double a = std::sqrt(dist(gen)) * radius;
        double b = std::cos(angle) * a;
        double c = std::sin(angle) * a;

        return {centerX + b, centerY + c};
    }

public:
    void run() {
        std::vector<Point> points(5);
        for (int i = 0; i < 5; ++i) {
            points[i] = randomPointOnCircle();
        }

        std::cout << "Generated 5 random points on circle:\n";
        for (size_t i = 0; i < points.size(); ++i) {
            std::cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")\n";
        }
    }
};

int main() {
    try {
        auto simulator = std::make_unique<CirclePolygonSimulator>();
        simulator->run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception occurred.\n";
        return 2;
    }
    return 0;
}