#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <exception>
#include "Point.hpp"
#include "CompareY.hpp"

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        constexpr size_t POINT_COUNT = 100;
        std::vector<Point> points;
        points.reserve(POINT_COUNT);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(0.0, 1000.0);

        for (size_t i = 0; i < POINT_COUNT; ++i) {
            points.emplace_back(dist(gen), dist(gen));
        }
        std::cout << "Created 100 Random Points:\n";
        for (const auto& point : points) {
            std::cout << point;
        }

        std::cout << "\nIncreasing order by the x-coordinates:\n";
        std::sort(points.begin(), points.end());
        for (const auto& point : points) {
            std::cout << point;
        }

        std::cout << "\nIncreasing order by the y-coordinates:\n";
        std::sort(points.begin(), points.end(), CompareY());
        for (const auto& point : points) {
            std::cout << point;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }
    return 0;
}