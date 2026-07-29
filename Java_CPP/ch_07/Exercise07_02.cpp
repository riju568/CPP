#include <iostream>
#include <array>
#include <exception>
#include <cstdlib>

/**
 * 7.2 (Reverse the numbers entered) Write a program that
 * reads ten integers and displays them in the reverse
 * of the order in which they were read.
 */

void display_reverse(const std::array<int, 10> &arr)
{
    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i)
    {
        std::cout << arr[i] << (i == 0 ? "" : " ");
    }
    std::cout << '\n';
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::cout << "Enter ten space-separated integers:\n";
        std::array<int, 10> arr{};

        for (size_t i = 0; i < arr.size(); ++i)
        {
            if (!(std::cin >> arr[i]))
            {
                std::cerr << "Error: Invalid integer input for element " << i + 1 << ".\n";
                return EXIT_FAILURE;
            }
        }

        display_reverse(arr);

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