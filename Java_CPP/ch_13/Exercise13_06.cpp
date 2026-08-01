#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <chrono>
#include <ctime>
#include <exception>

constexpr double PI = 3.14159265358979323846;
class GeometricObject {
private:
    std::string color{"white"};
    bool filled{false};
    std::chrono::system_clock::time_point dateCreated;

protected:
    GeometricObject()
        : dateCreated(std::chrono::system_clock::now()) {}

    GeometricObject(std::string col, bool isFilled)
        : color(std::move(col)), filled(isFilled), dateCreated(std::chrono::system_clock::now()) {}

public:
    virtual ~GeometricObject() = default;
    std::string getColor() const { return color; }
    void setColor(const std::string& col) { color = col; }
    bool isFilled() const { return filled; }
    void setFilled(bool fill) { filled = fill; }
    std::chrono::system_clock::time_point getDateCreated() const { return dateCreated; }
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;

    virtual std::string toString() const {
        std::time_t time = std::chrono::system_clock::to_time_t(dateCreated);
        std::string timeStr = std::ctime(&time);
        if (!timeStr.empty() && timeStr.back() == '\n') {
            timeStr.pop_back(); // Remove trailing newline
        }
        return "created on " + timeStr + "\ncolor: " + color + " and filled: " + (filled ? "true" : "false");
    }
};

class Circle : public GeometricObject {
private:
    double radius{0.0};

public:
    Circle() = default;

    explicit Circle(double r)
        : radius(r) {}

    Circle(double r, const std::string& col, bool isFilled)
        : GeometricObject(col, isFilled), radius(r) {}

    double getRadius() const { return radius; }
    void setRadius(double r) { radius = r; }

    double getArea() const override {
        return radius * radius * PI;
    }
    double getPerimeter() const override {
        return 2.0 * radius * PI;
    }
    std::string toString() const override {
        std::ostringstream oss;
        oss << GeometricObject::toString()
            << "\nRadius: " << radius
            << "\nArea: " << getArea()
            << "\nPerimeter: " << getPerimeter();
        return oss.str();
    }
};

class ComparableCircle : public Circle {
public:
    ComparableCircle() = default;
    explicit ComparableCircle(double radius) : Circle(radius) {}
    ComparableCircle(double radius, const std::string& color, bool filled) : Circle(radius, color, filled) {}
    int compareTo(const Circle& circle) const {
        double thisArea = this->getArea();
        double otherArea = circle.getArea();

        if (thisArea > otherArea) return 1;
        if (thisArea < otherArea) return -1;
        return 0;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        ComparableCircle c1(12.51);
        ComparableCircle c2(14.51);
        ComparableCircle c3(12.51);
        std::cout << "C1 area = " << c1.getArea() << ", C2 area = " << c2.getArea() << '\n';
        std::cout << "C1 compareTo C2 = " << c1.compareTo(c2) << '\n';
        std::cout << "C2 area = " << c2.getArea() << ", C1 area = " << c1.getArea() << '\n';
        std::cout << "C2 compareTo C1 = " << c2.compareTo(c1) << '\n';
        std::cout << "C3 area = " << c3.getArea() << ", C1 area = " << c1.getArea() << '\n';
        std::cout << "C3 compareTo C1 = " << c3.compareTo(c1) << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }
    return 0;
}