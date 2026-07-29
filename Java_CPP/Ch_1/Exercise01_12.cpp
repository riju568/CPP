#include <iostream>
#include <exception>
/**
 * 1.12 (Average speed in kilometers) Assume a runner runs 24 miles in 1 hour, 40 minutes,
 * and 35 seconds. Write a program that displays the average speed in kilometers per
 * hour. (Note that 1 mile is 1.6 kilometers.)
 */
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        const double hrs = 1.0;
        const double mins = 40.0;
        const double secs = 35.0;
        const double totalDist = 24.0;
        const double kiloDist = totalDist * 1.6;
        const double convertToMin = (hrs * 60.0) + mins + (secs / 60.0);
        const double kph = (60.0 * kiloDist) / convertToMin;

        std::cout << kph << '\n';
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