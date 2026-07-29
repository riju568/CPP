#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <exception>
/**
 * **9.13 (The Location class) Design a class named Location for locating a maximal
 * value and its location in a two-dimensional array.
 * <p>
 * The class contains public data
 * fields row, column, and maxValue that store the maximal value and its indices
 * in a two-dimensional array with row and column as int types and maxValue as
 * a double type.
 * Write the following method that returns the location of the largest element in a
 * two-dimensional array:
 * public static Location locateLargest(double[][] a)
 * The return value is an instance of Location.
 */


class Location {
public:
    int row;
    int column;
    double maxValue;

    Location() 
        : row(0), column(0), maxValue(std::numeric_limits<double>::lowest()) {}

    static Location locateLargest(const std::vector<std::vector<double>>& a) {
        Location location;

        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < a[i].size(); ++j) {
                if (a[i][j] > location.maxValue) {
                    location.maxValue = a[i][j];
                    location.row = static_cast<int>(i);
                    location.column = static_cast<int>(j);
                }
            }
        }
        return location;
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter the number of rows and columns in the array: ";
        int numRow, numCol;
        if (!(std::cin >> numRow >> numCol)) {
            return EXIT_FAILURE;
        }

        std::vector<std::vector<double>> numbers(numRow, std::vector<double>(numCol));

        std::cout << "Enter the array:\n";
        for (int r = 0; r < numRow; ++r) {
            for (int c = 0; c < numCol; ++c) {
                std::cin >> numbers[r][c];
            }
        }

        Location location = Location::locateLargest(numbers);

        std::cout << "The location of the largest element is: " 
                  << location.maxValue 
                  << " at (" << location.row << ", " << location.column << ")\n";

        return EXIT_SUCCESS;
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