#include <iostream>
#include <random>
#include <chrono>
#include <limits>
#include <exception>
#include <cstdlib>

/**
 * 5.2 (Repeat additions) Generates ten random addition questions for two
 * integers between 1 and 15, tracking score and total test time with proper
 * exception handling and resource management.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        constexpr int NUMBER_OF_QUESTIONS = 10;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 15);

        int correct_answers = 0;
        int count = 0;

        auto start_time = std::chrono::steady_clock::now();

        while (count < NUMBER_OF_QUESTIONS)
        {
            int n1 = dist(gen);
            int n2 = dist(gen);

            std::cout << "Question " << (count + 1) << ": What is " << n1 << " + " << n2 << "? ";

            int answer = 0;
            if (!(std::cin >> answer))
            {
                std::cout << "Error: Invalid input. Please enter an integer.\n\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (n1 + n2 == answer)
            {
                std::cout << "Correct answer!\n\n";
                correct_answers++;
            }
            else
            {
                std::cout << "Wrong answer...\n";
                std::cout << "(Correct Answer) " << n1 << " + " << n2 << " = " << (n1 + n2) << "\n\n";
            }
            count++;
        }

        auto end_time = std::chrono::steady_clock::now();
        auto total_time_seconds = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();

        std::cout << "--- Summary ---\n";
        std::cout << "Total correct answers: " << correct_answers << " out of " << NUMBER_OF_QUESTIONS << '\n';
        std::cout << "Total runtime: " << total_time_seconds << " seconds.\n";

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