#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

//__________________________UML DIAGRAM_____________________________*
/*																	|
 * 							  Fan   								|
 *------------------------------------------------------------------|
 * 	-SLOW : int														|
 * 																	|
 *  -MEDIUM : int				    								|
 * 																	|
 * 	-FAST : int			                    						|
 * 																	|
 * 	-speed : int    		                                        |
 *                          										|
 * 	-on : boolean    					                            |
 *                                      							|
 * 	-radius : double   			                                    |
 *                              									|
 * 	-color : String    												|
 *------------------------------------------------------------------|
 * 	 +Fan()				    										|
 * 	 +toString: String								   				|
 *__________________________________________________________________|  */


/**
 * 9.8 (The Fan class) Design a class named Fan to represent a fan. The class contains:
 * ■ Three constants named SLOW, MEDIUM, and FAST with the values 1, 2, and 3 to
 * denote the fan speed.
 * ■ A private int data field named speed that specifies the speed of the fan (the
 * default is SLOW).
 * ■ A private boolean data field named on that specifies whether the fan is on (the
 * default is false).
 * ■ A private double data field named radius that specifies the radius of the fan
 * (the default is 5).
 * ■ A string data field named color that specifies the color of the fan (the default
 * is blue).
 * ■ The accessor and mutator methods for all four data fields.
 * ■ A no-arg constructor that creates a default fan.
 * ■ A method named toString() that returns a string description for the fan. If
 * the fan is on, the method returns the fan speed, color, and radius in one combined string.
 * If the fan is not on, the method returns the fan color and radius
 * along with the string “fan is off” in one combined string.
 * Draw the UML diagram for the class and then implement the class.
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
        std::string special = "";
        if (on) {
            special += "speed=" + std::to_string(speed) +
                       ", radius=" + std::to_string(radius) +
                       ", color='" + color + "'";
        } else {
            special += "fan is off" +
                       ", radius=" + std::to_string(radius) +
                       ", color='" + color + "'";
        }
        return "Fan{" + special + '}';
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        Fan fan1;
        Fan fan2;

        fan1.setSpeed(Fan::FAST);
        fan1.setRadius(10.0);
        fan1.setColor("yellow");
        fan1.setOn(true);

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