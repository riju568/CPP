#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>

/**
 * 7.1 (Assign grades) Write a program that reads student scores, gets the best score,
 * and then assigns grades based on the following scheme:
 * Grade is A if score is >= best - 10
 * Grade is B if score is >= best - 20;
 * Grade is C if score is >= best - 30;
 * Grade is D if score is >= best - 40;
 * Grade is F otherwise.
 * The program prompts the user to enter the total number of students, then prompts
 * the user to enter all of the scores, and concludes by displaying the grades.
 */

int find_best_grade(const std::vector<int> &grades)
{
    int best = grades[0];
    for (size_t i = 1; i < grades.size(); ++i)
    {
        if (grades[i] > best)
        {
            best = grades[i];
        }
    }
    return best;
}

void print_letter_grades(const std::vector<int> &grades, int best_grade)
{
    for (size_t j = 0; j < grades.size(); ++j)
    {
        char letter_grade;
        if (grades[j] >= (best_grade - 10))
        {
            letter_grade = 'A';
        }
        else if (grades[j] >= (best_grade - 20))
        {
            letter_grade = 'B';
        }
        else if (grades[j] >= (best_grade - 30))
        {
            letter_grade = 'C';
        }
        else if (grades[j] >= (best_grade - 40))
        {
            letter_grade = 'D';
        }
        else
        {
            letter_grade = 'F';
        }
        std::cout << "Student " << j << " score is " << grades[j] << " and grade is " << letter_grade << '\n';
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter number of students now: ";
        int num_of_students = 0;
        if (std::cin >> num_of_students)
        {
            if (num_of_students <= 0)
            {
                std::cout << "Error: Number of students must be greater than zero.\n";
                return EXIT_SUCCESS;
            }

            std::vector<int> grades(num_of_students);
            std::cout << "Now enter " << num_of_students << " space separated scores: \n";

            for (int i = 0; i < num_of_students; ++i)
            {
                std::cin >> grades[i];
            }

            print_letter_grades(grades, find_best_grade(grades));
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