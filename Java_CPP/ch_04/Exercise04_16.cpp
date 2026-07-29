#include <iostream>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <random>

/**
 * 4.16 (Random character) Write a program that displays a random uppercase letter
 * using the Math.random() method.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        // Modern C++ uniform random distribution between 'A' and 'Z'
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist('A', 'Z');

        char random_char = static_cast<char>(dist(gen));

        std::cout << "The random uppercase letter is: " << random_char << '\n';

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