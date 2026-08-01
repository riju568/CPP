#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <exception>

struct Point2D
{
    double x = 0.0;
    double y = 0.0;

    Point2D midpoint(const Point2D& other) const
    {
        return {(x + other.x) / 2.0, (y + other.y) / 2.0};
    }
};

class SierpinskiTriangle
{
private:
    int order = 0;

    void displayTriangles(int currentOrder, Point2D p1, Point2D p2, Point2D p3) const
    {
        if (currentOrder == 0)
        {
            std::cout << "Triangle: (" << p1.x << "," << p1.y << "), ("
                      << p2.x << "," << p2.y << "), ("
                      << p3.x << "," << p3.y << ")\n";
        }
        else
        {
            Point2D p12 = p1.midpoint(p2);
            Point2D p23 = p2.midpoint(p3);
            Point2D p31 = p3.midpoint(p1);

            displayTriangles(currentOrder - 1, p1, p12, p31);
            displayTriangles(currentOrder - 1, p12, p2, p23);
            displayTriangles(currentOrder - 1, p31, p23, p3);
        }
    }

public:
    void setOrder(int newOrder)
    {
        if (newOrder < 0)
        {
            return;
        }
        order = newOrder;
        paint();
    }

    void increaseByOne() { setOrder(order + 1); }
    void decreaseByOne() { setOrder(order - 1); }

    void paint() const
    {
        std::cout << "\n--- Sierpinski Triangle (Order " << order << ") ---\n";
        Point2D p1{100.0, 10.0};
        Point2D p2{10.0, 190.0};
        Point2D p3{190.0, 190.0};
        displayTriangles(order, p1, p2, p3);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        SierpinskiTriangle triangle;
        triangle.paint();

        char command = '\0';
        std::cout << "\nControls: Enter '+' to increase order, '-' to decrease order, 'q' to quit.\n";
        
        while (std::cin >> command && command != 'q')
        {
            if (command == '+')
            {
                triangle.increaseByOne();
            }
            else if (command == '-')
            {
                triangle.decreaseByOne();
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}