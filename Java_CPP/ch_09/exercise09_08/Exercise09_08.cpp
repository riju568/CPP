#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

/**
 * Write a test program that creates two Fan objects. Assign maximum speed, radius 10, color
 * yellow, and turn it on to the first object. Assign medium speed, radius 5, color
 * blue, and turn it off to the second object. Display the objects by invoking their
 * toString method.
 */


class Fan {
public:
    static const int SLOW = 1;
    static const int MEDIUM = 2;
    static const int FAST = 3;

private:
    int speed;
    bool on;
    double radius;
    std::string color;

public:
    Fan() {
        speed = SLOW;
        on = false;
        radius = 5.0;
        color = "blue";
    }

    int getSpeed() const {
        return speed;
    }

    void setSpeed(int speed) {
        this->speed = speed;
    }

    bool isOn() const {
        return on;
    }

    void setOn(bool on) {
        this->on = on;
    }

    double getRadius() const {
        return radius;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

    std::string getColor() const {
        return color;
    }

    void setColor(const std::string& color) {
        this->color = color;
    }

    std::string toString() const {
        if (on) {
            return "Fan speed: " + std::to_string(speed) + 
                   ", color: " + color + 
                   ", radius: " + std::to_string(radius);
        } else {
            return "Fan color: " + color + 
                   ", radius: " + std::to_string(radius) + 
                   ", fan is off";
        }
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        Fan fan1;
        Fan fan2;

        fan1.setSpeed(Fan::FAST);
        fan1.setRadius(10.0);
        fan1.setColor("yellow");
        fan1.setOn(true);

        // Note: The prompt's main method example sets fan2 speed to FAST then turns it off, 
        // matching the provided Java test logic.
        fan2.setSpeed(Fan::FAST);
        fan2.setRadius(5.0);
        fan2.setColor("blue");
        fan2.setOn(false);

        std::cout << "Fan 1 toString: " << fan1.toString() << '\n';
        std::cout << "Fan 2 toString: " << fan2.toString() << '\n';

        return EXIT_SUCCESS;
    } 
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}