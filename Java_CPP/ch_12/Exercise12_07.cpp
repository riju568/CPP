#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
#include <format>
#include <exception>
#include <cstdlib>


int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 10000);
        constexpr std::size_t ARRAY_SIZE = 100;
        std::vector<int> randomArray(ARRAY_SIZE);
        for (std::size_t i = 0; i < ARRAY_SIZE; ++i) {
            randomArray[i] = dist(gen);
        }
        std::cout << "Enter an index in the array for which to display its value: ";
        int indexValue{0};
        if (!(std::cin >> indexValue)) {
            std::cout << "Invalid input type.\n";
            return EXIT_SUCCESS;
        }
        try {
            std::cout << std::format("{}\n", randomArray.at(indexValue));
        }
        catch (const std::out_of_range&) {
            std::cout << "Out Of Bounds\n";
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception& e) {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}