#include <iostream>
#include <random>
#include <exception>
#include <cstdlib>

/**
 * *6.38 (Generate random characters) Use the methods in RandomCharacter in Listing
 * 6.10 to print 100 uppercase letters and then 100 single digits, printing ten per line.
 */

char get_random_character(char ch1, char ch2)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(static_cast<unsigned char>(ch1), static_cast<unsigned char>(ch2));
    return static_cast<char>(dist(gen));
}

char get_random_upper_case_letter()
{
    return get_random_character('A', 'Z');
}

char get_random_digit_character()
{
    return get_random_character('0', '9');
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        for (int i = 0; i < 200; ++i)
        {
            if (i > 0 && i % 10 == 0)
            {
                std::cout << '\n';
            }
            if (i < 100)
            {
                std::cout << get_random_upper_case_letter() << ' ';
            }
            else
            {
                std::cout << get_random_digit_character() << ' ';
            }
        }
        std::cout << '\n';

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