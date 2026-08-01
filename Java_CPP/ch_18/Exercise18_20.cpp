#include <iostream>
#include <exception>

class RecursiveCirclePane
{
private:
    double distanceBetween = 10.0;
    double width = 340.0;
    double height = 340.0;

    void drawCircles(double radius, std::size_t& count) const
    {
        if (radius > 9.0)
        {
            std::cout << "Circle " << ++count 
                      << " | Center: (" << (width / 2.0) << ", " << (height / 2.0) 
                      << ") | Radius: " << radius << '\n';

            drawCircles(radius - distanceBetween, count);
        }
    }

public:
    void paint() const
    {
        std::cout << "--- Concentric Circles Output ---\n";
        double initialRadius = (((width + height) / 2.0) / 2.0) - distanceBetween;
        std::size_t totalCircles = 0;
        drawCircles(initialRadius, totalCircles);
        std::cout << "Total Circles Drawn: " << totalCircles << "\n\n";
    }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        RecursiveCirclePane pane;
        pane.paint();
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