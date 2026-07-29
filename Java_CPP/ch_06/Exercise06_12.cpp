#include <iostream>
#include <exception>
#include <cstdlib>

/**
 * 6.12 (Display characters) Write a method that prints characters using the
 * following header: void print_chars(char ch1, char ch2, int number_per_line)
 * This method prints the characters between ch1 and ch2 with the specified numbers per
 * line. Write a test program that prints ten characters per line from 1 to Z.
 * Characters are separated by exactly one space.
 */
void print_chars(char ch1, char ch2, int number_per_line)
{
    int count = number_per_line;
    while (ch1 <= ch2)
    {
        std::cout << ch1 << ' ';
        ch1++;
        count--;
        if (count == 0)
        {
            std::cout << '\n';
            count = number_per_line;
        }
    }
    if (count != number_per_line)
    {
        std::cout << '\n';
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        print_chars('1', 'Z', 10);

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