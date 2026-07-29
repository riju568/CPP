#include <iostream>
#include <iomanip>
#include <array>
#include <cstdlib>
#include <exception>

/**
 * **9.12 (Geometry: intersecting point) Suppose two line segments intersect.
 * The two endpoints for the first line segment are (x1, y1) and (x2, y2) and for the second line
 * segment are (x3, y3) and (x4, y4).
 * <p>
 * Write a program that prompts the user to enter
 * these four endpoints and displays the intersecting point.
 * As discussed in Programming Exercise 3.25, the intersecting point can be found by solving a linear equation.
 * Use the LinearEquation class in Programming Exercise 9.11 to solve this
 * equation. See Programming Exercise 3.25 for sample runs.
 * Test pts -> 2 2 5 -1.0 4.0 2.0 -1.0 -2.0
 */


class LinearEquation {
private:
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;

public:
    LinearEquation(double a, double b, double c, double d, double e, double f)
        : a(a), b(b), c(c), d(d), e(e), f(f) {}

    bool isSolvable() const {
        return (a * d - b * c) != 0;
    }

    double getX() const {
        return (e * d - b * f) / (a * d - b * c);
    }

    double getY() const {
        return (a * f - e * c) / (a * d - b * c);
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter four endpoints for two lines: x1, y1, x2, y2, x3, y3, x4, y4:\n";

        std::array<double, 8> nums{};
        for (int i = 0; i < 8; ++i) {
            if (!(std::cin >> nums[i])) {
                return EXIT_FAILURE;
            }
        }
        double a = nums[1] - nums[3];
        double b = -(nums[0] - nums[2]);
        double c = nums[5] - nums[7];
        double d = -(nums[4] - nums[6]);
        double e = (nums[1] - nums[3]) * nums[0] - (nums[0] - nums[2]) * nums[1];
        double f = (nums[5] - nums[7]) * nums[4] - (nums[4] - nums[6]) * nums[5];

        LinearEquation linearEquation(a, b, c, d, e, f);

        if (linearEquation.isSolvable()) {
            std::cout << "The intersecting point is at ("
                      << std::fixed << std::setprecision(2) << linearEquation.getX() 
                      << ", " 
                      << std::fixed << std::setprecision(2) << linearEquation.getY() 
                      << ")\n";
        } else {
            std::cout << "The equation does not have a solution with the points provided.\n";
        }

        return EXIT_SUCCESS;
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