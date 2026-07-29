#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

/**
 * *9.3 (Use the Date class) Write a program that creates a Date object, sets its elapsed
 * time to 10000, 100000, 1000000, 10000000, 100000000, 1000000000,
 * 10000000000, and 100000000000, and displays the date and time using the
 * toString() method, respectively.
 */


int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        const long long startElapsedTime = 10000LL;
        const long long endElapsedTime = 100000000000LL;
        for (long long elapsedTime = startElapsedTime; elapsedTime <= endElapsedTime; elapsedTime *= 10) {
                        std::time_t timeInSeconds = static_cast<std::time_t>(elapsedTime / 1000);
            std::tm* timeInfo = std::localtime(&timeInSeconds);
            if (timeInfo != nullptr) {
                char buffer[80];
                std::strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Z %Y", timeInfo);
                std::cout << buffer << '\n';
            }
        }
        return EXIT_SUCCESS;
    } 
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}