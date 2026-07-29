#include <iostream>
#include <cmath>
#include <iomanip>
#include <memory>
#include <exception>
#include <cstdlib>



class MyPoint
{
private:
    double x{0.0};
    double y{0.0};

public:
    MyPoint() = default;
    MyPoint(double xVal, double yVal) : x(xVal), y(yVal) {}
    [[nodiscard]] double getX() const { return x; }
    [[nodiscard]] double getY() const { return y; }
    [[nodiscard]] double distance(double xVal, double yVal) const { return std::hypot(x - xVal, y - yVal); }
    [[nodiscard]] double distance(const MyPoint &point) const { return distance(point.x, point.y); }
    [[nodiscard]] double distance(const std::shared_ptr<MyPoint> &point) const { return point ? distance(point->x, point->y) : 0.0; }
};
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        MyPoint p1(0.0, 0.0);
        MyPoint p2(10.0, 30.5);
        auto p3 = std::make_shared<MyPoint>(0.0, 0.0);
        auto p4 = std::make_shared<MyPoint>(10.0, 30.5);
        std::cout << "The distance between p1 and p2 (Stack) is " << std::fixed << std::setprecision(4) << p2.distance(p1) << "\n";
        std::cout << "The distance between p3 and p4 (Smart Pointers) is " << std::fixed << std::setprecision(4)<< p4->distance(p3) << "\n";
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}