#include <iostream>
#include <exception>
#include <cstdlib>

/**
 * 6.6 (Display patterns) Write a method to display a pattern as follows:
 * 1
 * 2 1
 * 3 2 1
 * ...
 * n n-1 ... 3 2 1
 * The method header is
 * void display_pattern(int n)
 */
void display_pattern(int n)
{
    int pad = n - 1;
    for (int r = 1; r <= n; ++r)
    {
        for (int p = 0; p < pad; ++p)
        {
            std::cout << "  ";
        }

        for (int i = r; i > 0; --i)
        {
            std::cout << i << ' ';
        }
        std::cout << '\n';
        pad--;
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter the number of rows to print: \n";
        int user_rows = 0;

        if (!(std::cin >> user_rows))
        {
            std::cerr << "Error: Invalid input. Please enter a valid integer.\n";
            return EXIT_SUCCESS;
        }

        display_pattern(user_rows);

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