#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <exception>

/**
 * <p>
 * Write a test program that prompts
 * the user to enter a two-dimensional array and displays the location of the largest
 * element in the array. Here is a sample run:
 * <p>
 * * Enter the number of rows and columns in the array: 3 4
 * * Enter the array:
 * * 23.5 35 2 10
 * * 4.5 3 45 3.5
 * * 35 44 5.5 9.6
 * * The location of the largest element is 45 at (1, 2)
 */


class Location {
public:
    int row;
    int column;
    double maxValue;

    Location(int r, int c, double maxVal) : row(r), column(c), maxValue(maxVal) {}

    static Location locateLargest(const std::vector<std::vector<double>>& a) {
        if (a.empty() || a[0].empty()) {
            return Location(-1, -1, 0.0);
        }

        int maxRow = 0;
        int maxCol = 0;
        double maxVal = a[0][0];

        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < a[i].size(); ++j) {
                if (a[i][j] > maxVal) {
                    maxVal = a[i][j];
                    maxRow = static_cast<int>(i);
                    maxCol = static_cast<int>(j);
                }
            }
        }
        return Location(maxRow, maxCol, maxVal);
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter the number of rows and columns in the array: ";
        int numRow, numCol;
        if (!(std::cin >> numRow >> numCol)) {
            return EXIT_FAILURE; // Handle invalid input
        }
        std::vector<std::vector<double>> numbers(numRow, std::vector<double>(numCol));
        std::cout << "Enter the array:\n";
        for (int r = 0; r < numRow; ++r) {
            for (int c = 0; c < numCol; ++c) {
                std::cin >> numbers[r][c];
            }
        }
        Location location = Location::locateLargest(numbers);
        std::cout << "The location of the largest element is: "  << std::defaultfloat << location.maxValue  << " at (" << location.row << ", " << location.column << ")\n";

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