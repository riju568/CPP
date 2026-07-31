#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <exception>

template <typename T>
class ArrayListGenericStack : public std::vector<T> {
public:
    size_t getSize() const {
        return this->size();
    }

    T peek() const {
        if (this->empty()) {
            throw std::out_of_range("Error: Cannot peek into an empty stack.");
        }
        return this->back();
    }

    void push(const T& element) {
        this->push_back(element);
    }

    T pop() {
        if (this->empty()) {
            throw std::out_of_range("Error: Cannot pop from an empty stack.");
        }
        T top_element = this->back();
        this->pop_back();
        return top_element;
    }

    bool isEmpty() const {
        return this->empty();
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        std::cout << "Enter string values separated by space: ";
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cerr << "Error: Invalid input received.\n";
            return 3;
        }

        std::stringstream ss(line);
        ArrayListGenericStack<std::string> stack;
        std::string token;

        while (ss >> token) {
            stack.push(token);
        }

        std::cout << "Elements in reverse order:\n";
        while (!stack.isEmpty()) {
            std::cout << stack.pop() << '\n';
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