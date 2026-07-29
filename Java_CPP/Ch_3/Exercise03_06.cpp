#include <iostream>
#include <stdexcept>
/**
 * 3.6 (Health application: BMI) Revise Listing 3.4, ComputeAndInterpretBMI.java, to
 * let the user enter weight, feet, and inches. For example, if a person is 5 feet and 10
 * inches, you will enter 5 for feet and 10 for inches.
 * <p>
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        double weight = 0.0;
        double feet = 0.0;
        double inches = 0.0;
        std::cout << "Enter weight in pounds: ";
        if (!(std::cin >> weight))
        {
            throw std::runtime_error("Invalid input: Please enter a valid numeric value for weight.");
        }
        std::cout << "Enter height by first entering feet followed by a space and then inches (ex. 5 10): ";
        if (!(std::cin >> feet >> inches))
        {
            throw std::runtime_error("Invalid input: Please enter valid numeric values for height.");
        }
        if (weight < 0.0 || feet < 0.0 || inches < 0.0)
        {
            throw std::out_of_range("Weight, feet, and inches cannot be negative values.");
        }

        double height = inches + (feet * 12.0);

        const double KILOGRAMS_PER_POUND = 0.45359237; // Constant
        const double METERS_PER_INCH = 0.0254;         // Constant

        // Compute BMI
        double weight_in_kilograms = weight * KILOGRAMS_PER_POUND;
        double height_in_meters = height * METERS_PER_INCH;

        if (height_in_meters == 0.0)
        {
            throw std::runtime_error("Height cannot be zero.");
        }

        double bmi = weight_in_kilograms / (height_in_meters * height_in_meters);

        std::cout << "BMI is " << bmi << "\n";
        if (bmi < 18.5)
        {
            std::cout << "Underweight\n";
        }
        else if (bmi < 25.0)
        {
            std::cout << "Normal\n";
        }
        else if (bmi < 30.0)
        {
            std::cout << "Overweight\n";
        }
        else
        {
            std::cout << "Obese\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}