#include <iostream>
#include <string_view>
#include <exception>
/**
 * 1.1 (Display three messages) Write a program that displays Welcome to Java,
 * Welcome to Computer Science, and Programming is fun.
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        displayMessage("Welcome to C++");
        displayMessage("Welcome to Computer Science");
        displayMessage("Programming is fun");
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