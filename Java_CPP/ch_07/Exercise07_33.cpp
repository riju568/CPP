#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <cstdlib>

/**
 * 7.33 (Culture: Chinese Zodiac) Simplifies 
 * Listing 3.9 using an array of strings to store the animal names.
 */

const std::vector<std::string> ANIMAL_NAMES = {
    "monkey", "rooster", "dog", "pig", "rat", "ox",
    "tiger", "rabbit", "dragon", "snake", "horse", "sheep"
};
int floorMod(int a, int b) {
    int result = a % b;
    if (result < 0) {
        result += b;
    }
    return result;
}
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter a year to find its Chinese Zodiac animal: ";
        int year = 0;
        if (!(std::cin >> year))
        {
            std::cerr << "Invalid input! Please enter a valid integer year.\n";
            return EXIT_FAILURE;
        }
        int zodiacIndex = floorMod(year, static_cast<int>(ANIMAL_NAMES.size()));
        std::cout << "The Chinese Zodiac animal for " << year << " is " << ANIMAL_NAMES[zodiacIndex] << '\n';
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}