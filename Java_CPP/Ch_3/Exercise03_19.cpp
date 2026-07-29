#include <iostream>
#include <stdexcept>
/**
 * *3.18 (Cost of shipping) A shipping company uses the following function to
 * calculate the cost (in dollars) of shipping based on the weight of the
 * package (in pounds). c(w) = d 3.5, if 0 5.5, if 1 8.5, if 3 10.5, if 10 666
 * 6www w666 ===6 =131020
 * <p>
 * Write a program that prompts the user to enter the weight of the package and
 * display the shipping cost. If the weight is greater than 50, display a
 * message “the package cannot be shipped.”
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try {
        double s1 = 0.0;
        double s2 = 0.0;
        double s3 = 0.0;
        std::cout << "Enter the sides of a triangle separated by spaces: ";
        if (!(std::cin >> s1 >> s2 >> s3)) {
            throw std::runtime_error("Invalid input: Please enter valid numeric values for the triangle edges.");
        }
        if (s1 <= 0.0 || s2 <= 0.0 || s3 <= 0.0) {
            std::cout << "Invalid Input.\n";
            return 0;
        }
        if (s3 > (s1 + s2) || s2 > (s1 + s3) || s1 > (s3 + s2)) {
            std::cout << "Invalid Input.\n";
        } else {
            std::cout << "Perimeter is " << (s1 + s2 + s3) << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}