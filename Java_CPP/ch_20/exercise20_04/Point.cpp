#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    Point() : x(0.0), y(0.0) {}
    Point(double x_val, double y_val) : x(x_val), y(y_val) {}

    double getX() const { return x; }
    Point& setX(double x_val) { 
        x = x_val; 
        return *this; 
    }

    double getY() const { return y; }
    Point& setY(double y_val) { 
        y = y_val; 
        return *this; 
    }
    bool operator<(const Point& that) const {
        if (this->x != that.x) {
            return this->x < that.x;
        }
        return this->y < that.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "Point{x=" << point.x << ", y=" << point.y << "}\n";
        return os;
    }
};

#endif 