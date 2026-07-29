#include <iostream>
#include <iomanip>
#include <exception>
/**
 * 2.23 (Cost of driving) Write a program that prompts the user to enter the
 * distance to drive, the fuel efficiency of the car in miles per gallon, and
 * the price per gallon, and displays the cost of the trip.
 */
int main()
{

    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        double distance = 0.0;
        double milesPerGallon = 0.0;
        double pricePerGallon = 0.0;

        std::cout << "Enter the driving distance in miles:\n";
        if (!(std::cin >> distance))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        std::cout << "Enter the miles per gallon:\n";
        if (!(std::cin >> milesPerGallon))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        if (milesPerGallon == 0.0)
        {
            std::cerr << "Error: Miles per gallon cannot be zero.\n";
            return 4;
        }
        std::cout << "Enter the price of gas per gallon:\n";
        if (!(std::cin >> pricePerGallon))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double tripCost = (distance / milesPerGallon) * pricePerGallon;
        std::cout << "\nThe cost of driving for this trip is: $"
                  << std::fixed << std::setprecision(2) << tripCost << '\n';
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