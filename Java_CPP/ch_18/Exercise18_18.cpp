#include <iostream>
#include <exception>
#include <cstddef>


std::size_t moveDisks(int n, char fromTower, char toTower, char auxTower)
{
    if (n <= 0)
    {
        return 0;
    }

    std::size_t moves = 1;

    if (n == 1)
    {
        std::cout << "Move disk 1 from " << fromTower << " to " << toTower << '\n';
    }
    else
    {
        moves += moveDisks(n - 1, fromTower, auxTower, toTower);
        std::cout << "Move disk " << n << " from " << fromTower << " to " << toTower << '\n';
        moves += moveDisks(n - 1, auxTower, toTower, fromTower);
    }
    return moves;
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        std::cout << "Enter number of disks: ";
        int n = 0;
        if (!(std::cin >> n) || n < 1)
        {
            throw std::invalid_argument("Number of disks must be a positive integer.");
        }

        std::cout << "The moves are:\n";
        std::size_t totalMoves = moveDisks(n, 'A', 'B', 'C');
        std::cout << "Total number of moves is: " << totalMoves << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }
    return 0;
}