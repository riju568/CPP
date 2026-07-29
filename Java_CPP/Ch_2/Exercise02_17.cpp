#include <iostream>
#include <cmath>
#include <exception>
/**
 * 2.17 (Science: wind-chill temperature) How cold is it outside? The temperature alone
 * is not enough to provide the answer. Other factors including wind speed, relative
 * humidity, and sunshine play important roles in determining coldness outside.
 * In 2001, the National Weather Service (NWS) implemented the new wind-chill
 * temperature to measure the coldness using temperature and wind speed. The
 * formula is
 * twc = 35.74 + 0.6215ta - 35.75v0.16 + 0.4275tav0.16
 * where ta is the outside temperature measured in degrees Fahrenheit and v is the
 * speed measured in miles per hour. twc is the wind-chill temperature. The formula
 * cannot be used for wind speeds below 2 mph or temperatures below -58 ºF or
 * above 41ºF.
 * <p>
 * Write a program that prompts the user to enter a temperature between -58 ºF and
 * 41ºF and a wind speed greater than or equal to 2 and displays the wind-chill
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        std::cout << "Enter the temperature in Fahrenheit between -58°F and 41°F: \n";
        double temp = 0.0;
        if (!(std::cin >> temp))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        std::cout << "Enter the wind speed (>=2) in miles per hour: \n";
        double windSpeed = 0.0;
        if (!(std::cin >> windSpeed))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double vToPow16 = std::pow(windSpeed, 0.16);
        const double twc = 35.74 + (0.6215 * temp) - (35.75 * vToPow16) + (0.4275 * temp * vToPow16);

        std::cout << "The wind chill index is " << twc << '\n';
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