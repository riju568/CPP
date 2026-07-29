#include <iostream>
#include <random>
#include <stdexcept>
/**
 * 3.14 (Game: heads or tails) Write a program that lets the user guess whether
 * the flip of a coin results in heads or tails. The program randomly generates
 * an integer 0 or 1, which represents head or tail. The program prompts the
 * user to enter a guess and reports whether the guess is correct or incorrect.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);
        int x = dis(gen);
        std::cout << "Enter your guess now! 0 for heads, or 1 for tails: ";
        int a = 0;

        if (!(std::cin >> a))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer.");
        }

        if (a < 0 || a > 1)
        {
            throw std::out_of_range("Error: Guess must be either 0 for heads or 1 for tails.");
        }

        if (a == x)
        {
            std::cout << "You are correct!\n";
        }
        else
        {
            std::cout << "Wrong! Better luck next time!\n";
            std::cout << "The correct answer was: " << x << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}