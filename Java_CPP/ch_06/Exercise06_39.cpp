#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 6.39 (Geometry: point position) Programming Exercise 3.32 shows how to test whether
 * a point is on the left side of a directed line, on the right, or on the same line.
 * Write the methods with the following headers:
 * /** Return true if point (x2, y2) is on the left side of the
 * * directed line from (x0, y0) to (x1, y1)
 * public static boolean leftOfTheLine(double x0, double y0,
 * double x1, double y1, double x2, double y2)
 * /** Return true if point (x2, y2) is on the same
 * * line from (x0, y0) to (x1, y1)
 * public static boolean onTheSameLine(double x0, double y0,
 * double x1, double y1, double x2, double y2)
 * /** Return true if point (x2, y2) is on the
 * * line segment from (x0, y0) to (x1, y1)
 * public static boolean onTheLineSegment(double x0, double y0,
 * double x1, double y1, double x2, double y2)
 * Write a program that prompts the user to enter the three points for p0, p1, and p2
 * and displays whether p2 is on the left of the line from p0 to p1, right, the same
 * line, or on the line segment.
 */




// Return true if point (x2, y2) is on the left side of the
// directed line from (x0, y0) to (x1, y1)
bool left_of_the_line(double x0, double y0, double x1, double y1, double x2, double y2)
{
    double determinant = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    return determinant > 0;
}

// Return true if point (x2, y2) is on the right side of the
// directed line from (x0, y0) to (x1, y1)
bool right_of_the_line(double x0, double y0, double x1, double y1, double x2, double y2)
{
    double determinant = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    return determinant < 0;
}

// Return true if point (x2, y2) is on the same
// line from (x0, y0) to (x1, y1)
bool on_the_same_line(double x0, double y0, double x1, double y1, double x2, double y2)
{
    double determinant = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    return determinant == 0;
}

// Return true if point (x2, y2) is on the
// line segment from (x0, y0) to (x1, y1)
bool on_the_line_segment(double x0, double y0, double x1, double y1, double x2, double y2)
{
    double determinant = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);

    if (determinant != 0)
    {
        return false;
    }

    // Check if (x2, y2) is within the bounding box of the line segment
    return x2 >= std::min(x0, x1) && x2 <= std::max(x0, x1) &&
           y2 >= std::min(y0, y1) && y2 <= std::max(y0, y1);
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter three sets of coordinates for the points p0, p1, p2 (ex: 4.4 2 6.5 9.5 -5 4): ";

        double x0 = 0.0, y0 = 0.0;
        double x1 = 0.0, y1 = 0.0;
        double x2 = 0.0, y2 = 0.0;

        if (std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2)
        {
            std::string beg = "(" + std::to_string(x2) + "," + std::to_string(y2) + ") is ";
            std::string end = " line from (" + std::to_string(x0) + "," + std::to_string(y0) + ") to (" + std::to_string(x1) + "," + std::to_string(y1) + ")";
            std::string det = "";

            if (on_the_line_segment(x0, y0, x1, y1, x2, y2))
            {
                det += "on the line segment from";
            }
            else if (left_of_the_line(x0, y0, x1, y1, x2, y2))
            {
                det += "on the left side of the";
            }
            else if (right_of_the_line(x0, y0, x1, y1, x2, y2))
            {
                det += "on the right side of the";
            }
            else if (on_the_same_line(x0, y0, x1, y1, x2, y2))
            {
                det += "on the same line as the";
            }

            std::cout << beg << det << end << '\n';
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}