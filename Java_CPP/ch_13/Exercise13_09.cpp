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
    double getDiameter() const { return 2.0 * radius; }
    double getArea() const override {
        return radius * radius * PI;
    }
    double getPerimeter() const override {
        return 2.0 * radius * PI;
    }
    bool equals(const Circle& other) const {
        return this->radius == other.radius;
    }

    bool operator==(const Circle& other) const {
        return equals(other);
    }
    int compareTo(const Circle& c1) const {
        if (this->radius > c1.radius) {
            return 1;
        } else if (this->radius < c1.radius) {
            return -1;
        } else {
            return 0;
        }
    }

    void printCircle() const {
        std::time_t time = std::chrono::system_clock::to_time_t(getDateCreated());
        std::string timeStr = std::ctime(&time);
        if (!timeStr.empty() && timeStr.back() == '\n') {
            timeStr.pop_back();
        }
        std::cout << "The circle is created " << timeStr << " and the radius is " << radius << '\n';
    }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        Circle c1(12.23);
        Circle c2(67.89);
        Circle c3(65.43);
        Circle c4(12.23);
        std::cout << "c1.equals(c2): " << (c1.equals(c2) ? "true" : "false") << '\n';
        std::cout << "c1.equals(c4): " << (c1.equals(c4) ? "true" : "false") << '\n';
        std::cout << "c2.compareTo(c3): " << c2.compareTo(c3) << '\n';
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