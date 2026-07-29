#include <iostream>
#include <vector>
#include <random>
#include <exception>
#include <cstdlib>

/**
 * 7.21 (Game: bean machine) Simulates the bean machine (Galton box) 
 * where balls drop through pegs choosing left or right paths into slots.
 */


std::vector<char> simulate_random_path(int num_slots)
{
    std::vector<char> result(num_slots - 1);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (size_t i = 0; i < result.size(); ++i)
    {
        int random = dis(gen);
        result[i] = (random == 0) ? 'R' : 'L';
    }
    return result;
}
void simulate_drop(const std::vector<char> &path, std::vector<int> &slots, int ball_number)
{
    int right_count = 0;
    for (char c : path)
    {
        if (c == 'R')
        {
            right_count++;
        }
    }
    
    std::cout << "Ball number " << ball_number << " falls down path: ";
    for (char c : path)
    {
        std::cout << c;
    }
    std::cout << '\n';
    std::cout << "And lands in slot index: " << right_count << '\n';
    slots[right_count]++;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter the number of balls to include in the Galton box experiment: ";
        int balls = 0;
        if (!(std::cin >> balls))
        {
            std::cout << "Invalid input: Expected an integer for the number of balls.\n";
            return EXIT_FAILURE;
        }

        std::cout << "Enter the number of slots: ";
        int num_slots = 0;
        if (!(std::cin >> num_slots))
        {
            std::cout << "Invalid input: Expected an integer for the number of slots.\n";
            return EXIT_FAILURE;
        }

        if (balls <= 0 || num_slots <= 0)
        {
            std::cout << "Error: Number of balls and slots must be greater than zero.\n";
            return EXIT_SUCCESS;
        }

        std::vector<int> slots(num_slots, 0);

        for (int i = 1; i <= balls; ++i)
        {
            // A machine with N slots requires N - 1 nail rows (path length)
            std::vector<char> path = simulate_random_path(num_slots);
            simulate_drop(path, slots, i);
        }

        std::cout << "\nFinal slot accumulation distribution:\n[";
        for (size_t i = 0; i < slots.size(); ++i)
        {
            std::cout << slots[i] << (i + 1 < slots.size() ? ", " : "");
        }
        std::cout << "]\n";

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