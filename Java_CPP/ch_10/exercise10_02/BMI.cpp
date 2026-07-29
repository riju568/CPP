#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <exception>

/**
 * 10.2 (The BMI class) Add the following new constructor in the BMI class:
 * /* Construct a BMI with the specified name, age, weight
 * * feet, and inches
 * <p>
 * public BMI(String name,int age,double weight, double feet, double inches)
 */



class BMI {
private:
    std::string name;
    int age;
    double weight; // in pounds
    double height; // in inches

public:
    static constexpr double KILOGRAMS_PER_POUND = 0.45359237;
    static constexpr double METERS_PER_INCH = 0.0254;

    // Primary constructor
    BMI(std::string name, int age, double weight, double height)
        : name(std::move(name)), age(age), weight(weight), height(height) {}

    // Constructor taking feet and inches (converted to total inches)
    BMI(std::string name, int age, double weight, double feet, double inches)
        : BMI(std::move(name), age, weight, (feet * 12.0) + inches) {}

    // Default age constructor
    BMI(std::string name, double weight, double height)
        : BMI(std::move(name), 20, weight, height) {}

    double getBMI() const {
        double weightInKilograms = weight * KILOGRAMS_PER_POUND;
        double heightInMeters = height * METERS_PER_INCH;
        double bmi = weightInKilograms / (heightInMeters * heightInMeters);
        return std::round(bmi * 100.0) / 100.0;
    }

    std::string getStatus() const {
        double bmi = getBMI();
        if (bmi < 18.5)
            return "Underweight";
        if (bmi < 25.0)
            return "Normal";
        if (bmi < 30.0)
            return "Overweight";
        return "Obese";
    }

    std::string getName() const { return name; }
    int getAge() const { return age; }
    double getWeight() const { return weight; }
    double getHeight() const { return height; }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        BMI bmi1("John Doe", 18, 145, 5, 10); std::cout << "The BMI for " << bmi1.getName() << " is " << std::fixed << std::setprecision(2) << bmi1.getBMI()  << " (" << bmi1.getStatus() << ")\n";
        BMI bmi2("Peter King", 215, 70);
        std::cout << "The BMI for " << bmi2.getName() << " is "  << std::fixed << std::setprecision(2) << bmi2.getBMI()  << " (" << bmi2.getStatus() << ")\n";
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