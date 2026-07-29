#include <iostream>
#include <cmath>
#include <exception>
/**
 * 2.18 (Print a table) Write a program that displays the following table. Cast floating point
 * numbers into integers.
 * a b pow(a, b)
 * 1 2 1
 * 2 3 8
 * 3 4 81
 * 4 5 1024
 * 5 6 15625
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "a    b    pow(a,b)\n";

        int a = 1;
        int b = 2;

        std::cout << a << "    " << b << "    " << static_cast<int>(std::pow(a, b)) << '\n';
        a++;
        b++;
        std::cout << a << "    " << b << "    " << static_cast<int>(std::pow(a, b)) << '\n';
        a++;
        b++;
        std::cout << a << "    " << b << "    " << static_cast<int>(std::pow(a, b)) << '\n';
        a++;
        b++;
        std::cout << a << "    " << b << "    " << static_cast<int>(std::pow(a, b)) << '\n';
        a++;
        b++;
        std::cout << a << "    " << b << "    " << static_cast<int>(std::pow(a, b)) << '\n';
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