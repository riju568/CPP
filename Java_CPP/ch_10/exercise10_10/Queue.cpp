#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include <cstdlib>


/**
 * *10.10 (The Queue class) Section 10.6 gives a class for Stack.
 * Design a class named Queue for storing integers.
 * Like a stack, a queue holds elements.
 *
 * In a stack, the elements are retrieved in a last-in first-out fashion.
 * In a queue, the elements are retrieved in a first-in first-out fashion.
 *
 * The class contains:
 * ■ An int[] data field named elements that stores the int values in the queue.
 * ■ A data field named size that stores the number of elements in the queue.
 * ■ A constructor that creates a Queue object with default capacity 8.
 * ■ The method enqueue(int v) that adds v into the queue.
 * ■ The method dequeue() that removes and returns the element from the queue.
 * ■ The method empty() that returns true if the queue is empty.
 * ■ The method get_size() that returns the size of the queue.
 *
 * Implement the class with the initial array size set to 8. The array size
 * will be doubled once the number of elements exceeds the size. After an
 * element is removed from the beginning of the array, shift all elements in
 * the array one position to the left.
 */

constexpr int DEFAULT_CAPACITY = 8;
constexpr int TOTAL_NUMBERS = 20;

class Queue
{
private:
    std::unique_ptr<int[]> elements;
    int size;
    int capacity;
    void ensure_capacity()
    {
        if (size >= capacity)
        {
            int new_capacity = capacity * 2;
            auto new_elements = std::make_unique<int[]>(new_capacity);
            for (int i = 0; i < size; ++i)
            {
                new_elements[i] = elements[i];
            }

            elements = std::move(new_elements); // Frees old memory automatically
            capacity = new_capacity;
        }
    }

public:
    Queue() : Queue(DEFAULT_CAPACITY) {}

    explicit Queue(int initial_capacity)
        : elements(std::make_unique<int[]>(initial_capacity)), size(0), capacity(initial_capacity)
    {
        if (initial_capacity <= 0)
        {
            throw std::invalid_argument("Capacity must be greater than zero.");
        }
    }

    void enqueue(int v)
    {
        ensure_capacity();
        elements[size] = v;
        ++size;
    }

    int dequeue()
    {
        if (empty())
        {
            throw std::underflow_error("Error: Cannot dequeue from an empty queue.");
        }

        int res = elements[0];
        for (int i = 1; i < size; ++i)
        {
            elements[i - 1] = elements[i];
        }
        --size;

        return res;
    }

    bool empty() const
    {
        return size == 0;
    }

    int get_size() const
    {
        return size;
    }

    int get_capacity() const
    {
        return capacity;
    }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        Queue queue;
        for (int i = 1; i <= TOTAL_NUMBERS; ++i)
        {
            queue.enqueue(i);
            std::cout << "TestQueue.enqueue(" << i << ") \n";
        }
        std::cout << '\n';
        while (!queue.empty())
        {
            int value = queue.dequeue();
            std::cout << "TestQueue.dequeue(" << value << ") \n";
        }

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}