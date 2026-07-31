#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <exception>
#include <iterator>

class PriorityQueueSetOps {
public:
    static void execute() {
        std::vector<std::string> list1 = {"George", "Jim", "John", "Blake", "Kevin", "Michael"};
        std::vector<std::string> list2 = {"George", "Katie", "Kevin", "Michelle", "Ryan"};

        std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> pq1(list1.begin(), list1.end());
        std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> pq2(list2.begin(), list2.end());

        std::set<std::string> set1(list1.begin(), list1.end());
        std::set<std::string> set2(list2.begin(), list2.end());

        // Union
        std::set<std::string> union_set;
        std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                       std::inserter(union_set, union_set.begin()));

        std::cout << "Union: [ ";
        for (const auto& item : union_set) std::cout << item << " ";
        std::cout << "]\n";

        // Difference (Set1 - Set2)
        std::set<std::string> diff_set;
        std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                            std::inserter(diff_set, diff_set.begin()));

        std::cout << "Difference (PQ1 - PQ2): [ ";
        for (const auto& item : diff_set) std::cout << item << " ";
        std::cout << "]\n";

        // Intersection
        std::set<std::string> intersect_set;
        std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                             std::inserter(intersect_set, intersect_set.begin()));

        std::cout << "Intersection: [ ";
        for (const auto& item : intersect_set) std::cout << item << " ";
        std::cout << "]\n";
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        PriorityQueueSetOps::execute();
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