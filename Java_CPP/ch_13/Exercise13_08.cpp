#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <exception>

class MyStack {
private:
    std::vector<std::string> list;
    std::vector<std::string> makeDeepCopy() const {
        std::vector<std::string> arrlist;
        arrlist.reserve(list.size());
        for (const auto& item : list) {
            arrlist.push_back(item);
        }
        return arrlist;
    }

public:
    MyStack() = default;
    MyStack(const MyStack& other) : list(other.list) {}
    MyStack& operator=(const MyStack& other) {
        if (this != &other) {
            list = other.list;
        }
        return *this;
    }

    size_t getSize() const {
        return list.size();
    }

    bool isEmpty() const {
        return list.empty();
    }

    std::string peek() const {
        if (list.empty()) {
            throw std::out_of_range("Cannot peek at an empty stack.");
        }
        return list.back();
    }

    std::string pop() {
        if (list.empty()) {
            throw std::out_of_range("Cannot pop from an empty stack.");
        }
        std::string obj = list.back();
        list.pop_back();
        return obj;
    }

    void push(const std::string& obj) {
        list.push_back(obj);
    }

    int search(const std::string& obj) const {
        for (size_t i = 0; i < list.size(); ++i) {
            if (list[i] == obj) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
    MyStack clone() const {
        MyStack myStack_Clone;
        myStack_Clone.list = makeDeepCopy();
        return myStack_Clone;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << "Stack: [";
        for (size_t i = 0; i < list.size(); ++i) {
            oss << list[i] << (i + 1 < list.size() ? ", " : "");
        }
        oss << "]";
        return oss.str();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try
    {
        MyStack start;
        start.push("One");
        start.push("Two");
        start.push("Three");
        MyStack cloned = start.clone();
        std::cout << "Is the cloned stack a shallow copy of the starting stack?\n";
        std::cout << ( (&cloned == &start) ? "true" : "false" ) << "\n\n";
        std::cout << "Cloned " << cloned.toString() << "\n\n";
        std::cout << "Original " << start.toString() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}