#include <iostream>
#include <string>
#include <string_view>
#include <stdexcept>
#include <exception>

int bin2Dec(std::string_view binaryString, int pow = 0)
{
    if (binaryString.empty())
    {
        return 0;
    }

    char binaryDigit = binaryString.back();
    if (binaryDigit != '0' && binaryDigit != '1')
    {
        throw std::invalid_argument("Input contains non-binary characters.");
    }

    int binaryValue = binaryDigit - '0';
    std::string_view remainingString = binaryString.substr(0, binaryString.length() - 1);

    return (binaryValue * (1 << pow)) + bin2Dec(remainingString, pow + 1);
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter the binary number to convert to decimal: ";
        std::string binaryNum;

        if (!(std::cin >> binaryNum))
        {
            throw std::runtime_error("Failed to read binary input.");
        }

        std::cout << binaryNum << " binary number is equivalent to the decimal integer: " 
                  << bin2Dec(binaryNum) << '\n';
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