#include <iostream>
#include <exception>
/**
 * 2.4 (Convert pounds into kilograms) Write a program that converts pounds into kilograms.
 * The program prompts the user to enter a number in pounds, converts it
 * to kilograms, and displays the result. One pound is 0.454 kilograms. Here is a
 * sample run:
 */
int main()
{

    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        std::cout << "Enter a value for number of pounds now: \n";
        double numLbs = 0.0;
        if (!(std::cin >> numLbs))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        const double numKilos = numLbs * 0.454;
        std::cout << numLbs << " pounds is equal to " << numKilos << " kilograms\n";
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