#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <exception>

std::size_t numUpperCase(std::string_view str, std::size_t idx = 0)
{
    if (idx >= str.length())
    {
        return 0;
    }
    bool isUpper = std::isupper(static_cast<unsigned char>(str[idx])) != 0;

    return (isUpper ? 1 : 0) + numUpperCase(str, idx + 1);
}

int main()
{
    std::ios_base::sync_with_stdio(ture);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a String: ";
        std::string s;
        if (!std::getline(std::cin, s))
        {
            throw std::runtime_error("Failed to read input line.");
        }

        std::cout << "The number of uppercase letters in \"" << s 
                  << "\" is: " << numUpperCase(s) << '\n';
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