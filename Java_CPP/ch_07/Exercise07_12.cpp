#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * 7.12 (Reverse an array) The reverse method reverses an array by
 * modifying it in place. Rewrite the method that reverses the array passed in
 * the argument and returns a reference to this array.
 * Write a test program that prompts the user to
 * enter ten numbers, invokes the method to reverse the numbers, and displays the
 * numbers.
 */

std::vector<int>& reverse(std::vector<int> &a)
{
    if (a.empty())
    {
        return a;
    }
    size_t j = a.size() - 1;
    for (size_t i = 0; i < a.size() / 2; ++i)
    {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        --j;
    }
    return a;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        std::vector<int> t1(10);

        std::cout << "Original array is: [";
        for (size_t i = 0; i < test.size(); ++i)
        {
            std::cout << test[i] << (i + 1 < test.size() ? ", " : "");
        }
        std::cout << "]\n";

        reverse(test);

        std::cout << "Original array reversed: [";
        for (size_t i = 0; i < test.size(); ++i)
        {
            std::cout << test[i] << (i + 1 < test.size() ? ", " : "");
        }
        std::cout << "]\n\n";

        std::cout << "Enter 10 numbers:\n";
        for (size_t i = 0; i < 10; ++i)
        {
            if (!(std::cin >> t1[i]))
            {
                std::cerr << "Error: Invalid integer input for element " << i + 1 << ".\n";
                return EXIT_FAILURE;
            }
        }

        reverse(t1);

        std::cout << "Your array reversed is: [";
        for (size_t i = 0; i < t1.size(); ++i)
        {
            std::cout << t1[i] << (i + 1 < t1.size() ? ", " : "");
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