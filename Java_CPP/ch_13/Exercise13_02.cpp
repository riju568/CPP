#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <exception>

void shuffle(std::vector<double>& list) {
    static std::mt19937 rng(std::random_device{}());
    for (size_t i = 0; i < list.size(); ++i) {
        std::uniform_int_distribution<size_t> dist(0, list.size() - 1);
        size_t randIdx = dist(rng);
        
        std::swap(list[i], list[randIdx]);
    }
}

void testShuffled(const std::vector<double>& list) {
    std::cout << "Testing shuffled list contains same contents as original list....\n";
    std::vector<double> copyOfShuffledList = list;
    
    std::sort(copyOfShuffledList.begin(), copyOfShuffledList.end());

    bool equalSortedArray = true;
    size_t i = 0;
    for (; i < 100 && i < copyOfShuffledList.size(); ++i) {
        if (static_cast<double>(i) != copyOfShuffledList[i]) {
            equalSortedArray = false;
            break;
        }
    }

    if (!equalSortedArray) {
        std::cout << "Shuffled array does not have same contents as original, @see array index: " << i << "\n";
    } else {
        std::cout << "Shuffled array has same contents as original array: " << (equalSortedArray ? "true" : "false") << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::vector<double> testList;
        testList.reserve(100);

        for (int i = 0; i < 100; ++i) {
            testList.push_back(i);
        }

        std::cout << "Original list of random int Numbers:\n[";
        for (size_t i = 0; i < testList.size(); ++i) {
            std::cout << testList[i] << (i + 1 < testList.size() ? ", " : "");
        }
        std::cout << "]\n";

        std::cout << "Shuffling the list....\n";
        shuffle(testList);

        std::cout << "Shuffle completed:\n[";
        for (size_t i = 0; i < testList.size(); ++i) {
            std::cout << testList[i] << (i + 1 < testList.size() ? ", " : "");
        }
        std::cout << "]\n";

        testShuffled(testList);
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