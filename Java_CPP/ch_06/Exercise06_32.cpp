#include <iostream>
#include <random>
#include <string>
#include <exception>
#include <cstdlib>

/**
 * **6.32 (Game: chance of winning at craps) Revise Exercise 6.30 to run it 10,000
 * times and display the number of winning games.
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

int start_games(int iterations)
{
    int wins = 0;
    for (int i = 0; i < iterations; ++i)
    {
        int point = 0;
        int rolled = roll_die() + roll_die();
        std::string res = check_result(rolled);

        if (res == "point")
        {
            point = rolled;
            int rolling = 0;
            while (rolling != 7)
            {
                rolling = roll_die() + roll_die();

                if (rolling == point)
                {
                    wins++;
                    break;
                }
                else if (rolling == 7)
                {
                    break;
                }
            }
        }
        else if (res == "natural")
        {
            wins++;
        }
    }
    return wins;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        int wins = start_games(10000);
        std::cout << "Played 10,000 games of craps and won " << wins << " times.\n";

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