#include <iostream>
#include <string>
#include <exception>
std::string dec2Bin(int value, std::string binary = "")
{
    if (value == 0)
    {
        return binary.empty() ? "0" : binary;
    }
    return dec2Bin(value / 2, std::to_string(value % 2) + binary);
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter a decimal(base 10) number as an integer: ";
        int decValue = 0;

        if (!(std::cin >> decValue))
        {
            throw std::runtime_error("Invalid integer input.");
        }

        if (decValue < 0)
        {
            throw std::invalid_argument("Negative integers are not supported.");
        }

        std::cout << decValue << " converted to binary is: " 
                  << dec2Bin(decValue) << '\n';
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