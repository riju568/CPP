#ifndef COMPAREY_HPP
#define COMPAREY_HPP
#include "Point.hpp"
struct CompareY {
    bool operator()(const Point& p1, const Point& p2) const {
        if (p1.getY() != p2.getY()) {
            return p1.getY() < p2.getY();
        }
        return p1.getX() < p2.getX();
    }
};

#endif