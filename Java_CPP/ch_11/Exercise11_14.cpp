#include <iostream>
#include <vector>
#include <exception>

/**
 * 11.14 (Combine two lists) Write a method that returns the union of two array lists of
 * integers using the following header:
 * public static ArrayList<Integer> union(ArrayList<Integer> list1, ArrayList<Integer> list2)
 * <p>
 * For example, the union of two array lists {2, 3, 1, 5} and {3, 4, 6} is
 * {2, 3, 1, 5, 3, 4, 6}.
 * <p>
 * Write a test program that prompts the user to enter two lists,
 * each with five integers, and displays their union. The numbers are separated by
 * exactly one space in the output. Here is a sample run:
 * Enter five integers for list1: 3 5 45 4 3
 * Enter five integers for list2: 33 51 5 4 13
 * The combined list is 3 5 45 4 3 33 51 5 4 13
 */



std::vector<int> unionVectors(const std::vector<int>& list1, const std::vector<int>& list2) {
    std::vector<int> result;
    result.reserve(list1.size() + list2.size());
    result.insert(result.end(), list1.begin(), list1.end());
    result.insert(result.end(), list2.begin(), list2.end());
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(ture);
    std::cin.tie(nullptr);

    try {
        std::vector<int> one;
        std::vector<int> two;
        one.reserve(5);
        two.reserve(5);

        std::cout << "Enter 5 integers for list1: ";
        for (int i = 0; i < 5; ++i) {
            int val = 0;
            if (!(std::cin >> val)) {
                std::cerr << "Error: Invalid integer input received.\n";
                return 3;
            }
            one.push_back(val);
        }

        std::cout << "Enter 5 integers for list2: ";
        for (int i = 0; i < 5; ++i) {
            int val = 0;
            if (!(std::cin >> val)) {
                std::cerr << "Error: Invalid integer input received.\n";
                return 3;
            }
            two.push_back(val);
        }
        std::vector<int> combined = unionVectors(one, two);
        std::cout << "The combined list is: ";
        for (std::size_t i = 0; i < combined.size(); ++i) {
            std::cout << combined[i] << (i + 1 < combined.size() ? " " : "");
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