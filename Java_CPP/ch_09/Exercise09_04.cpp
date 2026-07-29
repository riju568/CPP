#include <iostream>
#include <random>
#include <cstdlib>
#include <exception>

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        const int seed = 1000;
        const int n = 100;
        std::mt19937 generator(seed);
        std::uniform_int_distribution<int> distribution(0, n - 1);
        for (int i = 0; i < 50; ++i) {
            if (i % 10 == 0) {
                std::cout << '\n';
            }
            std::cout << distribution(generator) << ' ';
        }
        std::cout << '\n';
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