#include <iostream>
#include <exception>
/**
 * 1.7 (Approximate &Pi;) &Pi; can be computed using the following formula:
 * p = 4 * ¢1 - 1 3 + 1 5 - 17 + 1 9 - 11 1 + c ≤
 * Write a program that displays the result of 4 * ¢1 - 1 3 + 15 - 1 7 + 1 9 - 11 1 ≤
 * and 4 * ¢1 - 13 + 1 5 - 17 + 1 9 - 11 1 + 13 1 ≤. Use 1.0 instead of 1 in your
 * program.
 */
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        const double approxPi = 4.0 * (1.0 - 1.0 / 3.0 + 1.0 / 5.0 - 1.0 / 7.0 + 1.0 / 9.0 - 1.0 / 11.0);
        const double approxPi2 = 4.0 * (1.0 - 1.0 / 3.0 + 1.0 / 5.0 - 1.0 / 7.0 + 1.0 / 9.0 - 1.0 / 11.0 + 1.0 / 13.0);
        std::cout << approxPi << '\n';
        std::cout << approxPi2 << '\n';
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