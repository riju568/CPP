#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <utility>

// ==========================================
// GeometricObject Base Class
// ==========================================
class GeometricObject {
private:
    std::string color{"white"};
    bool filled{false};
    std::chrono::system_clock::time_point dateCreated;

public:
    GeometricObject() : dateCreated(std::chrono::system_clock::now()) {}

    GeometricObject(std::string col, bool isFilled)
        : color(std::move(col)), filled(isFilled), dateCreated(std::chrono::system_clock::now()) {}

    virtual ~GeometricObject() = default;

    [[nodiscard]] std::string getColor() const { return color; }
    void setColor(const std::string& col) { color = col; }

    [[nodiscard]] bool isFilled() const { return filled; }
    void setFilled(bool isFilled) { filled = isFilled; }

    [[nodiscard]] std::chrono::system_clock::time_point getDateCreated() const { return dateCreated; }

    [[nodiscard]] virtual std::string toString() const {
        auto timeT = std::chrono::system_clock::to_time_t(dateCreated);
        std::stringstream ss;
        ss << "created on: " << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S")
           << "\ncolor: " << color << " and filled: " << (filled ? "true" : "false");
        return ss.str();
    }
};

// ==========================================
// Triangle Derived Class
// ==========================================
class Triangle : public GeometricObject {
private:
    double side1{1.0};
    double side2{1.0};
    double side3{1.0};

    [[nodiscard]] static bool isValidTriangle(double s1, double s2, double s3) noexcept {
        return (s1 > 0 && s2 > 0 && s3 > 0) &&
               (s1 + s2 > s3) && (s1 + s3 > s2) && (s2 + s3 > s1);
    }

public:
    Triangle() = default;

    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {
        if (!isValidTriangle(s1, s2, s3)) {
            throw std::invalid_argument("Error: Given side lengths do not form a valid triangle.");
        }
    }

    Triangle(double s1, double s2, double s3, const std::string& color, bool filled)
        : GeometricObject(color, filled), side1(s1), side2(s2), side3(s3) {
        if (!isValidTriangle(s1, s2, s3)) {
            throw std::invalid_argument("Error: Given side lengths do not form a valid triangle.");
        }
    }

    [[nodiscard]] double getSide1() const noexcept { return side1; }
    [[nodiscard]] double getSide2() const noexcept { return side2; }
    [[nodiscard]] double getSide3() const noexcept { return side3; }

    [[nodiscard]] double getPerimeter() const noexcept {
        return side1 + side2 + side3;
    }

    [[nodiscard]] double getArea() const noexcept {
        double s = getPerimeter() / 2.0;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    [[nodiscard]] std::string toString() const override {
        return "Triangle: side1 = " + std::to_string(side1) +
               " side2 = " + std::to_string(side2) +
               " side3 = " + std::to_string(side3);
    }
};

// ==========================================
// Main Function & Application Logic
// ==========================================
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter the three sides of the triangle: ";
        double side1 = 0.0, side2 = 0.0, side3 = 0.0;

        if (!(std::cin >> side1 >> side2 >> side3)) {
            std::cerr << "Error: Invalid numeric input received.\n";
            return 3;
        }

        // Instantiates and validates triangle parameters
        Triangle triangle(side1, side2, side3);

        std::cout << "What color is the triangle? ";
        std::string color;
        if (!(std::cin >> color)) {
            std::cerr << "Error: Invalid color input.\n";
            return 3;
        }

        std::cout << "Is the triangle filled? (Enter Yes or No): ";
        std::string fillInput;
        if (!(std::cin >> fillInput)) {
            std::cerr << "Error: Invalid input.\n";
            return 3;
        }

        std::string fillLower = fillInput;
        std::transform(fillLower.begin(), fillLower.end(), fillLower.begin(), ::tolower);
        bool filled = (fillLower == "yes" || fillLower == "y" || fillLower == "true" || fillLower == "1");

        triangle.setColor(color);
        triangle.setFilled(filled);

        std::cout << "\nFor " << triangle.toString() << " the area is " << triangle.getArea()
                  << " square units,\nThe perimeter is " << triangle.getPerimeter() << '\n';
        std::cout << "The current color is " << triangle.getColor()
                  << "\nAnd is the triangle filled: " << (triangle.isFilled() ? "true" : "false") << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}