#include <iostream>
#include <cmath>
#include <iomanip>
#include <exception>
#include <cstdlib>
#include <limits>

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
    [[nodiscard]] double distance(const MyPoint &other) const { return std::hypot(x - other.x, y - other.y); }
    [[nodiscard]] double distance(double xVal, double yVal) const { return std::hypot(x - xVal, y - yVal); }
};

double readCoordinate(const std::string &prompt)
{
    double val{0.0};
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> val)
        {
            return val;
        }
        std::cout << "Invalid input! Please enter a valid numeric value.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "--- Point 1 ---\n";
        double x1 = readCoordinate("Enter x1: ");
        double y1 = readCoordinate("Enter y1: ");
        std::cout << "\n--- Point 2 ---\n";
        double x2 = readCoordinate("Enter x2: ");
        double y2 = readCoordinate("Enter y2: ");
        MyPoint p1(x1, y1);
        MyPoint p2(x2, y2);
        std::cout << "\nThe distance between p1(" << p1.getX() << ", " << p1.getY() << ")" << " and p2(" << p2.getX() << ", " << p2.getY() << ") is " << std::fixed << std::setprecision(4) << p1.distance(p2) << '\n';
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