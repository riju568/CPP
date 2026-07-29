#include <iostream>
#include <exception>
/**
 * 2.3 (Convert feet into meters) Write a program that reads a number in feet, converts it
 * to meters, and displays the result. One foot is 0.305 meter.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a value for feet: ";
        double numFeet = 0.0;
        if (!(std::cin >> numFeet))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        const double numMeters = numFeet * 0.305;
        std::cout << numFeet << " feet is " << numMeters << " meters\n";
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