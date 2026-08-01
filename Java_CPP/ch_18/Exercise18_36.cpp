#include <iostream>
#include <vector>
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

struct Triangle
{
    Point2D p1;
    Point2D p2;
    Point2D p3;
};

class SierpinskiTriangle
{
private:
    std::vector<Triangle> triangles;

    void displayTriangles(int order, const Point2D& p1, const Point2D& p2, const Point2D& p3)
    {
        if (order == 0)
        {
            triangles.push_back({p1, p2, p3});
        }
        else
        {
            Point2D p12 = p1.midpoint(p2);
            Point2D p23 = p2.midpoint(p3);
            Point2D p31 = p3.midpoint(p1);

            displayTriangles(order - 1, p1, p12, p31);
            displayTriangles(order - 1, p12, p2, p23);
            displayTriangles(order - 1, p31, p23, p3);
        }
    }

public:
    void generate(int order, double width = 200.0, double height = 220.0)
    {
        triangles.clear();
        Point2D p1{width / 2.0, 10.0};
        Point2D p2{10.0, height - 10.0};
        Point2D p3{width - 10.0, height - 10.0};

        displayTriangles(order, p1, p2, p3);
    }

    const std::vector<Triangle>& getTriangles() const { return triangles; }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        int order = 0;
        std::cout << "Enter an order for Sierpinski Triangle: ";
        if (!(std::cin >> order) || order < 0)
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        SierpinskiTriangle st;
        st.generate(order);

        std::cout << "Generated Sierpinski Triangle order " << order 
                  << " with " << st.getTriangles().size() << " filled triangles.\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}