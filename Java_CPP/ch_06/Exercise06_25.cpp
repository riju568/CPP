#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

/**
 * **6.25 (Convert milliseconds to hours, minutes, and seconds) Write a method that converts milliseconds to hours, minutes, and seconds using the following header:
 * std::string convert_millis(long long millis)
 * The method returns a string as hours:minutes:seconds. For example,
 * convert_millis(5500) returns a string 0:0:5, convert_millis(100000) returns
 * a string 0:1:40, and convert_millis(555550000) returns a string 154:19:10.
 */

std::string convert_millis(long long millis)
{
    long long total_seconds = millis / 1000;
    long long total_minutes = total_seconds / 60;
    long long hours = total_minutes / 60;

    long long current_minutes = total_minutes % 60;
    long long current_seconds = total_seconds % 60;

    return std::to_string(hours) + ":" + std::to_string(current_minutes) + ":" + std::to_string(current_seconds);
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << convert_millis(5500) << '\n';
        std::cout << convert_millis(100000) << '\n';
        std::cout << convert_millis(555550000) << '\n';

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