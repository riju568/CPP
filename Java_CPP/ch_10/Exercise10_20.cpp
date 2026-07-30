#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 10.20 (Approximate e) Programming Exercise 5.26 approximates e using the following
 * series:
 * In order to get better precision, use BigDecimal with 25 digits of precision in
 * the computation. Write a program that displays the e value for i = 100, 200, . . .,
 * and 1000.
 */

class BigDecimal25
{
private:
    std::string integral;
    std::string fractional; 
public:
    BigDecimal25(std::string int_part = "0", std::string frac_part = "0000000000000000000000000")
        : integral(std::move(int_part)), fractional(std::move(frac_part))
    {
        while (fractional.length() < 25) fractional += '0';
        if (fractional.length() > 25) fractional = fractional.substr(0, 25);
    }

    [[nodiscard]] std::string to_string() const
    {
        return integral + "." + fractional;
    }
    BigDecimal25 add(const BigDecimal25 &other) const
    {
        std::string new_frac(25, '0');
        int carry = 0;

        for (int i = 24; i >= 0; --i)
        {
            int sum = (fractional[i] - '0') + (other.fractional[i] - '0') + carry;
            new_frac[i] = static_cast<char>('0' + (sum % 10));
            carry = sum / 10;
        }
        int i1 = std::stoi(integral);
        int i2 = std::stoi(other.integral);
        int int_sum = i1 + i2 + carry;

        return BigDecimal25(std::to_string(int_sum), new_frac);
    }
    BigDecimal25 divide(int divisor) const
    {
        std::string full = integral + fractional;
        std::string quotient;
        int remainder = 0;

        for (char c : full)
        {
            int current = remainder * 10 + (c - '0');
            quotient += static_cast<char>('0' + (current / divisor));
            remainder = current % divisor;
        }
        std::size_t int_len = integral.length();
        std::string new_int = quotient.substr(0, int_len);
        std::string new_frac = quotient.substr(int_len, 25);
        std::size_t start = new_int.find_first_not_of('0');
        if (start == std::string::npos) new_int = "0";
        else new_int = new_int.substr(start);

        return BigDecimal25(new_int, new_frac);
    }

    [[nodiscard]] bool is_zero() const
    {
        return integral == "0" && fractional == "0000000000000000000000000";
    }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Approximating e with 25 digits of precision:\n\n";
        BigDecimal25 e("1", "0000000000000000000000000"); // e = 1
        BigDecimal25 item("1", "0000000000000000000000000"); // item = 1 / 0!

        for (int i = 1; i <= 1000; ++i)
        {
            item = item.divide(i); // item = item / i
            e = e.add(item);       // e = e + item

            if (i % 100 == 0)
            {
                std::cout << "For i = " << std::setw(4) << i << ": e = " << e.to_string() << '\n';
            }
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "An error occurred: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
}