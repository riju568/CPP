#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <exception>

struct Point
{
    int x = 0;
    int y = 0;
};

class KnightsTour
{
private:
    static constexpr int SIZE = 8;
    std::array<std::array<bool, SIZE>, SIZE> board{};
    std::vector<Point> path;

    int lookAheadCount(int x, int y) const
    {
        int count = 0;
        constexpr std::array<int, 8> dx = {2, 1, -1, -2, -2, -1, 1, 2};
        constexpr std::array<int, 8> dy = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && !board[nx][ny])
            {
                count++;
            }
        }
        return count;
    }

    bool solve(int x, int y, int moveCount)
    {
        board[x][y] = true;
        path.push_back({x, y});

        if (moveCount == SIZE * SIZE)
        {
            return true;
        }

        constexpr std::array<int, 8> dx = {2, 1, -1, -2, -2, -1, 1, 2};
        constexpr std::array<int, 8> dy = {1, 2, 2, 1, -1, -2, -2, -1};

        struct NextMove
        {
            int x;
            int y;
            int degree;
        };

        std::vector<NextMove> nextMoves;

        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && !board[nx][ny])
            {
                nextMoves.push_back({nx, ny, lookAheadCount(nx, ny)});
            }
        }
        std::sort(nextMoves.begin(), nextMoves.end(), [](const NextMove& a, const NextMove& b) {
            return a.degree < b.degree;
        });

        for (const auto& move : nextMoves)
        {
            if (solve(move.x, move.y, moveCount + 1))
            {
                return true;
            }
        }

        board[x][y] = false;
        path.pop_back();
        return false;
    }

public:
    bool runTour(int startX, int startY)
    {
        if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE)
        {
            throw std::out_of_range("Start coordinates out of board bounds.");
        }

        for (auto& row : board)
        {
            row.fill(false);
        }
        path.clear();

        return solve(startX, startY, 1);
    }

    const std::vector<Point>& getPath() const { return path; }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        int startX = 0;
        int startY = 0;

        std::cout << "Enter knight starting row and column (0-7): ";
        if (!(std::cin >> startX >> startY))
        {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        KnightsTour tour;
        if (tour.runTour(startX, startY))
        {
            std::cout << "Knight's Tour solution found:\n";
            const auto& path = tour.getPath();
            for (std::size_t i = 0; i < path.size(); ++i)
            {
                std::cout << "(" << path[i].x << ", " << path[i].y << ")";
                if (i + 1 < path.size()) std::cout << " -> ";
                if ((i + 1) % 4 == 0) std::cout << '\n';
            }
            std::cout << '\n';
        }
        else
        {
            std::cout << "No solution found.\n";
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