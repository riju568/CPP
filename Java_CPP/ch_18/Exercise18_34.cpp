#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <exception>

class EightQueens
{
private:
    static constexpr int SIZE = 8;
    std::array<int, SIZE> queens{};

    bool isValid(int row, int col) const
    {
        for (int i = 0; i < row; ++i)
        {
            if (queens[i] == col || std::abs(queens[i] - col) == std::abs(i - row))
            {
                return false;
            }
        }
        return true;
    }

    bool search(int row)
    {
        if (row == SIZE)
        {
            return true;
        }

        for (int col = 0; col < SIZE; ++col)
        {
            queens[row] = col;
            if (isValid(row, col) && search(row + 1))
            {
                return true;
            }
        }

        return false;
    }

public:
    bool solve()
    {
        queens.fill(-1);
        return search(0);
    }

    void displayBoard() const
    {
        for (int r = 0; r < SIZE; ++r)
        {
            for (int c = 0; c < SIZE; ++c)
            {
                if (queens[r] == c)
                {
                    std::cout << " Q ";
                }
                else
                {
                    std::cout << " . ";
                }
            }
            std::cout << '\n';
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        EightQueens solver;
        if (solver.solve())
        {
            std::cout << "Eight Queens Solution:\n";
            solver.displayBoard();
        }
        else
        {
            std::cout << "No solution exists.\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}