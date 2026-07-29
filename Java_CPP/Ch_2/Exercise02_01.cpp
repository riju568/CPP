#include <iostream>
#include <exception>

/** 2.1
 * Reads Celsius in double value from the console and converts it to Fahrenheit
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        double celsius = 0.0;
        double fahrenheit = 0.0;
        std::cout << "Enter degrees in Celsius\n";
        if (!(std::cin >> celsius))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }
        fahrenheit = (9.0 / 5.0 * celsius) + 32.0;

        std::cout << fahrenheit << '\n';
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