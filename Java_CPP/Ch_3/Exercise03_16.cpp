#include <iostream>
#include <random>
/**
 * 3.16 (Random point) Write a program that displays a random coordinate in a
 * rectangle. The rectangle is centered at (0, 0) with width 100 and height 200
 *
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis_x(0, 99);
    std::uniform_int_distribution<> dis_y(0, 199);
    std::uniform_int_distribution<> dis_bool(0, 1);

    int x = dis_x(gen);
    int y = dis_y(gen);

    bool negOrPosX = dis_bool(gen);
    bool negOrPosY = dis_bool(gen);

    if (negOrPosX) {
        x = x * -1;
    }

    if (negOrPosY) {
        y = y * -1;
    }

    std::cout << "(" << x << "," << y << ")\n";

    return 0;
}