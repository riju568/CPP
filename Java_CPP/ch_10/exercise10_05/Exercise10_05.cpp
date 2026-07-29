#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>


class StackOfIntegers
{
private:
    std::vector<int> elements;

public:
    StackOfIntegers() = default;

    explicit StackOfIntegers(std::size_t capacity)
    {
        elements.reserve(capacity);
    }

    [[nodiscard]] bool empty() const
    {
        return elements.empty();
    }

    [[nodiscard]] int peek() const
    {
        if (elements.empty())
        {
            throw std::underflow_error("Stack underflow: cannot peek an empty stack.");
        }
        return elements.back();
    }

    void push(int value)
    {
        elements.push_back(value);
    }

    int pop()
    {
        if (elements.empty())
        {
            throw std::underflow_error("Stack underflow: cannot pop from an empty stack.");
        }
        int topValue = elements.back();
        elements.pop_back();
        return topValue;
    }

    [[nodiscard]] std::size_t getSize() const
    {
        return elements.size();
    }
};
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter a positive integer to find its smallest factors: ";
        int n{0};
        if (!(std::cin >> n) || n <= 0)
        {
            std::cout << "Invalid input! Please enter a positive integer greater than 0.\n";
            return EXIT_FAILURE;
        }
        StackOfIntegers soi;
        int temp = n;
        for (int f = 2; temp != 1; ++f)
        {
            while (temp % f == 0)
            {
                soi.push(f);
                temp /= f;
            }
        }
        std::cout << "The prime factors for " << n << " in decreasing order: ";
        while (!soi.empty())
        {
            std::cout << soi.pop();
            if (soi.getSize() > 0)
            {
                std::cout << ", ";
            }
        }
        std::cout << "\n";

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}