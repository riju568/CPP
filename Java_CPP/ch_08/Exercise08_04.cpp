#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * 8.4 (Compute the weekly hours for each employee)
 * Suppose the weekly hours for all employees are stored
 * in a two-dimensional array. Each row records an employee's
 * seven-day work hours with seven columns. For example, the
 * following array stores the work hours for eight employees.
 * Write a program that displays employees and their total
 * hours in decreasing order of the total hours.
 */
void printArray(const std::vector<std::vector<int>>& array) {
    std::cout << "Employees and their total hours (in decreasing order):\n";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << "Employee number: " << array[i][1] << "'s total hours for the week were " << array[i][0] << '\n';
    }
}


void processAndSortEmployeeHours(const std::vector<std::vector<int>>& employeeHours) {
    if (employeeHours.empty()) {
        throw std::invalid_argument("Employee hours matrix cannot be empty.");
    }

    std::vector<std::vector<int>> sumHours(employeeHours.size(), std::vector<int>(2, 0));
    for (size_t row = 0; row < employeeHours.size(); ++row) {
        if (employeeHours[row].empty()) {
            std::cout << "Warning: Employee " << row << " hour records are missing or empty.\n";
            sumHours[row][1] = static_cast<int>(row);
            continue;
        }

        int weeklySum = 0;
        for (size_t column = 0; column < employeeHours[row].size(); ++column) {
            weeklySum += employeeHours[row][column];
        }
        sumHours[row][0] = weeklySum;   // Total hours
        sumHours[row][1] = static_cast<int>(row); // Original employee ID index
    }

    // Selection Sort for descending order
    for (size_t i = 0; i < sumHours.size() - 1; ++i) {
        for (size_t j = i + 1; j < sumHours.size(); ++j) {
            if (sumHours[j][0] > sumHours[i][0]) {
                std::vector<int> tmp = sumHours[i];
                sumHours[i] = sumHours[j];
                sumHours[j] = tmp;
            }
        }
    }

    printArray(sumHours);
}

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<std::vector<int>> employeeHours = {
            {2, 4, 3, 4, 5, 8, 8},  // emp0
            {7, 3, 4, 3, 3, 4, 4},  // emp1
            {3, 3, 4, 3, 3, 2, 2},  // emp2
            {9, 3, 4, 7, 3, 4, 1},  // emp3
            {3, 5, 4, 3, 6, 3, 8},  // emp4
            {3, 4, 4, 6, 3, 4, 4},  // emp5
            {3, 7, 4, 8, 3, 8, 4},  // emp6
            {6, 3, 5, 9, 2, 7, 9}   // emp7
        };

        processAndSortEmployeeHours(employeeHours);

        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Validation Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    } 
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}