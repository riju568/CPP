#include <iostream>
#include <random>
#include <string>
#include <exception>
#include <cstdlib>


/**
 * **6.30 (Game: craps) Craps is a popular dice game played in casinos. Write a program
 * to play a variation of the game, as follows:
 * Roll two dice. Each die has six faces representing values 1, 2, …, and 6, respectively.
 * Check the sum of the two dice.
 * <p>
 * If the sum is 2, 3, or 12 (called craps), you
 * lose; if the sum is 7 or 11 (called natural), you win; if the sum is another value
 * (i.e., 4, 5, 6, 8, 9, or 10), a point is established. Continue to roll the dice until either
 * a 7 or the same point value is rolled. If 7 is rolled, you lose. Otherwise, you win.
 * Your program acts as a single player. Here are some sample runs.
 * You rolled 5 + 6 = 11
 * You win
 * You rolled 1 + 2 = 3
 * You lose
 * You rolled 4 + 4 = 8
 * point is 8
 * You rolled 6 + 2 = 8
 * You win
 * You rolled 3 + 2 = 5
 * point is 5
 * You rolled 2 + 5 = 7
 * You lose
 
 */

int roll_die()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 6);
    return dist(gen);
}

std::string check_result(int roll)
{
    if (roll == 2 || roll == 3 || roll == 12)
    {
        return "craps";
    }
    else if (roll == 7 || roll == 11)
    {
        return "natural";
    }
    return "point";
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        int point = 0;
        std::cout << "Rolling dice.......\n";
        int rolled = roll_die() + roll_die();
        std::string res = check_result(rolled);

        if (res == "craps")
        {
            std::cout << "Craps!! Rolled a " << rolled << ". Better luck next time...\n";
        }
        else if (res == "point")
        {
            point = rolled;
            std::cout << "Rolled " << rolled << ", point is established. Rolling again...\n";
            int rolling = 0;

            while (rolling != 7)
            {
                rolling = roll_die() + roll_die();
                std::cout << "You rolled a " << rolling << '\n';
                if (rolling == point)
                {
                    std::cout << "You Win!\n";
                    break;
                }
                else if (rolling == 7)
                {
                    std::cout << "You lose!\n";
                    break;
                }
            }
        }
        else if (res == "natural")
        {
            std::cout << "Natural! You rolled a " << rolled << " you win!\n";
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