#include <cmath>
#include <format>
#include <string>
#include <string_view>
#include <stdexcept>
#include <memory>
#include <chrono>
#include <iostream>
#include <cstdlib>


class GeometricObject {
private:
    std::string color{"white"};
    bool filled{false};
    std::chrono::system_clock::time_point dateCreated;

public:
    GeometricObject() 
        : dateCreated(std::chrono::system_clock::now()) {}

    GeometricObject(std::string_view color, bool filled)
        : color(color), filled(filled), dateCreated(std::chrono::system_clock::now()) {}

    virtual ~GeometricObject() = default;

    std::string getColor() const { return color; }
    void setColor(std::string_view newColor) { color = newColor; }

    bool isFilled() const { return filled; }
    void setFilled(bool fillState) { filled = fillState; }

    std::chrono::system_clock::time_point getDateCreated() const { return dateCreated; }

    virtual std::string toString() const {
        return std::format("created on: {:%Y-%m-%d %H:%M:%S}\ncolor: {} and filled: {}", 
                           dateCreated, color, filled);
    }

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

// Derived Triangle Class matching your Java code directly
class Triangle : public GeometricObject {
private:
    double side1{1.0};
    double side2{1.0};
    double side3{1.0};

    // Helper method to validate Triangle Inequality Theorem
    static bool isValidTriangle(double s1, double s2, double s3) noexcept {
        return (s1 + s2 > s3) && (s1 + s3 > s2) && (s2 + s3 > s1);
    }

public:
    // Default constructor (1.0, 1.0, 1.0)
    Triangle() = default;

    // Parameterized constructor
    Triangle(double newSide1, double newSide2, double newSide3)
        : GeometricObject(), side1(newSide1), side2(newSide2), side3(newSide3) {
        if (newSide1 <= 0 || newSide2 <= 0 || newSide3 <= 0) {
            throw std::invalid_argument("Triangle side lengths must be strictly positive.");
        }
        if (!isValidTriangle(newSide1, newSide2, newSide3)) {
            throw std::invalid_argument("The given sides do not satisfy the triangle inequality theorem.");
        }
    }

    // Heron's formula for area calculation
    double getArea() const noexcept override {
        double s = (this->side1 + this->side2 + this->side3) / 2.0;
        return std::sqrt(s * (s - this->side1) * (s - this->side2) * (s - this->side3));
    }

    // Perimeter calculation
    double getPerimeter() const noexcept override {
        return this->side1 + this->side2 + this->side3;
    }

    // Accessors
    double getSide1() const noexcept { return side1; }
    double getSide2() const noexcept { return side2; }
    double getSide3() const noexcept { return side3; }

    // Overridden toString method matching Java signature
    std::string toString() const override {
        return std::format("Triangle: side1 = {:.1f} side2 = {:.1f} side3 = {:.1f}", 
                           this->side1, this->side2, this->side3);
    }
};