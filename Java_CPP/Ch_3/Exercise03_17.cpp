#include <iostream>
#include <random>
#include <string>
#include <stdexcept>

/**
 * *3.17 (Game: scissor, rock, paper) Write a program that plays the popular
 * scissor-rock-paper game. (A scissor can cut a paper, a rock can knock a
 * scissor, and a paper can wrap a rock.)
 * <p>
 * The program randomly generates a number 0, 1, or 2 representing scissor,
 * rock, and paper. The program prompts the user to enter a number 0, 1, or 2
 * and displays a message indicating whether the user or the computer wins,
 * loses, or draws.
 * <p>
 * Here are sample runs: scissor (0), rock (1), paper (2): 1 The computer is
 * scissor. You are rock. You won
 *
 */
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try
    {
        const int scissor = 0;
        const int rock = 1;
        const int paper = 2;
        std::cout << "Scissor (0), rock (1), paper (2): ";
        int user = 0;
        if (!(std::cin >> user))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer.");
        }

        if (user == 0 || user == 1 || user == 2)
        {
            // Modern C++ secure random number generation for range [0, 2]
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, 2);

            int comp = dis(gen);
            std::string res = "The computer is";

            switch (user)
            {
            case 0:
                if (comp == scissor)
                {
                    res += " scissor and you are scissor, it's a draw.";
                }
                else if (comp == rock)
                {
                    res += " rock and you are scissor, you lost.";
                }
                else if (comp == paper)
                {
                    res += " paper and you are scissor, you won.";
                }
                break;
            case 1:
                if (comp == scissor)
                {
                    res += " scissor and you are rock, you won.";
                }
                else if (comp == rock)
                {
                    res += " rock and you are rock, its a draw.";
                }
                else if (comp == paper)
                {
                    res += " paper and you are rock, you lost.";
                }
                break;
            case 2:
                if (comp == scissor)
                {
                    res += " scissor and you are paper, you lost.";
                }
                else if (comp == rock)
                {
                    res += " rock and you are paper, you won.";
                }
                else if (comp == paper)
                {
                    res += " paper and you are paper, it's a draw.";
                }
                break;
            }
            std::cout << res << "\n";
        }
        else
        {
            std::cout << "Computer wins, you input an invalid value so you forfeit this round!\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}