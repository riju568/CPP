#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * *4.25 (Generate vehicle plate numbers) Assume a vehicle plate number consists of three
 * uppercase letters followed by four digits. Write a program to generate a plate
 * number.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> letter_dist('A', 'Z');
        std::uniform_int_distribution<int> digit_dist(0, 9);

        std::string plate_number;
        plate_number.reserve(7);

        // Generate 3 uppercase letters
        for (int i = 0; i < 3; ++i)
        {
            plate_number += static_cast<char>(letter_dist(gen));
        }

        // Generate 4 digits
        for (int j = 0; j < 4; ++j)
        {
            plate_number += std::to_string(digit_dist(gen));
        }

        std::cout << plate_number << '\n';

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