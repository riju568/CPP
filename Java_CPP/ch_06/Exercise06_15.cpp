#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <exception>
#include <cstdlib>

/**
 * *6.15 (Financial application: print a tax table) Listing 3.5 gives a program to compute
 * tax. Write a method for computing tax using the following header:
 * double compute_tax(int status, double taxable_income)
 *
 * Use this method to write a program that prints a tax table for taxable income from
 * $50,000 to $60,000 with intervals of $50 for all filing statuses.
 */

double compute_tax(int status, double taxable_income)
{
    double tax = 0.0;

    int up_bound10 = 0;
    int up_bound15 = 0;
    int up_bound25 = 0;
    int up_bound28 = 0;
    int up_bound33 = 0;

    if (status == 0) // Single filers
    {
        up_bound10 = 8350;
        up_bound15 = 33950;
        up_bound25 = 82250;
        up_bound28 = 171550;
        up_bound33 = 372950;
    }
    else if (status == 1) // Married Filing Jointly or Qualifying Widow(er)
    {
        up_bound10 = 16700;
        up_bound15 = 67900;
        up_bound25 = 137050;
        up_bound28 = 208850;
        up_bound33 = 372950;
    }
    else if (status == 2) // Married Filing Separately
    {
        up_bound10 = 8350;
        up_bound15 = 33950;
        up_bound25 = 68525;
        up_bound28 = 104425;
        up_bound33 = 186475;
    }
    else if (status == 3) // Head of Household
    {
        up_bound10 = 11950;
        up_bound15 = 45500;
        up_bound25 = 117450;
        up_bound28 = 190200;
        up_bound33 = 372950;
    }
    else
    {
        std::cerr << "Error: invalid status\n";
        std::exit(EXIT_FAILURE);
    }

    if (taxable_income <= up_bound10)
    {
        tax = taxable_income * 0.10;
    }
    else if (taxable_income <= up_bound15)
    {
        tax = up_bound10 * 0.10 + (taxable_income - up_bound10) * 0.15;
    }
    else if (taxable_income <= up_bound25)
    {
        tax = up_bound10 * 0.10 + (up_bound15 - up_bound10) * 0.15 + (taxable_income - up_bound15) * 0.25;
    }
    else if (taxable_income <= up_bound28)
    {
        tax = up_bound10 * 0.10 + (up_bound15 - up_bound10) * 0.15 + (up_bound25 - up_bound15) * 0.25
            + (taxable_income - up_bound25) * 0.28;
    }
    else if (taxable_income <= up_bound33)
    {
        tax = up_bound10 * 0.10 + (up_bound15 - up_bound10) * 0.15 + (up_bound25 - up_bound15) * 0.25
            + (up_bound28 - up_bound25) * 0.28 + (taxable_income - up_bound28) * 0.33;
    }
    else
    {
        tax = up_bound10 * 0.10 + (up_bound15 - up_bound10) * 0.15 + (up_bound25 - up_bound15) * 0.25
            + (up_bound28 - up_bound25) * 0.28 + (up_bound33 - up_bound28) * 0.33 + (taxable_income - up_bound33) * 0.35;
    }

    return tax;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        const std::string space = "      ";
        const std::string spacex2 = space + "    ";

        std::cout << "Taxable" << space << "Single" << space << "Married Joint" << space << "Married" << space << "Head " << "of";
        std::cout << "\nIncome" << space << "     " << space << " Or Qualifying" << space << "Separate" << "      " << "a " << "House";
        std::cout << "\n      " << space << "       " << space << "Widow(er)" << space << "       " << space << "     ";
        std::cout << "\n_____________________________________________________________________\n";

        for (int i = 50000; i <= 60000; i += 50)
        {
            std::cout << i
                      << spacex2 << std::lround(compute_tax(0, i))
                      << spacex2 << std::lround(compute_tax(1, i))
                      << spacex2 << std::lround(compute_tax(2, i))
                      << spacex2 << std::lround(compute_tax(3, i)) << '\n';
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