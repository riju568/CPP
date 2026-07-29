#include <iostream>
#include <stdexcept>
/**
 * 3.8 (Sort three integers) Write a program that prompts the user to enter three integers
 * and display the integers in non-decreasing order.
 */
int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        int x = 0;
        int y = 0;
        int z = 0;
        std::cout << "Please enter three integers:\n";
        if (!(std::cin >> x >> y >> z))
        {
            throw std::runtime_error("Invalid input: Please enter valid integer values.");
        }
        if (x > y)
        {
            int temp1 = x;
            x = y;
            y = temp1;
        }

        if (y > z)
        {
            int temp2 = y;
            y = z;
            z = temp2;
        }

        if (x > y)
        {
            int temp3 = x;
            x = y;
            y = temp3;
        }

        std::cout << x << " " << y << " " << z << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}