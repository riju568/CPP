#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * Exercise 9.1 (The Rectangle class) Following the example of the
 * Circle class in Section 9.2, design a class named Rectangle
 * to represent a rectangle. The class contains:
 * <p>
 * Two double data fields named width and height that specify
 * the width and height of the rectangle. The default values
 * are 1 for both width and height.
 * <p>
 * A no-arg constructor that creates a default rectangle.
 * <p>
 * A constructor that creates a rectangle with the specified width and height.
 * <p>
 * A method named getArea() that returns the area of this rectangle.
 * <p>
 * A method named getPerimeter() that returns the perimeter.
 * <p>
 * Draw the UML diagram for the class and then implement the class.
 * Write a test program that creates two Rectangle objects-one with width 4 and height 40 and the other with
 * width 3.5 and height 35.9. Display the width, height, area, and perimeter of each
 * rectangle in this order.
 */


class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle() {
        this->width = 1.0;
        this->height = 1.0;
    }

    Rectangle(double width, double height) {
        setWidth(width);
        setHeight(height);
    }

    double getArea() const {
        return width * height;
    }

    double getPerimeter() const {
        return 2 * (width + height);
    }

    double getWidth() const {
        return width;
    }

    void setWidth(double width) {
        if (width <= 0) {
            throw std::invalid_argument("Width must be greater than 0.");
        }
        this->width = width;
    }

    double getHeight() const {
        return height;
    }

    void setHeight(double height) {
        if (height <= 0) {
            throw std::invalid_argument("Height must be greater than 0.");
        }
        this->height = height;
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        Rectangle r1(4, 40);
        Rectangle r2(3.5, 35.9);

        std::cout << "The width, height, area, and perimeter of rectangle one are "
                  << r1.getWidth() << " , " << r1.getHeight() << " , " 
                  << r1.getArea() << " , " << r1.getPerimeter() << '\n';

        std::cout << "The width, height, area, and perimeter of rectangle two are "
                  << r2.getWidth() << " , " << r2.getHeight() << " , " 
                  << r2.getArea() << " , " << r2.getPerimeter() << '\n';

        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Error initializing rectangle: " << e.what() << '\n';
        return EXIT_FAILURE;
    } 
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}