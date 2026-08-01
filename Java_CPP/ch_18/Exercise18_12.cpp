#include <iostream>
#include <string>
#include <string_view>
#include <exception>

void reverseDisplay(std::string_view value, std::size_t high)
{
    if (value.empty())
    {
        return;
    }

    std::cout << value[high];

    if (high > 0)
    {
        reverseDisplay(value, high - 1);
    }
}

void reverseDisplay(std::string_view value)
{
    if (!value.empty())
    {
        reverseDisplay(value, value.length() - 1);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a String: ";
        std::string s;
        if (!(std::cin >> s))
        {
            throw std::runtime_error("Failed to read string.");
        }

        reverseDisplay(s);
        std::cout << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}