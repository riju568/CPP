
#include <iostream>
#include <cmath>
#include <stdexcept>
/**
 * *3.20 (Science: wind-chill temperature) Programming Exercise 2.17 gives a
 * formula to compute the wind-chill temperature. The formula is valid for
 * temperatures in the range between −58ºF and 41ºF and wind speed greater than
 * or equal to 2.
 * <p>
 * Write a program that prompts the user to enter a temperature and a wind
 * speed. The program displays the wind-chill temperature if the input is valid;
 * otherwise, it displays a message indicating whether the temperature and/or
 * wind speed is invalid.
 */

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        double temp = 0.0;
        int wind_speed = 0;

        std::cout << "Enter the temperature in Fahrenheit between -58°F and 41°F: ";
        if (!(std::cin >> temp))
        {
            throw std::runtime_error("Invalid input: Please enter a valid numeric value for temperature.");
        }

        std::cout << "Enter the wind speed (>=2) in miles per hour: ";
        if (!(std::cin >> wind_speed))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer value for wind speed.");
        }
        if (temp >= -58.0 && temp <= 41.0 && wind_speed >= 2)
        {
            double v_to_pow16 = std::pow(wind_speed, 0.16);
            double twc = 35.74 + 0.6215 * temp - 35.75 * v_to_pow16 + 0.4275 * temp * v_to_pow16;

            std::cout << "The wind chill index is " << twc << "\n";
        }
        else
        {
            std::cout << "Please check to make sure you are entering valid input.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}