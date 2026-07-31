#include <iostream>
#include <queue>
#include <string>
#include <memory>
#include <exception>

template <typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>>
class MyPriorityQueue {
private:
    std::priority_queue<T, Container, Compare> pq;

public:
    MyPriorityQueue() = default;
    MyPriorityQueue(const MyPriorityQueue& other) = default;
    MyPriorityQueue& operator=(const MyPriorityQueue& other) = default;
    MyPriorityQueue(MyPriorityQueue&& other) noexcept = default;
    MyPriorityQueue& operator=(MyPriorityQueue&& other) noexcept = default;

    void offer(const T& value) {
        pq.push(value);
    }

    void pop() {
        pq.pop();
    }

    const T& top() const {
        return pq.top();
    }

    bool empty() const {
        return pq.empty();
    }

    size_t size() const {
        return pq.size();
    }
    std::unique_ptr<MyPriorityQueue<T, Container, Compare>> clone() const {
        return std::make_unique<MyPriorityQueue<T, Container, Compare>>(*this);
    }

    void print_elements() const {
        std::priority_queue<T, Container, Compare> temp = pq;
        std::cout << "[ ";
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << "]\n";
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        MyPriorityQueue<std::string> queue;
        queue.offer("Testing");
        queue.offer("Test");
        queue.offer("TEST");
        std::cout << "Original queue: ";
        queue.print_elements();
        auto cloned_queue = queue.clone();

        std::cout << "Cloned queue: ";
        cloned_queue->print_elements();
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