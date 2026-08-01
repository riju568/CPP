#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <exception>


int largestInteger(const std::vector<int>& arr, std::size_t idx = 0)
{
    if (arr.empty())
    {
        throw std::invalid_argument("Array cannot be empty.");
    }
    if (idx == arr.size() - 1)
    {
        return arr[idx];
    }

    return std::max(arr[idx], largestInteger(arr, idx + 1));
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        constexpr std::size_t capacity = 8;
        std::vector<int> arr(capacity);

        std::cout << "Enter a list of eight integers: ";
        for (std::size_t i = 0; i < capacity; ++i)
        {
            if (!(std::cin >> arr[i]))
            {
                throw std::runtime_error("Invalid integer input encountered.");
            }
        }

        std::cout << "The largest integer in the list is " << largestInteger(arr) << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred.\n";
        return 2;
    }

    return 0;
}