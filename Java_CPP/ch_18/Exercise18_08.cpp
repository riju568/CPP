#include <iostream>
#include <cmath>
#include <exception>

void reverseDisplay(int value) {
    if (value < 0) {
        std::cout << '-';
        reverseDisplay(-value);
        return;
    }
    if (value > 0) {
        std::cout << (value % 10);
        reverseDisplay(value / 10);
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::cout << "Enter an integer to reverse: ";
        int num = 0;

        if (!(std::cin >> num)) {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        if (num == 0) {
            std::cout << 0;
        } else {
            reverseDisplay(num);
        }
        std::cout << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}