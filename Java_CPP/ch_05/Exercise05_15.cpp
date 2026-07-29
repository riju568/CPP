#include <iostream>
#include <exception>
/**
 * 5.15 (Display the ASCII character table) Prints characters from '!' to '~' 
 * ten per line, separated by a single space, with zero heap allocations 
 * and proper exception handling.
 */


main() {

    std::ios_base::sync_with_stdio(true);
    constexpr char START_CHAR = '!';
    constexpr char END_CHAR = '~';
    constexpr int CHARS_PER_LINE = 10;

    try {
        int count = 0;
        for (int i = START_CHAR; i <= END_CHAR; ++i) {
            ++count;
            std::cout << static_cast<char>(i);

            if (count % CHARS_PER_LINE == 0) {
                std::cout << '\n';
            } else {
                std::cout << ' ';
            }
        }

        if (count % CHARS_PER_LINE != 0) {
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