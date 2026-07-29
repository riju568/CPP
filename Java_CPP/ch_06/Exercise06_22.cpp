#include <iostream>
#include <cmath>
#include <exception>
#include <cstdlib>
/**
 * **6.22 (Math: approximate the square root) There are several techniques for implementing the sqrt method in the Math class.
 * One such technique is known as the Babylonian method. It approximates the square root of a number, n, by repeatedly
 * performing a calculation using the following formula:
 * nextGuess = (lastGuess + n / lastGuess) / 2
 * <p>
 * When nextGuess and lastGuess are almost identical, nextGuess is the
 * approximated square root.
 * <p>
 * The initial guess can be any positive value (e.g., 1).
 * This value will be the starting value for lastGuess. If the difference between
 * nextGuess and lastGuess is less than a very small number, such as 0.0001,
 * you can claim that nextGuess is the approximated square root of n.
 * If not, nextGuess becomes lastGuess and the approximation process continues.
 * <p>
 * Implement the following method that returns the square root of n.
 * public static double sqrt(long n)
 */



bool diff(double a, double b)
{
    return std::abs(a - b) < 0.0001; // If the difference between nextGuess and lastGuess is less than 0.0001.
}

double sqrt(long long n)
{
    double last_guess = 2.0; // Initial guess
    double next_guess = (last_guess + static_cast<double>(n) / last_guess) / 2.0;

    while (!diff(next_guess, last_guess))
    {
        last_guess = next_guess;
        next_guess = (last_guess + static_cast<double>(n) / last_guess) / 2.0;
    }
    return next_guess;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        for (int i = 10; i < 100; i += 10)
        {
            std::cout << "The result of the Babylonian sqrt method for: " << i << " = " << sqrt(i) << '\n';
            std::cout << "The result of std::sqrt(i) method for: " << i << " = " << std::sqrt(i) << '\n';
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