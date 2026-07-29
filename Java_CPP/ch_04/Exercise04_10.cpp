#include <iostream>
#include <string_view>
#include <array>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *4.10 (Guess birthday) Rewrite Listing 4.3, GuessBirthday.java, to prompt the user to
 * enter the character Y for Yes and N for No rather than entering 1 for Yes and 0 for No.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        constexpr std::array<std::string_view, 5> sets = {
            " 1  3  5  7\n 9 11 13 15\n17 19 21 23\n25 27 29 31",
            " 2  3  6  7\n10 11 14 15\n18 19 22 23\n26 27 30 31",
            " 4  5  6  7\n12 13 14 15\n20 21 22 23\n28 29 30 31",
            " 8  9 10 11\n12 13 14 15\n24 25 26 27\n28 29 30 31",
            "16 17 18 19\n20 21 22 23\n24 25 26 27\n28 29 30 31"};

        constexpr std::array<int, 5> set_values = {1, 2, 4, 8, 16};

        int day = 0;

        for (std::size_t i = 0; i < sets.size(); ++i)
        {
            std::cout << "Is your birthday in Set" << (i + 1) << "?\n";
            std::cout << sets[i];
            std::cout << "\nEnter N for No and Y for Yes: ";
            char answer = '\0';
            if (!(std::cin >> answer))
            {
                std::cout << "Please enter a valid character input.\n";
                return EXIT_SUCCESS;
            }

            if (answer == 'Y' || answer == 'y')
            {
                day += set_values[i];
            }
            std::cout << '\n';
        }

        std::cout << "Your birthday is " << day << "!\n";

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}