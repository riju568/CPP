#include <iostream>
#include <stdexcept>
#include <cmath>
/**
 * 3.12 (Palindrome number) Write a program that prompts the user to enter a
 * three-digit integer and determines whether it is a palindrome number. A
 * number is palindrome if it reads the same from right to left and from left to
 * right. Here is a sample run of this program:
 * <p>
 * Enter a three-digit integer: 121 121 is a palindrome
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        std::cout << "Please enter a three-digit integer: ";
        int start_num = 0;
        if (!(std::cin >> start_num))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer.");
        }
        if ((start_num < 100 || start_num > 999) && (start_num < -999 || start_num > -100))
        {
            throw std::out_of_range("Error: The entered number must be a three-digit integer.");
        }
        int num_last = start_num % 10;
        int num_first = start_num / 100;
        if (num_last < 0)
            num_last = -num_last;
        if (num_first < 0)
            num_first = -num_first;

        if (num_last == num_first)
        {
            std::cout << start_num << " is a palindrome\n";
        }
        else
        {
            std::cout << start_num << " is not a palindrome\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}