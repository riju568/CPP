#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * 7.4 (Analyze scores) Write a program that reads an unspecified number
 * of scores and determines how many scores are above or equal to the average
 * and how many scores are below the average. Enter a negative number to
 * signify the end of the input. Assume that the maximum
 * number of scores is 100.
 */

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<double> scores;
        double sum = 0.0;

        std::cout << "Enter a new score (enter a negative number to complete program):\n";

        for (int i = 0; i < 100; ++i)
        {
            double score = 0.0;
            if (!(std::cin >> score))
            {
                std::cerr << "Error: Invalid score input.\n";
                return EXIT_FAILURE;
            }

            if (score < 0)
            {
                break;
            }

            scores.push_back(score);
            sum += score;
        }

        if (scores.empty())
        {
            std::cout << "No scores entered.\n";
            return EXIT_SUCCESS;
        }

        double average = sum / scores.size();
        int above_or_equal = 0;

        for (double score : scores)
        {
            if (score >= average)
            {
                above_or_equal++;
            }
        }

        std::cout << "Count is: " << scores.size() << '\n';
        std::cout.precision(2);
        std::cout << std::fixed;
        std::cout << "The average is " << average << '\n';
        std::cout << "Number of scores above or equal to average is: " << above_or_equal << '\n';
        std::cout << "Number of scores below the average is: " << (scores.size() - above_or_equal) << '\n';

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