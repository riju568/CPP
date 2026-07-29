#include <iostream>
#include <exception>

/**
 * 5.10 (Find numbers divisible by 5 and 6) Write a program that displays
 * all the numbers from 100 to 1,000, ten per line, that are divisible by
 * 5 and 6. Numbers are separated by exactly one space.
 * 5.10 (Find numbers divisible by 5 and 6) Displays all numbers 
 * from 100 to 1,000, ten per line, that are divisible by both 5 and 6.
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    constexpr int START_NUM = 100;
    constexpr int END_NUM = 1000;
    constexpr int NUMS_PER_LINE = 10;
    try {
        int count = 0;
        for (int i = START_NUM; i <= END_NUM; ++i) {
            if (i % 5 == 0 && i % 6 == 0) {
                std::cout << i << ' ';
                ++count;

                if (count == NUMS_PER_LINE) {
                    std::cout << '\n';
                    count = 0;
                }
            }
        }
        if (count > 0) {
            std::cout << '\n';
        }

    } catch (const std::exception& e) {
        std::cerr << "An error occurred during program execution: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return 1;
    }

    return 0;
}