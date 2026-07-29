#include <iostream>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 6.5 (Sort three numbers) Write a method with the following header to display three numbers in increasing order:
 * void display_sorted_numbers(double num1, double num2, double num3)
 * Write a test program that prompts the user to enter three numbers and invokes the method to display them in increasing order.
 */
void display_sorted_numbers(double num1, double num2, double num3)
{
    double temp = 0.0;

    if (num1 > num2)
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    if (num2 > num3)
    {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }

    if (num1 > num2)
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    std::cout << "The sorted numbers are " << num1 << " " << num2 << " " << num3 << '\n';
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter three numbers: \n";
        double num1 = 0.0;
        double num2 = 0.0;
        double num3 = 0.0;

        if (!(std::cin >> num1 >> num2 >> num3))
        {
            std::cerr << "Error: Invalid input. Please enter three valid numbers.\n";
            return EXIT_SUCCESS;
        }

        display_sorted_numbers(num1, num2, num3);

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