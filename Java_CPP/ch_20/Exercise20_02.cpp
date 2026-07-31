#include <iostream>
#include <list>
#include <algorithm>
#include <random>
#include <vector>
#include <limits>
#include <exception>

class NumberListManager {
private:
    std::list<int> numbers;

    bool contains(int val) const {
        return std::find(numbers.begin(), numbers.end(), val) != numbers.end();
    }

public:
    bool add(int val) {
        if (contains(val)) {
            return false; 
        }
        numbers.push_back(val);
        return true;
    }

    void sort_list() {
        numbers.sort();
    }

    void reverse_list() {
        numbers.reverse();
    }

    void shuffle_list() {
        std::vector<int> temp(numbers.begin(), numbers.end());
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(temp.begin(), temp.end(), g);
        numbers.assign(temp.begin(), temp.end());
    }

    void display() const {
        std::cout << "Linked List: [ ";
        for (int n : numbers) {
            std::cout << n << " ";
        }
        std::cout << "]\n";
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        NumberListManager manager;
        std::cout << "Number List Manager (Linked List based)\n";
        std::cout << "Commands:\n";
        std::cout << "  a <num> : Add unique number\n";
        std::cout << "  s       : Sort list\n";
        std::cout << "  f       : Shuffle list\n";
        std::cout << "  r       : Reverse list\n";
        std::cout << "  d       : Display list\n";
        std::cout << "  q       : Quit\n\n";

        char cmd;
        while (std::cout << "Enter command: " && std::cin >> cmd) {
            if (cmd == 'a' || cmd == 'A') {
                int val;
                if (std::cin >> val) {
                    if (!manager.add(val)) {
                        std::cout << "Number " << val << " is already in the list (duplicates ignored).\n";
                    } else {
                        manager.display();
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid integer input.\n";
                }
            } else if (cmd == 's' || cmd == 'S') {
                manager.sort_list();
                manager.display();
            } else if (cmd == 'f' || cmd == 'F') {
                manager.shuffle_list();
                manager.display();
            } else if (cmd == 'r' || cmd == 'R') {
                manager.reverse_list();
                manager.display();
            } else if (cmd == 'd' || cmd == 'D') {
                manager.display();
            } else if (cmd == 'q' || cmd == 'Q') {
                break;
            } else {
                std::cout << "Unknown command.\n";
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}