#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>
/**
 * **3.22 (Geometry: point in a circle?) Write a
 * program that prompts the user to enter a point (x, y) and checks whether the
 * point is within the circle centered at (0, 0) with radius 10.
 */

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        double x2 = 0.0;
        double y2 = 0.0;

        std::cout << "Enter a point with two coordinates: ";  
        if (!(std::cin >> x2 >> y2)) {
            throw std::runtime_error("Invalid input: Please enter valid numeric coordinates.");
        }

        double x1 = 0.0;
        double y1 = 0.0;
        double distance_to_zero = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        std::string res = "";
        if (distance_to_zero <= 10.0) {
            res = "is in the circle";
        } else {
            res = "is not in the circle";
        }
        std::cout << "Point (" << x2 << ", " << y2 << ") " << res << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}