#include <iostream>
#include <random>
#include <stdexcept>

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 99);

        int n1 = dis(gen);
        int n2 = dis(gen);

        std::cout << "What is " << n1 << " + " << n2 << "? ";
        int user_answer = 0;
        if (!(std::cin >> user_answer))
        {
            throw std::runtime_error("Invalid input: Please enter a valid integer.");
        }
        if (n1 + n2 == user_answer)
        {
            std::cout << "You are correct!\n";
        }
        else
        {
            std::cout << "Your answer is wrong.\n";
            std::cout << n1 << " + " << n2 << " should be " << (n1 + n2) << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}