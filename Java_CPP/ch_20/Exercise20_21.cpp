#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cmath>
#include <functional>
#include <exception>


class GeometricObject {
public:
    virtual double get_area() const = 0;
    virtual double get_perimeter() const = 0;
    virtual std::string to_string() const = 0;
    virtual ~GeometricObject() = default; 
};

class Circle : public GeometricObject {
private:
    double radius;
public:
    explicit Circle(double r = 1.0) : radius(r) {}
    double get_area() const override { return radius * radius * 3.14159265358979323846; }
    double get_perimeter() const override { return 2 * radius * 3.14159265358979323846; }
    std::string to_string() const override { return "Circle (Radius: " + std::to_string(radius) + ")"; }
};

class Rectangle : public GeometricObject {
private:
    double width;
    double height;
public:
    Rectangle(double w = 1.0, double h = 1.0) : width(w), height(h) {}
    double get_area() const override { return width * height; }
    double get_perimeter() const override { return 2 * (width + height); }
    std::string to_string() const override { return "Rectangle (" + std::to_string(width) + "x" + std::to_string(height) + ")"; }
};

template <typename T, typename Compare>
void selection_sort(std::vector<T>& list, Compare comp) {
    if (list.size() <= 1) return;

    for (size_t i = 0; i < list.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < list.size(); ++j) {
            if (comp(list[j], list[min_idx])) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(list[i], list[min_idx]);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try {
        std::vector<std::unique_ptr<GeometricObject>> list;
        list.push_back(std::make_unique<Circle>(5.0));
        list.push_back(std::make_unique<Rectangle>(4.0, 5.0));
        list.push_back(std::make_unique<Circle>(5.5));
        list.push_back(std::make_unique<Rectangle>(2.4, 5.0));
        list.push_back(std::make_unique<Circle>(0.5));
        list.push_back(std::make_unique<Rectangle>(4.0, 65.0));
        list.push_back(std::make_unique<Circle>(4.5));
        list.push_back(std::make_unique<Rectangle>(4.4, 1.0));
        list.push_back(std::make_unique<Circle>(6.5));
        list.push_back(std::make_unique<Rectangle>(4.0, 5.0));

        // Area comparison comparator
        auto area_comparator = [](const std::unique_ptr<GeometricObject>& a,
                                  const std::unique_ptr<GeometricObject>& b) {
            return a->get_area() < b->get_area();
        };

        selection_sort(list, area_comparator);

        for (size_t i = 0; i < list.size(); ++i) {
            std::cout << "Area of GeometricObject @ list[" << i << "] = " << list[i]->get_area() << '\n';
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Standard Exception: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}