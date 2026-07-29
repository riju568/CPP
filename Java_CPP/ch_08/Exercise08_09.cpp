#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>

const std::string USER_X_ID = "X";
const std::string USER_O_ID = "O";
const std::string IN_PROMPT_ROW = "Enter a row (0, 1, or 2) for player ";
const std::string IN_PROMPT_COLUMN = "Enter a column (0, 1, or 2) for player ";
const std::string VERTICAL_LINE = "----------------------------------------\n";

std::vector<std::vector<std::string>> boxes(3, std::vector<std::string>(3, ""));
std::string nextMove = USER_X_ID;
std::string status = "continue";
std::string winner = "";
int totalMoves = 9;

/** Initializes or resets the Tic-Tac-Toe game board */
void initializeGame()
{
    boxes = std::vector<std::vector<std::string>>(3, std::vector<std::string>(3, ""));
    nextMove = USER_X_ID;
    status = "continue";
    winner = "";
    totalMoves = 9;
}

/** Checks if the specified player token (X or O) has won */
bool checkWinner(const std::string &player)
{
    // Check rows
    for (int i = 0; i < 3; ++i)
    {
        if (boxes[i][0] == player && boxes[i][1] == player && boxes[i][2] == player)
        {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; ++j)
    {
        if (boxes[0][j] == player && boxes[1][j] == player && boxes[2][j] == player)
        {
            return true;
        }
    }
    // Check diagonals
    if (boxes[0][0] == player && boxes[1][1] == player && boxes[2][2] == player)
    {
        return true;
    }
    if (boxes[0][2] == player && boxes[1][1] == player && boxes[2][0] == player)
    {
        return true;
    }

    return false;
}

/** Prints the current state of the game board */
void printGameBoard()
{
    for (int i = 0; i < 3; ++i)
    {
        std::cout << VERTICAL_LINE;
        for (int j = 0; j < 3; ++j)
        {
            if (boxes[i][j].empty())
            {
                std::cout << "|   ";
            }
            else
            {
                std::cout << "| " << boxes[i][j] << " ";
            }
        }
        std::cout << "|\n";
    }
    std::cout << VERTICAL_LINE;
}
void addMove(int markRow, int markCol)
{
    if (boxes[markRow][markCol].empty())
    {
        boxes[markRow][markCol] = nextMove;
        totalMoves--;
        if (checkWinner(nextMove))
        {
            status = "win";
            winner = nextMove;
        }
        else if (totalMoves == 0)
        {
            status = "draw";
        }
        else
        {
            nextMove = (nextMove == USER_X_ID) ? USER_O_ID : USER_X_ID;
        }
    }
    else
    {
        std::cout << "Nice try, you can only enter your mark in an empty box...\n";
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        initializeGame();
        std::cout << "Welcome to Tic Tac Toe!\n";

        bool firstPrint = true;

        while (status == "continue")
        {
            if (firstPrint)
            {
                printGameBoard();
                firstPrint = false;
            }

            int row = -1;
            int col = -1;

            // Input row safely
            std::cout << IN_PROMPT_ROW << nextMove << ": ";
            if (std::cin >> row)
            {
                // valid input
            }
            else
            {
                std::cout << "Invalid input. Please enter an integer (0, 1, or 2).\n";
                std::cin.clear();
                std::string dummy;
                std::cin >> dummy;
                continue;
            }

            // Input column safely
            std::cout << IN_PROMPT_COLUMN << nextMove << ": ";
            if (std::cin >> col)
            {
                // valid input
            }
            else
            {
                std::cout << "Invalid input. Please enter an integer (0, 1, or 2).\n";
                std::cin.clear();
                std::string dummy;
                std::cin >> dummy;
                continue;
            }

            // Validate boundaries
            if ((row >= 0 && row <= 2) && (col >= 0 && col <= 2))
            {
                addMove(row, col);
            }
            else
            {
                std::cout << "Out of bounds! Player " << nextMove << ", enter 0, 1, or 2.\n";
                continue;
            }

            // Redisplay board after a valid attempt
            printGameBoard();
        }

        // Game over results
        if (status == "win")
        {
            std::cout << "\nPlayer " << winner << " won!\n";
        }
        else if (status == "draw")
        {
            std::cout << "\nThe match is a draw!!\n";
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}