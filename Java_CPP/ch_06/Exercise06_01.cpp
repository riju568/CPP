#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>

/**
 * 6.1 (Math: pentagonal numbers) A pentagonal number is defined
 * as n(3n - 1)/2. Therefore, the first few numbers are 1, 5, 12, 22, . . . .
 * Write a method with the following header that returns a pentagonal number:
 */
constexpr int get_pentagonal_number(int n)
{
    return n * (3 * n - 1) / 2;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        for (int i = 1; i <= 100; ++i)
        {
            if (i % 10 == 0)
            {
                std::cout << std::setw(7) << get_pentagonal_number(i) << '\n';
            }
            else
            {
                std::cout << std::setw(7) << get_pentagonal_number(i);
            }
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