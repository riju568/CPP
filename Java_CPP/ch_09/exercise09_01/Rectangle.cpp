#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/*_______________UML Diagram____________________*
 *______________________________________________*
 *              Rectangle                       *
 *______________________________________________*
 *                                              *
 *  width: double                               *
 *                                              *
 *  height: double                              *
 *                                              *
 *  Rectangle()                                 *
 *                                              *
 *  Rectangle(newWidth: double, newHeight: double)*
 *                                              *
 *  getArea(): double                           *
 *                                              *
 *  getPerimeter(): double                      *
 *                                              *
 * _____________________________________________*
 */


class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle() {
        width = 1.0;
        height = 1.0;
    }

    Rectangle(double newWidth, double newHeight) {
        if (newWidth <= 0 || newHeight <= 0) {
            throw std::invalid_argument("Width and height must be greater than 0.");
        }
        width = newWidth;
        height = newHeight;
    }

    double getArea() const {
        return width * height;
    }

    double getPerimeter() const {
        return (2 * width) + (2 * height);
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
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