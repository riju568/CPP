#include <iostream>
#include <stack>
#include <exception>

struct HanoiMove {
    bool is_last_in_from_tower;
    int n;
    char from_tower;
    char to_tower;
    char aux_tower;

    HanoiMove(bool last, int count, char from, char to, char aux)
        : is_last_in_from_tower(last), n(count), from_tower(from), to_tower(to), aux_tower(aux) {}
};

void move_disks(int n, char from_tower, char to_tower, char aux_tower) {
    if (n <= 0) return;

    std::stack<HanoiMove> move_stack;
    move_stack.push(HanoiMove(false, n, from_tower, to_tower, aux_tower));

    while (!move_stack.empty()) {
        HanoiMove move = move_stack.top();
        move_stack.pop();

        if (move.is_last_in_from_tower || move.n == 1) {
            std::cout << "Move disk " << move.n << " from " << move.from_tower << " to " << move.to_tower << '\n';
        } else {
            move_stack.push(HanoiMove(false, move.n - 1, move.aux_tower, move.to_tower, move.from_tower));
            move_stack.push(HanoiMove(true, move.n, move.from_tower, move.to_tower, move.aux_tower));
            move_stack.push(HanoiMove(false, move.n - 1, move.from_tower, move.aux_tower, move.to_tower));
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter number of disks: ";
        int n = 0;
        if (!(std::cin >> n) || n <= 0) {
            std::cerr << "Error: Invalid number of disks entered.\n";
            return 3;
        }

        std::cout << "The moves are:\n";
        move_disks(n, 'A', 'B', 'C');
    }
    catch (const std::exception& e) {
        std::cerr << "Standard Exception: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}