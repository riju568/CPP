#include <iostream>
#include <cmath>
#include <exception>
/**
 * 2.14 (Health application: computing BMI) Body Mass Index (BMI)
 * is a measure of health on weight. It can be calculated by taking
 * your weight in kilograms and dividing by the square of your height in
 * meters. Write a program that prompts the user to enter a weight in
 * pounds and height in inches and displays the BMI.
 * Note that one pound is 0.45359237 kilograms and one inch is 0.0254 meters.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Please enter your weight in pounds: ";
        double weightInpounds = 0.0;
        if (!(std::cin >> weightInpounds))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        std::cout << "Please enter you height in inches: ";
        double heightInInches = 0.0;
        if (!(std::cin >> heightInInches))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        if (heightInInches == 0.0)
        {
            std::cerr << "Error: Height in inches cannot be zero.\n";
            return 4;
        }
        const double weightInkilograms = weightInpounds * 0.45359237;
        const double heightInmeters = heightInInches * 0.0254;
        const double metersFactor = std::pow(heightInmeters, 2.0);

        std::cout << "Your BMI is: " << (weightInkilograms / metersFactor) << '\n';
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