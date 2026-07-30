#include <iostream>
#include <vector>
#include <new>
#include <format>
#include <exception>
#include <cstdlib>


int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        try {
            std::size_t size = 50;
            while (true) {
                std::vector<long long> testHeap(size);
                testHeap[0] = 1LL;
                size *= 4;
            }
        }
        catch (const std::bad_alloc& e) {
            std::cout << std::format("Out of memory error: {}\n", e.what());
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