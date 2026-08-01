#include <iostream>
#include <vector>
#include <unordered_set>
#include <exception>

/**
 * 11.13 (Remove duplicates) Write a method that removes the
 * duplicate elements from an array list of integers using the following header:
 * public static void removeDuplicate(ArrayList<Integer> list)
 * <p>
 * <p>
 * Write a test program that prompts the user to enter 10 integers to a list
 * and displays the distinct integers in their input order and
 * separated by exactly one space.
 */



void removeDuplicate(std::vector<int>& list) {
    std::unordered_set<int> seen;
    std::vector<int> result;
    result.reserve(list.size());

    for (int val : list) {
        if (seen.find(val) == seen.end()) {
            seen.insert(val);
            result.push_back(val);
        }
    }

    list = std::move(result);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter ten integers to put into the list now: ";
        std::vector<int> testList;
        testList.reserve(10);

        for (int i = 0; i < 10; ++i) {
            int val = 0;
            if (!(std::cin >> val)) {
                std::cerr << "Error: Invalid integer input received.\n";
                return 3;
            }
            testList.push_back(val);
        }

        removeDuplicate(testList);

        std::cout << "The distinct integers are: ";
        for (std::size_t i = 0; i < testList.size(); ++i) {
            std::cout << testList[i] << (i + 1 < testList.size() ? " " : "");
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