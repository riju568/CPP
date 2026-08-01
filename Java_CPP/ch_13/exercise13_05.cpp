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
    int compareTo(const GeometricObject& o) const {
        if (this->getArea() > o.getArea()) return 1;
        if (this->getArea() < o.getArea()) return -1;
        return 0;
    }

    static const GeometricObject& max(const GeometricObject& o1, const GeometricObject& o2) {
        return (o1.compareTo(o2) >= 0) ? o1 : o2;
    }

    virtual std::string toString() const {
        std::time_t time = std::chrono::system_clock::to_time_t(dateCreated);
        std::string timeStr = std::ctime(&time);
        if (!timeStr.empty() && timeStr.back() == '\n') {
            timeStr.pop_back(); // Remove trailing newline from std::ctime
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

class Rectangle : public GeometricObject {
private:
    double width{1.0};
    double height{1.0};

public:
    Rectangle() = default;

    Rectangle(double w, double h) 
        : width(w), height(h) {}

    double getWidth() const { return width; }
    void setWidth(double w) { width = w; }

    double getHeight() const { return height; }
    void setHeight(double h) { height = h; }

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2.0 * (width + height);
    }
    std::string toString() const override {
        std::ostringstream oss;
        oss << GeometricObject::toString()
            << "\nWidth: " << width
            << "\nHeight: " << height
            << "\nArea: " << getArea()
            << "\nPerimeter: " << getPerimeter();
        return oss.str();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        Rectangle r1(10.15, 11.55);
        Rectangle r2(31.22, 12.44);

        std::cout << "The larger of the two rectangles is the one:\n";
        std::cout << GeometricObject::max(r1, r2).toString() << "\n\n";

        Circle c1(13.45);
        Circle c2(10.15);

        std::cout << "The larger of the two circles is the one:\n";
        std::cout << GeometricObject::max(c1, c2).toString() << "\n";
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