#include <iostream>
#include <exception>
#include <cmath>
#include <numbers>

/**
 * **16.30 (Pattern recognition: consecutive four equal numbers) Write a GUI program for
 * Programming Exercise 8.19, as shown in Figure 16.49a–b. Let the user enter the
 * numbers in the text fields in a grid of 6 rows and 7 columns. The user can click
 * the Solve button to highlight a sequence of four equal numbers,
 * if it exists. Initially, the values in the text fields are filled with numbers from 0 to 9 randomly.
 */

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::cout << "Enter the radius and length of a cylinder: ";

        double radius = 0.0;
        double length = 0.0;

        if (!(std::cin >> radius >> length)) {
            throw std::invalid_argument("Invalid or non-numeric input received.");
        }

        if (radius < 0.0 || length < 0.0) {
            throw std::out_of_range("Radius and length must be non-negative values.");
        }
        #if __cpp_lib_math_constants
            const double pi = std::numbers::pi;
        #else
            const double pi = 3.14159265358979323846;
        #endif
        const double area = radius * radius * pi;
        const double volume = area * length;
        std::cout << "The area is " << area << '\n';
        std::cout << "The volume is " << volume << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown error occurred.\n";
        return 2;
    }

    return 0;
}