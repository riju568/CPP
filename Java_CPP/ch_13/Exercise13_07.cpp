#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <chrono>
#include <ctime>
#include <exception>


class Colorable {
public:
    virtual ~Colorable() = default;
    virtual void howToColor() const = 0;
};

class GeometricObject : public Colorable {
private:
    std::string color{"white"};
    bool filled{false};
    std::chrono::system_clock::time_point dateCreated;

protected:
    GeometricObject() 
        : dateCreated(std::chrono::system_clock::now()) {}

    GeometricObject(std::string col, bool isFilled)
        : color(std::move(col)), filled(isFilled), dateCreated(std::chrono::system_clock::now()) {}

public:
    virtual ~GeometricObject() = default;
    std::string getColor() const { return color; }
    void setColor(const std::string& col) { color = col; }
    bool isFilled() const { return filled; }
    void setFilled(bool fill) { filled = fill; }
    std::chrono::system_clock::time_point getDateCreated() const { return dateCreated; }
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;

    virtual std::string toString() const {
        std::time_t time = std::chrono::system_clock::to_time_t(dateCreated);
        std::string timeStr = std::ctime(&time);
        if (!timeStr.empty() && timeStr.back() == '\n') {
            timeStr.pop_back(); // Remove trailing newline
        }
        return "created on " + timeStr + "\ncolor: " + color + " and filled: " + (filled ? "true" : "false");
    }
};

class Square : public GeometricObject {
private:
    double height{0.0};

public:
    Square() = default;
    explicit Square(double h)  height(h) {}
    Square(double h, const std::string& col, bool isFilled): GeometricObject(col, isFilled), height(h) {}
    double getHeight() const { return height; }
    void setHeight(double h) { height = h; }
    void howToColor() const override {
        std::cout << "Color all four sides.\n";
    }

    double getArea() const override {
        return height * height;
    }

    double getPerimeter() const override {
        return height * 4.0;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::mt19937 rng(std::random_device{}());
        std::uniform_real_distribution<double> dist(0.0, 9.0);
        std::vector<std::unique_ptr<GeometricObject>> test;
        test.reserve(5);

        for (int i = 0; i < 5; ++i) {
            test.push_back(std::make_unique<Square>(dist(rng)));
        }

        for (const auto& object : test) {
            if (object) {
                std::cout << "Area = " << object->getArea() << " squared\n";
                if (auto colorable = dynamic_cast<const Colorable*>(object.get())) {
                    std::cout << "How to color method result: \n";
                    colorable->howToColor();
                }
            }
        }
    }
    catch (const std::exception &e)
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