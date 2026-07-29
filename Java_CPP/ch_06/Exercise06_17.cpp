#include <iostream>
#include <random>
#include <exception>
#include <cstdlib>

/**
 * *6.17 (Display matrix of 0s and 1s) Write a method that displays an n-by-n matrix using
 * the following header:
 * void print_matrix(int n)
 * Each element is 0 or 1, which is generated randomly.
 *
 * Write a test program that prompts the user to enter n and displays an n-by-n matrix.
 */
void print_matrix(int n)
{
    if (n >= 1000)
    {
        std::cout << n << " is too large and may overload your computer....\n";
        return;
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << dist(gen) << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter n: \n";
        int n = 0;
        if (!(std::cin >> n))
        {
            std::cerr << "Error: Invalid input. Please enter an integer.\n";
            return EXIT_SUCCESS;
        }

        print_matrix(n);

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