#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>

void printSet(const std::string& label, const std::set<std::string>& s) {
    std::cout << label << " [";
    bool first = true;
    for (const auto& item : s) {
        if (!first) std::cout << ", ";
        std::cout << item;
        first = false;
    }
    std::cout << "]\n";
}
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        const std::set<std::string> set1 = {"George", "Jim", "John", "Blake", "Kevin", "Michael"};
        const std::set<std::string> set2 = {"George", "Katie", "Kevin", "Michelle", "Ryan"};
        std::set<std::string> unionSet = set1;
        unionSet.insert(set2.begin(), set2.end());
        printSet("Union is:", unionSet);
        std::set<std::string> intersectionSet;
        std::set_intersection(
            set1.begin(), set1.end(),
            set2.begin(), set2.end(),
            std::inserter(intersectionSet, intersectionSet.begin())
        );
        printSet("Intersection is:", intersectionSet);
        std::set<std::string> differenceSet;
        std::set_difference(
            unionSet.begin(), unionSet.end(),
            intersectionSet.begin(), intersectionSet.end(),
            std::inserter(differenceSet, differenceSet.begin())
        );
        printSet("Difference is:", differenceSet);

    } catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }
    return 0;
}