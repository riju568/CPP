#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <random>

/**
 * 4.6 (Random points on a circle) Write a program that generates three random points
 * on a circle centered at (0, 0) with radius 40 and display three angles in a triangle
 * formed by these three points, as shown in Figure 4.7a.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        constexpr double RADIUS = 40.0;
        constexpr double PI = 3.14159265358979323846;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(0.0, 2.0 * PI);

        auto to_degrees = [PI](double rad)
        {
            return rad * (180.0 / PI);
        };
        double angle1 = dist(gen);
        double angle2 = dist(gen);
        double angle3 = dist(gen);
        double x1 = RADIUS * std::cos(angle1);
        double y1 = RADIUS * std::sin(angle1);
        double x2 = RADIUS * std::cos(angle2);
        double y2 = RADIUS * std::sin(angle2);
        double x3 = RADIUS * std::cos(angle3);
        double y3 = RADIUS * std::sin(angle3);
        double a = std::hypot(x2 - x3, y2 - y3);
        double b = std::hypot(x1 - x3, y1 - y3);
        double c = std::hypot(x1 - x2, y1 - y2);
        double cos_A = std::clamp((b * b + c * c - a * a) / (2.0 * b * c), -1.0, 1.0);
        double cos_B = std::clamp((a * a + c * c - b * b) / (2.0 * a * c), -1.0, 1.0);
        double cos_C = std::clamp((a * a + b * b - c * c) / (2.0 * a * b), -1.0, 1.0);

        double angle_A = to_degrees(std::acos(cos_A));
        double angle_B = to_degrees(std::acos(cos_B));
        double angle_C = to_degrees(std::acos(cos_C));


        std::cout << "The three angles are: "
                  << std::fixed << std::setprecision(2)
                  << angle_A << ", " << angle_B << ", " << angle_C << '\n';

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}