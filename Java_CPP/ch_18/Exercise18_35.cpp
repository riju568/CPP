#include <iostream>
#include <vector>
#include <exception>

struct Point2D
{
    double x = 0.0;
    double y = 0.0;
};

struct LineSegment
{
    Point2D start;
    Point2D end;
};

class HTree
{
private:
    std::vector<LineSegment> lines;

    void drawH(double x, double y, double size)
    {
        lines.push_back({{x, y}, {x, y + size}});
        lines.push_back({{x + size, y}, {x + size, y + size}});
        lines.push_back({{x, y + size / 2.0}, {x + size, y + size / 2.0}});
    }

    void generateHTree(int order, double x, double y, double size)
    {
        drawH(x, y, size);
        if (order > 0)
        {
            generateHTree(order - 1, x - size / 4.0, y - size / 4.0, size / 2.0);
            generateHTree(order - 1, x + size - size / 4.0, y - size / 4.0, size / 2.0);
            generateHTree(order - 1, x - size / 4.0, y + size - size / 4.0, size / 2.0);
            generateHTree(order - 1, x + size - size / 4.0, y + size - size / 4.0, size / 2.0);
        }
    }

public:
    void generate(int order, double canvasWidth = 350.0, double canvasHeight = 350.0)
    {
        lines.clear();
        double baseSize = canvasHeight / 2.0 - 50.0;
        double centerX = canvasWidth / 2.0 - baseSize / 2.0;
        double centerY = canvasHeight / 2.0 - baseSize / 2.0;

        generateHTree(order, centerX, centerY, baseSize);
    }

    const std::vector<LineSegment>& getLines() const { return lines; }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        int order = 0;
        std::cout << "Enter order of H-Tree fractal: ";
        if (!(std::cin >> order) || order < 0)
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        HTree tree;
        tree.generate(order);

        std::cout << "Generated H-Tree order " << order 
                  << " with " << tree.getLines().size() << " total segments.\n";
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