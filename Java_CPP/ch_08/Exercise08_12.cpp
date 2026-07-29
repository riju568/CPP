#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <exception>
#include <cstdlib>
/**
 * 8.12 (Financial application: compute tax) Rewrite Listing 3.5, ComputeTax.java,
 * using arrays. For each filing status, there are six tax rates. Each rate is applied
 * to a certain amount of taxable income.
 * <p>
 * For example, from the taxable income of $400,000 for a single filer, $8,350 is taxed at 10%, (33,950 - 8,350) at 15%,
 * (82,250 - 33,950) at 25%, (171,550 - 82,550) at 28%, (372,550 - 82,250) at
 * 33%, and (400,000 - 372,950) at 36%. The six rates are the same for all filing
 * statuses, which can be represented in the following array: double[] rates = {0.10, 0.15, 0.25, 0.28, 0.33, 0.35};
 * The brackets for each rate for all the filing statuses can be represented in a two-dimensional array as follows:
 * int[][] brackets = { {8350, 33950, 82250, 171550, 372950}, // Single filer
 * {16700, 67900, 137050, 20885, 372950}, // Married jointly -or qualifying widow(er)
 * {8350, 33950, 68525, 104425, 186475}, // Married separately
 * {11950, 45500, 117450, 190200, 372950} // Head of household
 * };
 * Suppose the taxable income is $400,000 for single filers. The tax can be computed as follows:
 * tax = brackets[0][0] * rates[0] +
 * (brackets[0][1] – brackets[0][0]) * rates[1] +
 * (brackets[0][2] – brackets[0][1]) * rates[2] +
 * (brackets[0][3] – brackets[0][2]) * rates[3] +
 * (brackets[0][4] – brackets[0][3]) * rates[4] +
 * (400000 – brackets[0][4]) * rates[5]
 */

/** Calculates the income tax based on brackets and rates */
double calcTax(double income, const std::vector<int> &bracket, const std::vector<double> &rates)
{
    if (bracket.empty() || rates.empty() || rates.size() != bracket.size() + 1)
    {
        throw std::invalid_argument("Invalid tax brackets or rates configuration.");
    }

    double tax = 0;
    double previousBracketLimit = 0;

    for (size_t i = 0; i < bracket.size(); ++i)
    {
        if (income > bracket[i])
        {
            // Tax the portion that falls within this bracket tier
            tax += (bracket[i] - previousBracketLimit) * rates[i];
            previousBracketLimit = bracket[i];
        }
        else
        {
            tax += (income - previousBracketLimit) * rates[i];
            return tax;
        }
    }
    tax += (income - previousBracketLimit) * rates[rates.size() - 1];

    return tax;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<double> rates = {0.10, 0.15, 0.25, 0.28, 0.33, 0.35};
        std::vector<std::vector<int>> brackets = {
            {8350, 33950, 82250, 171550, 372950},   // 0 - Single filer
            {16700, 67900, 137050, 208850, 372950}, // 1 - Married jointly or qualifying widow(er)
            {8350, 33950, 68525, 104425, 186475},   // 2 - Married separately
            {11950, 45500, 117450, 190200, 372950}  // 3 - Head of household
        };

        std::cout << "\nFiling Status Options:\n"
                  << "  0 - Single filer\n"
                  << "  1 - Married jointly or qualifying widow(er)\n"
                  << "  2 - Married separately\n"
                  << "  3 - Head of household\n"
                  << "Enter the filing status (0-3): ";

        int status = 0;
        if (!(std::cin >> status))
        {
            std::cerr << "Error: Invalid filing status format.\n";
            return EXIT_FAILURE;
        }

        if (status < 0 || status >= static_cast<int>(brackets.size()))
        {
            std::cerr << "Error: Invalid filing status. Please enter a value between 0 and 3.\n";
            return EXIT_FAILURE;
        }

        std::cout << "Enter the taxable income: ";
        double income = 0.0;
        if (!(std::cin >> income))
        {
            std::cerr << "Error: Invalid income format.\n";
            return EXIT_FAILURE;
        }

        if (income < 0)
        {
            std::cerr << "Error: Taxable income cannot be negative.\n";
            return EXIT_FAILURE;
        }

        double totalTax = calcTax(income, brackets[status], rates);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Tax is $" << totalTax << '\n';

        return EXIT_SUCCESS;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Validation Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}