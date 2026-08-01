#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <exception>

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

class Rectangle : public GeometricObject {
private:
    double width{0.0};
    double height{0.0};

public:
    Rectangle() = default;

    Rectangle(double w, double h) 
        : width(w), height(h) {}

    Rectangle(double w, double h, const std::string& col, bool isFilled)
        : GeometricObject(col, isFilled), width(w), height(h) {}

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
    int compareTo(const Rectangle& obj) const {
        double thisArea = this->getArea();
        double otherArea = obj.getArea();

        if (thisArea > otherArea) return 1;
        if (thisArea < otherArea) return -1;
        return 0;
    }
    bool equals(const Rectangle& obj) const {
        return compareTo(obj) == 0;
    }
    bool operator==(const Rectangle& obj) const {
        return equals(obj);
    }
    std::string toString() const override {
        std::ostringstream oss;
        oss << GeometricObject::toString() << "\nArea: " << getArea() << "\nPerimeter: " << getPerimeter();
        return oss.str();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        Rectangle rectangle1(4.0, 7.0, "Yellow", true);
        Rectangle rectangle2(4.0, 7.0, "Blue", false);
        std::cout << "\nRectangle 1:\n " << rectangle1.toString() << "\n\nand\n\nRectangle 2:\n " << rectangle2.toString() << '\n';
        std::cout << "\nAre they equal? " << (rectangle1.equals(rectangle2) ? "true" : "false") << '\n';
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