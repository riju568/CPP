#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
/**
 * **3.9 (Business: check ISBN-10) An ISBN-10 (International Standard Book
 * Number) consists of 10 digits: d1d2d3d4d5d6d7d8d9d10. The last digit, d10, is
 * a checksum, which is calculated from the other nine digits using the
 * following formula: (d1 * 1 + d2 * 2 + d3 * 3 + d4 * 4 + d5 * 5 + d6 * 6 + d7
 * * 7 + d8 * 8 + d9 * 9) % 11 If the checksum is 10, the last digit is denoted
 * as X according to the ISBN-10 convention.
 * <p>
 * Write a program that prompts the user to enter the first 9 digits and
 * displays the 10-digit ISBN (including leading zeros). Your program should
 * read the input as an integer.
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::cout << "Enter the first 9 digits of an ISBN-10 number: ";
        long long isbn = 0;
        if (!(std::cin >> isbn))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer.");
        }
        if (isbn < 0 || isbn > 999999999LL)
        {
            throw std::out_of_range("Input must be a valid positive integer up to 9 digits.");
        }

        long long temp = isbn;
        int sum = 0;
        std::vector<int> digits(9);
        for (int i = 8; i >= 0; i--)
        {
            digits[i] = static_cast<int>(temp % 10);
            temp /= 10;
        }

        for (int i = 0; i < 9; i++)
        {
            int d_num = i + 1;
            int t = digits[i] * d_num;

            std::cout << "d" << d_num << " = " << digits[i] << " ->: ";
            std::cout << "d" << d_num << " * " << d_num << " -> " << digits[i] << " * " << d_num << " = " << t << "\n";

            std::cout << "sum = " << sum << " + " << t << "\n";
            sum += t;
            std::cout << "sum = " << sum << "\n";
        }
        int d10 = sum % 11;
        std::cout << "d10 = sum % 11 -> " << d10 << " = " << sum << " % 11\n";
        std::ostringstream oss;
        oss << std::setw(9) << std::setfill('0') << isbn;
        std::string original_digits = oss.str();

        if (d10 == 10)
        {
            std::cout << "The ISBN-10 number is: " << original_digits << "X\n";
        }
        else
        {
            std::cout << "The ISBN-10 number is: " << original_digits << d10 << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}