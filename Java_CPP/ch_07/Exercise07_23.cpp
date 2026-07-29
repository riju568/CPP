#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <cstdlib>

/**
 * 7.23 (Game: locker puzzle) Finds and displays which lockers are open 
 * after 100 students pass through the school, separated by a single space.
 */

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        int num_lockers = 100;
        std::vector<bool> lockers(num_lockers, false);
        for (int student = 1; student <= num_lockers; ++student)
        {
            for (int action = student - 1; action < num_lockers; action += student)
            {
                lockers[action] = !lockers[action];
            }
        }

        std::cout << "Open locker numbers:\n";
        std::string open_lockers = "";
        for (int i = 0; i < num_lockers; ++i)
        {
            if (lockers[i])
            {
                if (!open_lockers.empty())
                {
                    open_lockers += " ";
                }
                open_lockers += std::to_string(i + 1); // Index 0 represents Locker 1
            }
        }
        
        std::cout << open_lockers << '\n';

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