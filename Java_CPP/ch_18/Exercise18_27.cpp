#include <iostream>
#include <vector>
#include <cmath>
#include <exception>

constexpr double PI = 3.14159265358979323846;

struct Point
{
    double x = 0.0;
    double y = 0.0;
};

struct Line
{
    Point start;
    Point end;

    double length() const
    {
        return std::sqrt(std::pow(end.x - start.x, 2) + std::pow(end.y - start.y, 2));
    }
};

class KochSnowflake
{
private:
    std::vector<Line> fractalLines;

    void divideLine(const Line& line, std::vector<Line>& nextGen)
    {
        double dist = line.length() / 3.0;
        double dy = line.start.y - line.end.y;
        double dx = line.end.x - line.start.x;
        double th = std::atan2(dy, dx);

        Point p1{line.start.x + dist * std::cos(th), line.start.y - dist * std::sin(th)};
        
        double rad180 = PI;
        double rad120 = (2.0 * PI) / 3.0;

        Point p2{line.end.x + dist * std::cos(th + rad180), line.end.y - dist * std::sin(th + rad180)};
        Point p3{p2.x + dist * std::cos(th + rad120), p2.y - dist * std::sin(th + rad120)};

        nextGen.push_back({line.start, p1});
        nextGen.push_back({p2, line.end});
        nextGen.push_back({p1, p3});
        nextGen.push_back({p3, p2});
    }

public:
    void generate(int order, double width = 350.0, double height = 350.0)
    {
        fractalLines.clear();

        double length = height - 100.0;
        Point p1{width / 2.0, 0.0};
        Point p2{(width / 2.0) + length * std::cos(2.0 * PI / 6.0), length * std::sin(2.0 * PI / 6.0)};
        Point p3{p2.x - length, p2.y};

        fractalLines.push_back({p1, p2});
        fractalLines.push_back({p2, p3});
        fractalLines.push_back({p3, p1});

        for (int i = 0; i < order; ++i)
        {
            std::vector<Line> nextGen;
            for (const auto& line : fractalLines)
            {
                divideLine(line, nextGen);
            }
            fractalLines = std::move(nextGen);
        }
    }

    std::size_t getLineCount() const { return fractalLines.size(); }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter order of Koch Snowflake fractal: ";
        int order = 0;
        if (!(std::cin >> order) || order < 0)
        {
            throw std::invalid_argument("Order must be a non-negative integer.");
        }

        KochSnowflake snowflake;
        snowflake.generate(order);

        std::cout << "Koch Snowflake order " << order 
                  << " generated with " << snowflake.getLineCount() << " line segments.\n";
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