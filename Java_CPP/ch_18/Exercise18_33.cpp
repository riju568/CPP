#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <exception>

struct MovePoint
{
    int step = 0;
    int row = 0;
    int col = 0;
};

class AnimatedKnightsTour
{
private:
    static constexpr int SIZE = 8;
    std::array<std::array<bool, SIZE>, SIZE> visited{};
    std::vector<MovePoint> animationSteps;

    int getDegree(int x, int y) const
    {
        int degree = 0;
        constexpr std::array<int, 8> dx = {2, 1, -1, -2, -2, -1, 1, 2};
        constexpr std::array<int, 8> dy = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && !visited[nx][ny])
            {
                degree++;
            }
        }
        return degree;
    }

    bool solve(int x, int y, int step)
    {
        visited[x][y] = true;
        animationSteps.push_back({step, x, y});

        if (step == SIZE * SIZE)
        {
            return true;
        }

        constexpr std::array<int, 8> dx = {2, 1, -1, -2, -2, -1, 1, 2};
        constexpr std::array<int, 8> dy = {1, 2, 2, 1, -1, -2, -2, -1};

        struct Candidate
        {
            int x;
            int y;
            int deg;
        };

        std::vector<Candidate> candidates;

        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && !visited[nx][ny])
            {
                candidates.push_back({nx, ny, getDegree(nx, ny)});
            }
        }

        std::sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
            return a.deg < b.deg;
        });

        for (const auto& next : candidates)
        {
            if (solve(next.x, next.y, step + 1))
            {
                return true;
            }
        }

        visited[x][y] = false;
        animationSteps.pop_back();
        return false;
    }

public:
    bool generatePath(int startX, int startY)
    {
        if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE)
        {
            throw std::out_of_range("Starting coordinates out of bounds.");
        }

        for (auto& row : visited)
        {
            row.fill(false);
        }
        animationSteps.clear();

        return solve(startX, startY, 1);
    }

    const std::vector<MovePoint>& getSteps() const { return animationSteps; }
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

        AnimatedKnightsTour tour;
        if (tour.generatePath(startX, startY))
        {
            std::cout << "Generated path animation sequence:\n";
            for (const auto& step : tour.getSteps())
            {
                std::cout << "Frame " << step.step << ": Move knight to (" 
                          << step.row << ", " << step.col << ")\n";
            }
        }
        else
        {
            std::cout << "No tour path generated.\n";
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