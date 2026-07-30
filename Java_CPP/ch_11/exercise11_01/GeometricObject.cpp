#include <iostream>
#include <string>
#include <string_view>
#include <cmath>
#include <memory>
#include <chrono>
#include <format>
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
        return std::format("created on: {:%Y-%m-%d %H:%M:%S}\ncolor: {} and filled: {}", 
                           dateCreated, color, filled);
    }

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};


class Triangle2D : public GeometricObject {
private:
    double side1{1.0};
    double side2{1.0};
    double side3{1.0};

    // Helper: Validates Triangle Inequality Theorem
    static bool isValidTriangle(double s1, double s2, double s3) noexcept {
        return (s1 + s2 > s3) && (s1 + s3 > s2) && (s2 + s3 > s1);
    }

public:
    // No-arg Constructor
    Triangle2D() = default;

    // Parameterized Constructors
    Triangle2D(double side1, double side2, double side3)
        : GeometricObject(), side1(side1), side2(side2), side3(side3) {
        validateSides(side1, side2, side3);
    }

    Triangle2D(double side1, double side2, double side3, std::string_view color, bool filled)
        : GeometricObject(color, filled), side1(side1), side2(side2), side3(side3) {
        validateSides(side1, side2, side3);
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
        return std::format("Triangle2D: side1 = {:.1f} side2 = {:.1f} side3 = {:.1f}", 
                           side1, side2, side3);
    }

private:
    static void validateSides(double s1, double s2, double s3) {
        if (s1 <= 0 || s2 <= 0 || s3 <= 0) {
            throw std::invalid_argument("Triangle sides must be positive values.");
        }
        if (!isValidTriangle(s1, s2, s3)) {
            throw std::invalid_argument("The given sides do not form a valid triangle.");
        }
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
    throw std::invalid_argument("Invalid boolean string provided.");
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter the three sides of the triangle: ";
        double side1{}, side2{}, side3{};
        if (!(std::cin >> side1 >> side2 >> side3)) {
            throw std::runtime_error("Invalid side input.");
        }

        std::cout << "What color is the triangle? ";
        std::string color;
        if (!(std::cin >> color)) {
            throw std::runtime_error("Invalid color input.");
        }

        std::cout << "Is the triangle filled? (Enter Yes or No): ";
        std::string fillInput;
        if (!(std::cin >> fillInput)) {
            throw std::runtime_error("Invalid filled input.");
        }

        bool filled = parseBooleanInput(fillInput);


        std::unique_ptr<Triangle2D> triangle = 
            std::make_unique<Triangle2D>(side1, side2, side3, color, filled);

        std::cout << "\nFor " << triangle->toString() << " the area is " 
                  << std::format("{:.2f}", triangle->getArea()) << " square units, \n"
                  << "The perimeter is " << triangle->getPerimeter() << '\n';

        std::cout << "The current color is " << triangle->getColor() << " \n"
                  << "And is the triangle filled is: " 
                  << (triangle->isFilled() ? "true" : "false") << '\n';

        std::cout << "\n[Base Class Information]\n" << triangle->GeometricObject::toString() << '\n';

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
        std::cerr << "An unexpected non-standard exception was caught.\n";
        return EXIT_FAILURE;
    }
}