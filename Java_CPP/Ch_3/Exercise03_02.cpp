#include <iostream>
#include <random>
#include <stdexcept>
#include <limits>
/**
 * 3.2 (Game: add three numbers) The program in Listing 3.1, AdditionQuiz.java, generates
 * two integers and prompts the user to enter the sum of these two integers.
 * Revise the program to generate three single-digit integers and prompt the user to
 * enter the sum of these three integers.
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 9);
        int a = dis(gen);
        int b = dis(gen);
        int c = dis(gen);
        int correct_answer = a + b + c;
        int user_answer = 0;
        std::cout << "What is " << a << " + " << b << " + " << c << "? ";
        if (!(std::cin >> user_answer))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer.");
        }
        if (user_answer == correct_answer)
        {
            std::cout << a << " + " << b << " + " << c << " = " << user_answer << " is correct\n";
        }
        else
        {
            std::cout << a << " + " << b << " + " << c << " = " << user_answer << " is incorrect\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}