#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <cstdlib>

/**
 * 7.17 (Sort students) Write a program that prompts the user to enter the number of students,
 * the students' names, and their scores, and prints student names and scores in decreasing
 * order of their scores.
 */

void sort_array(std::vector<double> &arr, std::vector<std::string> &array)
{
    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
        double current_max = arr[i];
        size_t current_index = i;

        for (size_t j = i + 1; j < arr.size(); ++j)
        {
            if (arr[j] > current_max)
            {
                current_max = arr[j];
                current_index = j;
            }
        }

        if (current_index != i)
        {
            double temp_score = arr[i];
            arr[i] = arr[current_index];
            arr[current_index] = temp_score;
            std::string temp_name = array[i];
            array[i] = array[current_index];
            array[current_index] = temp_name;
        }
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Please enter the number of students: ";
        int num_students = 0;
        if (!(std::cin >> num_students))
        {
            std::cerr << "Error: Invalid input for number of students.\n";
            return EXIT_FAILURE;
        }

        if (num_students <= 0)
        {
            std::cout << "Number of students must be greater than zero.\n";
            return EXIT_SUCCESS;
        }

        std::vector<double> scores(num_students);
        std::vector<std::string> names(num_students);

        for (int i = 0; i < num_students; ++i)
        {
            std::cout << "Enter a student name: ";
            if (!(std::cin >> names[i]))
            {
                std::cerr << "Error: Invalid input for student name.\n";
                return EXIT_FAILURE;
            }
            std::cout << "Enter the student's score: ";
            if (!(std::cin >> scores[i]))
            {
                std::cerr << "Error: Invalid input for student score.\n";
                return EXIT_FAILURE;
            }
        }

        sort_array(scores, names);
        std::cout << "The student names in decreasing order of their scores are:\n";

        for (int i = 0; i < num_students; ++i)
        {
            std::cout << names[i] << " " << scores[i] << '\n';
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