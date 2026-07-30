#include <iostream>
#include <memory>
#include <exception>
#include <cstdlib>

/**
 * Custom stack class equivalent to Java's StackOfIntegers
 */
class StackOfIntegers
{
private:
    std::unique_ptr<int[]> elements;
    int size;
    int capacity;

public:
    explicit StackOfIntegers(int capacity = 16) 
        : size(0), capacity(capacity), elements(std::make_unique<int[]>(capacity)) {}
    void push(int value)
    {
        if (size >= capacity)
        {
            capacity *= 2;
            auto temp = std::make_unique<int[]>(capacity);
            for (int i = 0; i < size; ++i) temp[i] = elements[i];
            elements = std::move(temp);
        }
        elements[size++] = value;
    }
    int pop() { return elements[--size]; }
    [[nodiscard]] int get_size() const noexcept { return size; }
    [[nodiscard]] bool empty() const noexcept { return size == 0; }
};
static bool check_prime(int num)
{
    for (int f = 2; f * f <= num; ++f)
        if (num % f == 0) return false;
    return num > 1;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        StackOfIntegers stack;
        constexpr int limit = 120;
        for (int i = 2; i < limit; ++i)
            if (check_prime(i)) stack.push(i);
        std::cout << "All prime numbers less than " << limit << ", in reverse order:\n";
        while (stack.get_size() > 0)
            std::cout << stack.pop() << (stack.get_size() > 0 ? ", " : "\n");
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}