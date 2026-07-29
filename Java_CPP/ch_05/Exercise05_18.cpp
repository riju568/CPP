#include <iostream>
#include <exception>
#include <cstdlib>

constexpr int TOTAL_LINES = 6;
void display_pattern_a()
{
    std::cout << "Pattern A\n";
    for (int i = 1; i <= TOTAL_LINES; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }
}
void display_pattern_b()
{
    std::cout << "Pattern B\n";
    for (int i = TOTAL_LINES; i >= 1; --i)
    {
        for (int j = 1; j <= i; ++j)
        {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }
}

void display_pattern_c()
{
    std::cout << "Pattern C\n";
    for (int i = 1; i <= TOTAL_LINES; ++i)
    {
        for (int s = 0; s < TOTAL_LINES - i; ++s)
        {
            std::cout << "  ";
        }
        for (int j = i; j >= 1; --j)
        {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }
}

void display_pattern_d()
{
    std::cout << "Pattern D\n";
    for (int i = 0; i < TOTAL_LINES; ++i)
    {
        for (int s = 0; s < i; ++s)
        {
            std::cout << "  ";
        }
        for (int j = 1; j <= TOTAL_LINES - i; ++j)
        {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }
}

/**
 * *5.18 (Display four patterns using loops) Use nested loops that display the following
 * patterns in four separate programs: Pattern A, Pattern B, Pattern C, Pattern D.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        display_pattern_a();
        std::cout << '\n';

        display_pattern_b();
        std::cout << '\n';

        display_pattern_c();
        std::cout << '\n';

        display_pattern_d();

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