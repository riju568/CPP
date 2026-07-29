#include <iostream>
#include <string_view>
#include <exception>
/**
 * 1.4 (Print a table) Write a program that displays the following table:
 * a a^2 a^3
 * 1 1 1
 * 2 4 8
 * 3 9 27
 * 4 16 64
 */
namespace
{
    void displayMessage(std::string_view message)
    {
        std::cout << message << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        const int num = 4;
        displayMessage("a a^2 a^3");

        for (int row = 1; row <= num; ++row)
        {
            int a = row;
            int a2 = row * row;
            int a3 = row * row * row;
            std::cout << a << " " << a2 << " " << a3 << '\n';
        }
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