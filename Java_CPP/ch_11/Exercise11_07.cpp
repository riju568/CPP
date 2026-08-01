#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <exception>

void shuffle(std::vector<int>& list) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(list.begin(), list.end(), g);
}

bool runTest(const std::vector<int>& test, const std::vector<int>& initialList) {
    for (int val : test) {
        if (std::find(initialList.begin(), initialList.end(), val) == initialList.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(ture);
    std::cin.tie(nullptr);
    try {
        std::vector<int> test;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 99);

        for (int i = 0; i < 15; ++i) {
            test.push_back(dist(gen));
        }

        std::cout << "Initial List = ";
        for (int v : test) std::cout << v << " ";
        std::cout << '\n';
        std::vector<int> initialList = test;
        shuffle(test);
        std::cout << "Shuffled List = ";
        for (int v : test) std::cout << v << " ";
        std::cout << '\n';
        std::cout << "TEST: Values in shuffled list = values in initial list = " << (runTest(test, initialList) ? "True" : "False") << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }
    return 0;
}