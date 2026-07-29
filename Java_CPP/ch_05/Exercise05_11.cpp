#include <iostream>
#include <exception>


/**
 * 5.11 (Find numbers divisible by 5 or 6, but not both) Displays numbers from 100 to 200, 
 * ten per line, that are divisible by 5 or 6, but not both, with zero heap allocations 
 * and exception safety.
 */

int main() {
    std::ios_base::sync_with_stdio(true);
    constexpr int START_NUM = 100;
    constexpr int END_NUM = 200;
    constexpr int NUMS_PER_LINE = 10;
    try {
        int count = 0;
        for (int i = START_NUM; i <= END_NUM; ++i) {
            if ((i % 5 == 0) ^ (i % 6 == 0)) {
                ++count;
                std::cout << i;

                if (count % NUMS_PER_LINE == 0) {
                    std::cout << '\n';
                } else {
                    std::cout << ' ';
                }
            }
        }
        if (count % NUMS_PER_LINE != 0) {
            std::cout << '\n';
        }

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}