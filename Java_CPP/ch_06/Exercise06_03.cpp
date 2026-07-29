#include <iostream>
#include <cmath>
#include <exception>
#include <cstdlib>

/**
 * **6.3 (Palindrome integer) Write the methods with the following headers
 * // Return the reversal of an integer, i.e., reverse(456) returns 654
 * int reverse_integer(int number)
 * // Return true if number is a palindrome
 * bool is_palindrome(int number)
 * Use the reverse method to implement is_palindrome.
 * A number is a palindrome if its reversal is the same as itself.
 * Write a test program that prompts the
 * user to enter an integer and reports whether the integer is a palindrome.
 */

int reverse_integer(int number)
{
    int reversed = 0;
    int remaining = std::abs(number);

    while (remaining > 0)
    {
        int digit = remaining % 10;
        reversed = reversed * 10 + digit;
        remaining /= 10;
    }

    return number < 0 ? -reversed : reversed;
}

bool is_palindrome(int number)
{
    if (number < 0)
    {
        return false;
    }
    return number == reverse_integer(number);
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter an integer: \n";
        int num = 0;

        if (!(std::cin >> num))
        {
            std::cerr << "Error: Invalid input. Please enter a valid integer.\n";
            return EXIT_SUCCESS;
        }

        if (is_palindrome(num))
        {
            std::cout << "Is a palindrome\n";
        }
        else
        {
            std::cout << "Is not a palindrome\n";
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