#include <iostream>
#include <string>
#include <exception>

char getAsHexChar(int value)
{
    if (value >= 10 && value <= 15)
    {
        return static_cast<char>('A' + (value - 10));
    }
    return static_cast<char>('0' + value);
}

std::string dec2Hex(int value)
{
    if (value < 0)
    {
        throw std::invalid_argument("Negative values are not supported.");
    }
    if (value < 16)
    {
        return std::string(1, getAsHexChar(value));
    }

    return dec2Hex(value / 16) + getAsHexChar(value % 16);
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a decimal number to convert to hex: ";
        int number = 0;

        if (!(std::cin >> number))
        {
            throw std::runtime_error("Invalid integer input.");
        }

        std::cout << number << " is equivalent to hexadecimal number " 
                  << dec2Hex(number) << '\n';
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