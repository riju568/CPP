#include <iostream>
#include <iomanip>
#include <stdexcept>
/**
 * *3.13 (Financial application: compute taxes) Listing 3.5, ComputeTax.java,
 * gives the source code to compute taxes for single filers. Complete Listing
 * 3.5 to compute the taxes for all filing statuses
 *
 *
 */
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);
    try {
        int status = 0;
        double income = 0.0;
        std::cout << "(0-single filer, 1-married jointly or qualifying widow(er), 2-married separately, 3-head of household) Enter the filing status: ";
        if (!(std::cin >> status)) {
            throw std::runtime_error("Invalid input: Please enter a valid integer for the filing status.");
        }
        if (status < 0 || status > 3) {
            throw std::out_of_range("Error: invalid status. Status must be an integer between 0 and 3.");
        }
        std::cout << "Enter the taxable income: ";
        if (!(std::cin >> income)) {
            throw std::runtime_error("Invalid input: Please enter a valid numeric value for taxable income.");
        }
        if (income < 0.0) {
            throw std::out_of_range("Taxable income cannot be a negative value.");
        }
        double tax = 0.0;
        int upBound10 = 0, upBound15 = 0, upBound25 = 0, upBound28 = 0, upBound33 = 0;

        if (status == 0) { 
            upBound10 = 8350;
            upBound15 = 33950;
            upBound25 = 82250;
            upBound28 = 171550;
            upBound33 = 372950;
        } else if (status == 1) { // Married Filing Jointly or Qualifying Widow(er)
            upBound10 = 16700;
            upBound15 = 67900;
            upBound25 = 137050;
            upBound28 = 208850;
            upBound33 = 372950;
        } else if (status == 2) { // Compute tax for married separately
            upBound10 = 8350;
            upBound15 = 33950;
            upBound25 = 68525;
            upBound28 = 104425;
            upBound33 = 186475;
        } else if (status == 3) { // Compute tax for head of household
            upBound10 = 11950;
            upBound15 = 45500;
            upBound25 = 117450;
            upBound28 = 190200;
            upBound33 = 372950;
        }

        if (income <= upBound10) {
            tax = income * 0.10;
        } else if (income <= upBound15) {
            tax = upBound10 * 0.10 + (income - upBound10) * 0.15;
        } else if (income <= upBound25) {
            tax = upBound10 * 0.10 + (upBound15 - upBound10) * 0.15 + (income - upBound15) * 0.25;
        } else if (income <= upBound28) {
            tax = upBound10 * 0.10 + (upBound15 - upBound10) * 0.15 + (upBound25 - upBound15) * 0.25
                    + (income - upBound25) * 0.28;
        } else if (income <= upBound33) {
            tax = upBound10 * 0.10 + (upBound15 - upBound10) * 0.15 + (upBound25 - upBound15) * 0.25
                    + (upBound28 - upBound25) * 0.28 + (income - upBound28) * 0.33;
        } else {
            tax = upBound10 * 0.10 + (upBound15 - upBound10) * 0.15 + (upBound25 - upBound15) * 0.25
                    + (upBound28 - upBound25) * 0.28 + (upBound33 - upBound28) * 0.33 + (income - upBound33) * 0.35;
        }
        std::cout << "Tax is " << std::fixed << std::setprecision(2) << (static_cast<int>(tax * 100) / 100.0) << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}