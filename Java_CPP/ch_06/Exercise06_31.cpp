#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

/**
 * **6.31 (Financial: credit card number validation) Credit card numbers follow certain patterns.
 * A credit card number must have between 13 and 16 digits. It must start with:
 * ■ 4 for Visa cards
 * ■ 5 for Master cards
 * ■ 37 for American Express cards
 * ■ 6 for Discover cards
 * <p>
 * In 1954, Hans Luhn of IBM proposed an algorithm for validating credit card
 * numbers. The algorithm is useful to determine whether a card number is entered
 * correctly or whether a credit card is scanned correctly by a scanner. Credit card
 * numbers are generated following this validity check, commonly known as the
 * Luhn check or the Mod 10 check, which can be described as follows (for illustration, consider the card number 4388576018402626):
 * <p>
 * 1. Double every second digit from right to left. If doubling of a digit results in a
 * two-digit number, add up the two digits to get a single-digit number.
 * 4388576018402626
 * 2 * 2 = 4
 * 2 * 2 = 4
 * 4 * 2 = 8
 * 1 * 2 = 2
 * 6 * 2 = 12 (1 + 2 = 3)
 * 5 * 2 = 10 (1 + 0 = 1)
 * 8 * 2 = 16 (1 + 6 = 7)
 * 4 * 2 = 8
 * <p>
 * 2. Now add all single-digit numbers from Step 1.
 * 4 + 4 + 8 + 2 + 3 + 1 + 7 + 8 = 37
 * 3. Add all digits in the odd places from right to left in the card number.
 * 6 + 6 + 0 + 8 + 0 + 7 + 8 + 3 = 38
 * 4. Sum the results from Step 2 and Step 3.
 * 37 + 38 = 75
 * 5. If the result from Step 4 is divisible by 10, the card number is valid; otherwise,
 * it is invalid. For example, the number 4388576018402626 is invalid, but the
 * number 4388576018410707 is valid.
 * Write a program that prompts the user to enter a credit card number as a long
 * integer. Display whether the number is valid or invalid. Design your program to
 * use the following methods:
 * <p>
 * // Return true if the card number is valid //
 * public static boolean isValid(long number)
 * <p>
 * // Get the result from Step 2 //
 * public static int sumOfDoubleEvenPlace(long number)
 * <p>
 * // Return this number if it is a single digit, otherwise,
 * return the sum of the two digits //
 * public static int getDigit(int number)
 * <p>
 * // Return sum of odd-place digits in number //
 * public static int sumOfOddPlace(long number)
 * <p>
 * // Return true if the digit d is a prefix for number //
 * public static boolean prefixMatched(long number, int d)
 * <p>
 * // Return the number of digits in d //
 * public static int getSize(long d)
 * <p>
 * // Return the first k number of digits from number. If the
 * * number of digits in number is less than k, return number. //
 * public static long getPrefix(long number, int k)
 */




int get_size(long long d)
{
    return static_cast<int>(std::to_string(d).length());
}
long long get_prefix(long long number, int k)
{
    if (get_size(number) < k)
    {
        return number;
    }
    std::string s = std::to_string(number);
    return std::stoll(s.substr(0, k));
}

bool prefix_matched(long long number, int d)
{
    std::string s = std::to_string(number);
    std::string d_str = std::to_string(d);
    return s.rfind(d_str, 0) == 0;
}
int get_digit(int number)
{
    if (get_size(number) > 1)
    {
        int d1 = number % 10;
        int d2 = number / 10;
        return d1 + d2;
    }
    return number;
}
int sum_of_double_even_place(long long number)
{
    int sum = 0;
    std::string n = std::to_string(number);
    for (int i = static_cast<int>(n.length()) - 2; i >= 0; i -= 2)
    {
        int digit = std::stoi(n.substr(i, 1));
        int temp = digit * 2;
        int d = get_digit(temp);
        sum += d;
    }
    return sum;
}
int sum_of_odd_place(long long number)
{
    int sum = 0;
    std::string n = std::to_string(number);
    for (int i = static_cast<int>(n.length()) - 1; i >= 0; i -= 2)
    {
        int x = std::stoi(n.substr(i, 1));
        sum += x;
    }
    return sum;
}
bool is_valid(long long number)
{
    std::string s = std::to_string(number);
    if (s.length() < 13 || s.length() > 16)
    {
        return false;
    }
    else if (prefix_matched(number, 4) || prefix_matched(number, 6) || prefix_matched(number, 5) || prefix_matched(number, 37))
    {
        int sum_even = sum_of_double_even_place(number);
        int sum_odd = sum_of_odd_place(number);
        int total = sum_even + sum_odd;
        return total % 10 == 0;
    }
    return false;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a credit card number as a long integer: ";
        std::string cc_num;
        if (std::cin >> cc_num)
        {
            long long number = std::stoll(cc_num);
            std::cout << cc_num << (is_valid(number) ? " is valid.\n" : " is invalid.\n");
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}