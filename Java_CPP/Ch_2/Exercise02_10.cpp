#include <iostream>
#include <exception>
/**
 * 2.10 (Science: calculating energy) Write a program that calculates the energy needed
 * to heat water from an initial temperature to a final temperature. Your program
 * should prompt the user to enter the amount of water in kilograms and the initial
 * and final temperatures of the water. The formula to compute the energy is
 * Q = M * (finalTemperature – initialTemperature) * 4184
 * where M is the weight of water in kilograms, temperatures are in degrees Celsius,
 * and energy Q is measured in joules. Here is a sample run:
 * <p>
 * Enter the amount of water in kilograms: 55.5
 * Enter the initial temperature: 3.5
 * Enter the final temperature: 10.5
 * The energy needed is 1625484.0
 */

int main()
{

    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        double weightOfWater = 0.0;
        double initialTemperature = 0.0;
        double finalTemperature = 0.0;
        std::cout << "Enter the amount of water in kilograms: ";
        if (!(std::cin >> weightOfWater))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        std::cout << "Enter the initial temperature: ";
        if (!(std::cin >> initialTemperature))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        std::cout << "Enter the final temperature: ";
        if (!(std::cin >> finalTemperature))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double energy = weightOfWater * (finalTemperature - initialTemperature) * 4184.0;
        std::cout << "The energy needed is " << energy << '\n';
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