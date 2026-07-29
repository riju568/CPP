#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.12 (Hex to binary) Write a program that prompts the user to enter a hex digit and
 * displays its corresponding binary number. Here is a sample run:
 * Enter a hex digit: B
 * The binary value is 1011
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a hex digit: ";
        std::string input;
        if (!(std::cin >> input))
        {
            std::cout << "Invalid Input.\n";
            return EXIT_SUCCESS;
        }

        if (input.length() == 1 && std::isxdigit(static_cast<unsigned char>(input[0])))
        {
            char hex_char = static_cast<char>(std::toupper(static_cast<unsigned char>(input[0])));
            std::string_view binary_val;

            switch (hex_char)
            {
            case '0':
                binary_val = "0000";
                break;
            case '1':
                binary_val = "0001";
                break;
            case '2':
                binary_val = "0010";
                break;
            case '3':
                binary_val = "0011";
                break;
            case '4':
                binary_val = "0100";
                break;
            case '5':
                binary_val = "0101";
                break;
            case '6':
                binary_val = "0110";
                break;
            case '7':
                binary_val = "0111";
                break;
            case '8':
                binary_val = "1000";
                break;
            case '9':
                binary_val = "1001";
                break;
            case 'A':
                binary_val = "1010";
                break;
            case 'B':
                binary_val = "1011";
                break;
            case 'C':
                binary_val = "1100";
                break;
            case 'D':
                binary_val = "1101";
                break;
            case 'E':
                binary_val = "1110";
                break;
            case 'F':
                binary_val = "1111";
                break;
            }

            std::cout << "The binary value is " << binary_val << '\n';
        }
        else
        {
            std::cout << input << " is an invalid hex digit.\n";
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}