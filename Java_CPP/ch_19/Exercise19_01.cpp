#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <stdexcept>
#include <exception>

template <typename T>
class GenericStack {
private:
    size_t capacity;
    size_t size;
    std::unique_ptr<T[]> elements;

    void ensureCapacity() {
        if (size >= capacity) {
            size_t new_capacity = capacity * 2;
            auto new_elements = std::make_unique<T[]>(new_capacity);
            for (size_t i = 0; i < size; ++i) {
                new_elements[i] = std::move(elements[i]);
            }
            elements = std::move(new_elements);
            capacity = new_capacity;
        }
    }

public:
    explicit GenericStack(size_t initial_capacity = 16)
        : capacity(initial_capacity), size(0), elements(std::make_unique<T[]>(initial_capacity)) {}
    GenericStack(const GenericStack& other)
        : capacity(other.capacity), size(other.size), elements(std::make_unique<T[]>(other.capacity)) {
        for (size_t i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }

    // Copy Assignment Operator
    GenericStack& operator=(const GenericStack& other) {
        if (this != &other) {
            auto new_elements = std::make_unique<T[]>(other.capacity);
            for (size_t i = 0; i < other.size; ++i) {
                new_elements[i] = other.elements[i];
            }
            elements = std::move(new_elements);
            capacity = other.capacity;
            size = other.size;
        }
        return *this;
    }
    GenericStack(GenericStack&&) noexcept = default;
    GenericStack& operator=(GenericStack&&) noexcept = default;
    ~GenericStack() = default;

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Error: Cannot peek into an empty stack.");
        }
        return elements[size - 1];
    }

    void push(const T& value) {
        ensureCapacity();
        elements[size++] = value;
    }

    void push(T&& value) {
        ensureCapacity();
        elements[size++] = std::move(value);
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Error: Cannot pop from an empty stack.");
        }
        return elements[--size];
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        GenericStack<std::string> stack1;

        stack1.push("Atlanta");
        stack1.push("Memphis");
        stack1.push("New York");
        stack1.push("Columbus");
        stack1.push("Chicago");
        stack1.push("St. Louis");
        stack1.push("New Orleans");
        stack1.push("Boston");
        stack1.push("Atlanta");
        stack1.push("Memphis");
        stack1.push("New York");
        stack1.push("Chicago");
        stack1.push("St. Louis");
        stack1.push("New Orleans");
        stack1.push("Boston");
        stack1.push("Atlanta");
        stack1.push("Memphis");
        stack1.push("New York");
        stack1.push("Columbus");
        stack1.push("Chicago");
        stack1.push("St. Louis");
        stack1.push("New Orleans");
        stack1.push("Boston");

        while (stack1.getSize() > 0) {
            std::cout << "Pop: " << stack1.pop() << '\n';
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