#include <iostream>
#include <exception>
/**
 * 1.6 (Summation of a series) Write a program that displays the result of
 * 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9.
 */

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        const int sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
        std::cout << sum << '\n';
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