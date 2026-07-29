#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <iomanip>

/**
 * *8.21 (Central city) Given a set of cities, the central city is the city that has the shortest
 * total distance to all other cities. Write a program that prompts the user to enter
 * the number of the cities and the locations of the cities (coordinates), and finds
 * the central city and its total distance to all other cities.
 * Drop a yellow disk at column (0–6): 3
 * | | | | | | | |
 * | | | | | | | |
 * | | | | | | | |
 * | | | | | | | |
 * | | | | | | | |
 * |R| | |Y| | | |
 * . . .
 * . . .
 * . . .
 * Drop a yellow disk at column (0–6): 6
 * | | | | | | | |
 * | | | | | | | |
 * | | | |R| | | |
 * | | | |Y|R|Y| |
 * | | |R|Y|Y|Y|Y|
 * |R|Y|R|Y|R|R|R|
 * ———————————————
 * The yellow player won
 * Enter the number of cities: 5
 * Enter the coordinates of the cities:
 * 2.5 5 5.1 3 1 9 5.4 54 5.5 2.1
 * The central city is at (2.5, 5.0)
 * The total distance to all other cities is 60.81
 */



/** Finds the index of the minimum value in an array */
int indexOfMin(const std::vector<double>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("Array cannot be empty.");
    }

    int index = 0;
    double minDistance = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        if (minDistance > arr[i]) {
            minDistance = arr[i];
            index = static_cast<int>(i);
        }
    }
    return index;
}

/** Computes the Euclidean distance matrix between all pairs of cities */
std::vector<std::vector<double>> findDistances(const std::vector<std::vector<double>>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("Coordinates array cannot be empty.");
    }

    size_t n = arr.size();
    std::vector<std::vector<double>> d(n, std::vector<double>(n, 0.0));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            double x1 = arr[i][0];
            double y1 = arr[i][1];
            double x2 = arr[j][0];
            double y2 = arr[j][1];
            d[i][j] = std::hypot(x2 - x1, y2 - y1);
        }
    }
    return d;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::cout << "Enter the number of cities: ";
        int numCities = 0;
        if (!(std::cin >> numCities)) {
            std::cerr << "Error: Invalid integer format for the number of cities.\n";
            return EXIT_FAILURE;
        }

        if (numCities <= 0) {
            std::cerr << "Error: Number of cities must be greater than zero.\n";
            return EXIT_FAILURE;
        }

        std::vector<std::vector<double>> coor(numCities, std::vector<double>(2));
        std::cout << "Enter the coordinates of the " << numCities << " cities: ";

        for (int i = 0; i < numCities; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (!(std::cin >> coor[i][j])) {
                    std::cerr << "Error: Invalid numeric input format.\n";
                    return EXIT_FAILURE;
                }
            }
        }

        std::vector<std::vector<double>> distances = findDistances(coor);
        std::vector<double> sumOfDistances(distances.size(), 0.0);

        for (size_t i = 0; i < sumOfDistances.size(); ++i) {
            for (size_t j = 0; j < distances[i].size(); ++j) {
                sumOfDistances[i] += distances[i][j];
            }
        }

        // Find the index of the city with the minimum total distance
        int indexMin = indexOfMin(sumOfDistances);

        std::cout << "\nThe central city is at (" << coor[indexMin][0] << ", " << coor[indexMin][1] << ")\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "And the total distance to all other cities is " << sumOfDistances[indexMin] << '\n';

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