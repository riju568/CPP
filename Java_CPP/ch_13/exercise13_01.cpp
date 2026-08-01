#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <ctime>
#include <exception>
#include <algorithm>

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
};


class Triangle : public GeometricObject {
private:
    double side1{1.0};
    double side2{1.0};
    double side3{1.0};

public:
    Triangle() = default;

    Triangle(double s1, double s2, double s3)
        : side1(s1), side2(s2), side3(s3) {}

    double getSide1() const { return side1; }
    void setSide1(double s1) { side1 = s1; }

    double getSide2() const { return side2; }
    void setSide2(double s2) { side2 = s2; }

    double getSide3() const { return side3; }
    void setSide3(double s3) { side3 = s3; }

    double getArea() const override {
        double s = 0.5 * (side1 + side2 + side3);
        double areaSq = s * (s - side1) * (s - side2) * (s - side3);
        return (areaSq > 0.0) ? std::sqrt(areaSq) : 0.0;
    }

    double getPerimeter() const override {
        return side1 + side2 + side3;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Please Enter the 3 sides of the triangle now: ";
        double side1 = 0.0;
        double side2 = 0.0;
        double side3 = 0.0;

        if (!(std::cin >> side1 >> side2 >> side3))
        {
            std::cerr << "Error: Invalid numeric input received for triangle sides.\n";
            return 3;
        }

        std::cout << "Now enter a color followed by true or false for if the triangle is filled: ";
        std::string color;
        std::string filledStr;

        if (!(std::cin >> color >> filledStr))
        {
            std::cerr << "Error: Invalid input received for color or fill status.\n";
            return 3;
        }
        std::string fillLower = filledStr;
        std::transform(fillLower.begin(), fillLower.end(), fillLower.begin(), ::tolower);
        bool isFilled = false;
        if (fillLower == "true" || fillLower == "1")
        {
            isFilled = true;
        }
        else if (fillLower == "false" || fillLower == "0")
        {
            isFilled = false;
        }
        else
        {
            std::cerr << "Error: Invalid boolean string received. Use 'true' or 'false'.\n";
            return 3;
        }
        Triangle triangle(side1, side2, side3);
        triangle.setColor(color);
        triangle.setFilled(isFilled);
        std::cout << "The area of the triangle is " << triangle.getArea() << '\n';
        std::cout << "The Perimeter of the triangle is " << triangle.getPerimeter() << '\n';
        std::cout << "Its color is currently " << triangle.getColor() << '\n';
        std::cout << "Its filled status is currently " << (triangle.isFilled() ? "true" : "false") << '\n';
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