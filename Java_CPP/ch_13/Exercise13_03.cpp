#include <iostream>
#include <vector>
#include <random>
#include <exception>

void sort(std::vector<double>& list) {
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (size_t i = 0; i < list.size() - 1; ++i) {
            if (list[i] > list[i + 1]) {
                isSorted = false;
                std::swap(list[i], list[i + 1]);
            }
        }
    }
}

std::vector<double> getRandomTestList() {
    std::vector<double> list;
    list.reserve(100);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 99);
    
    for (int i = 0; i < 100; ++i) {
        list.push_back(dist(rng));
    }
    return list;
}

bool isArraySorted(const std::vector<double>& list) {
    for (size_t i = 1; i < list.size(); ++i) {
        if (list[i] < list[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        std::vector<double> testList;
        std::cout << "Enter five integers and five doubles: ";

        for (int i = 0; i < 5; ++i) {
            double n;
            if (!(std::cin >> n)) {
                std::cerr << "\nError: Invalid integer input received.\n";
                return 3;
            }
            testList.push_back(n);
        }

        for (int i = 0; i < 5; ++i) {
            double n;
            if (!(std::cin >> n)) {
                std::cerr << "\nError: Invalid double input received.\n";
                return 3;
            }
            testList.push_back(n);
        }
        sort(testList);
        for (double n : testList) {
            std::cout << n << " ";
        }
        std::cout << "\n";
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