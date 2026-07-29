#include <iostream>
#include <string_view>
#include <exception>
/**
 * *1.3 (Display a pattern) Write a program that displays the following pattern:
 * J A V V A
 * J A A V V A A
 * J J AAAAA V V AAAAA
 * J J A A V A A
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
    // Optimize standard stream performance cross-platform
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        displayMessage("    J    A    V    V    A");
        displayMessage("    J   A A    V  V    A A");
        displayMessage("J   J  AAAAA    V V   AAAAA");
        displayMessage(" J J  A     A    V   A     A");
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