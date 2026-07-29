#include <iostream>
#include <iomanip>
#include <exception>
/**
 * 1.10 (Average speed in miles) Assume a runner runs 14 kilometers in 45 minutes and 30
 * seconds. Write a program that displays the average speed in miles per hour. (Note
 * that 1 mile is 1.6 kilometers.)
 */
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        const double numMiles = 14.0 / 1.6;
        const double speed = numMiles / (45.5 / 60.0);
        std::cout << std::fixed << std::setprecision(3) << speed << '\n';
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