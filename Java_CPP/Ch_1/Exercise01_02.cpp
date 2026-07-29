#include <iostream>
#include <string_view>
#include <exception>
/**
 * 1.2 (Display five messages) Write a program that displays Welcome to Java five times
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
        int count = 0;
        const int targetCount = 5;

        while (count < targetCount)
        {
            displayMessage("Welcome to C++");
            ++count;
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