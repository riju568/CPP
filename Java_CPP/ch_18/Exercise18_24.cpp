#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <stdexcept>
#include <exception>

long long hexCharToDecimal(char ch)
{
    unsigned char uc = static_cast<unsigned char>(ch);
    if (std::isdigit(uc))
    {
        return uc - '0';
    }
    
    uc = static_cast<unsigned char>(std::toupper(uc));
    if (uc >= 'A' && uc <= 'F')
    {
        return 10 + (uc - 'A');
    }

    throw std::invalid_argument("Invalid hexadecimal character encountered.");
}

long long hex2Dec(std::string_view hexString, int low, int high)
{
    if (high < low)
    {
        return 0;
    }

    return hex2Dec(hexString, low, high - 1) * 16 + hexCharToDecimal(hexString[high]);
}

long long hex2Dec(std::string_view hexString)
{
    if (hexString.empty())
    {
        return 0;
    }
    return hex2Dec(hexString, 0, static_cast<int>(hexString.length()) - 1);
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a hex number: ";
        std::string hex;

        if (!(std::cin >> hex))
        {
            throw std::runtime_error("Failed to read input line.");
        }

        std::cout << hex << " is decimal " << hex2Dec(hex) << '\n';
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