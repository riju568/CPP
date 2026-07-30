#include <iostream>
#include <string>
#include <string_view>
#include <cmath>
#include <memory>
#include <chrono>
#include <format>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <exception>
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
        return std::format("GeometricObject created with color: {} and filled: {}", color, filled);
    }
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class Triangle2D : public GeometricObject {
private:
    double side1{1.0};
    double side2{1.0};
    double side3{1.0};
    static bool isValidTriangle(double s1, double s2, double s3) noexcept {
        return (s1 + s2 > s3) && (s1 + s3 > s2) && (s2 + s3 > s1);
    }

public:
    Triangle2D() = default;

    Triangle2D(double side1, double side2, double side3)
        : GeometricObject(), side1(side1), side2(side2), side3(side3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
            throw std::invalid_argument("Triangle side lengths must be strictly positive.");
        }
        if (!isValidTriangle(side1, side2, side3)) {
            throw std::invalid_argument("The given side lengths do not satisfy the triangle inequality theorem.");
        }
    }

    Triangle2D(double side1, double side2, double side3, std::string_view color, bool filled)
        : GeometricObject(color, filled), side1(side1), side2(side2), side3(side3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
            throw std::invalid_argument("Triangle side lengths must be strictly positive.");
        }
        if (!isValidTriangle(side1, side2, side3)) {
            throw std::invalid_argument("The given side lengths do not satisfy the triangle inequality theorem.");
        }
    }

    double getSide1() const noexcept { return side1; }
    double getSide2() const noexcept { return side2; }
    double getSide3() const noexcept { return side3; }
    double getArea() const noexcept override {
        double s = getPerimeter() / 2.0;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double getPerimeter() const noexcept override {
        return side1 + side2 + side3;
    }

    std::string toString() const override {
        return std::format("Triangle2D: side1 = {:.1f} side2 = {:.1f} side3 = {:.1f}", side1, side2, side3);
    }
};
bool parseBooleanInput(const std::string& inputStr) {
    std::string lowerInput = inputStr;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    if (lowerInput == "true" || lowerInput == "yes" || lowerInput == "y" || lowerInput == "1") {
        return true;
    }
    if (lowerInput == "false" || lowerInput == "no" || lowerInput == "n" || lowerInput == "0") {
        return false;
    }

    throw std::invalid_argument("Invalid boolean input. Expected 'true/false' or 'yes/no'.");
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter three sides of the triangle: ";
        double side1{}, side2{}, side3{};
        if (!(std::cin >> side1 >> side2 >> side3)) {
            throw std::runtime_error("Invalid input stream reading side lengths.");
        }
        std::cout << "Enter color: ";
        std::string color;
        if (!(std::cin >> color)) {
            throw std::runtime_error("Invalid input stream reading color.");
        }

        std::cout << "Is the triangle filled? (true/false or yes/no): ";
        std::string fillInput;
        if (!(std::cin >> fillInput)) {
            throw std::runtime_error("Invalid input stream reading filled status.");
        }
        bool filled = parseBooleanInput(fillInput);
        std::unique_ptr<GeometricObject> shape = 
            std::make_unique<Triangle2D>(side1, side2, side3, color, filled);


        std::cout << "\n---------------- Result ----------------\n";
        std::cout << shape->toString() << '\n';
        std::cout << std::format("Area: {:.2f} square units\n", shape->getArea());
        std::cout << std::format("Perimeter: {:.2f}\n", shape->getPerimeter());
        std::cout << std::format("Color: {}\n", shape->getColor());
        std::cout << std::format("Filled: {}\n", shape->isFilled() ? "true" : "false");

        return EXIT_SUCCESS;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Validation Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (const std::exception& e) {
        std::cerr << "Execution Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown fatal error occurred.\n";
        return EXIT_FAILURE;
    }
}