#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * 4.23 (Financial application: payroll) Reads employee payroll details
 * and prints a formatted payroll statement with exception handling and
 * resource management.
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::cout << "Enter employee's name: ";
        std::string name;
        if (!std::getline(std::cin, name))
        {
            std::cout << "Error: Invalid input.\n";
            return EXIT_SUCCESS;
        }
        std::cout << "Enter number of hours worked in a week: ";
        double hours = 0.0;
        if (!(std::cin >> hours))
        {
            std::cerr << "Error: Invalid numeric input. Please enter numbers for hours, pay rate, and tax rates.\n";
            return EXIT_SUCCESS;
        }

        std::cout << "Enter hourly pay rate: ";
        double pay_rate = 0.0;
        if (!(std::cin >> pay_rate))
        {
            std::cerr << "Error: Invalid numeric input. Please enter numbers for hours, pay rate, and tax rates.\n";
            return EXIT_SUCCESS;
        }

        std::cout << "Enter federal tax withholding rate: ";
        double federal_tax_rate = 0.0;
        if (!(std::cin >> federal_tax_rate))
        {
            std::cerr << "Error: Invalid numeric input. Please enter numbers for hours, pay rate, and tax rates.\n";
            return EXIT_SUCCESS;
        }

        std::cout << "Enter state tax withholding rate: ";
        double state_tax_rate = 0.0;
        if (!(std::cin >> state_tax_rate))
        {
            std::cerr << "Error: Invalid numeric input. Please enter numbers for hours, pay rate, and tax rates.\n";
            return EXIT_SUCCESS;
        }

        double gross_pay = hours * pay_rate;
        double federal_tax = gross_pay * federal_tax_rate;
        double state_tax = gross_pay * state_tax_rate;
        double total_tax = federal_tax + state_tax;
        double net_pay = gross_pay - total_tax;

        std::cout << "\nEmployee Name: " << name << '\n';
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Hours Worked: " << hours << '\n';
        std::cout << "Pay Rate: $" << std::setprecision(2) << pay_rate << '\n';
        std::cout << "Gross Pay: $" << std::setprecision(2) << gross_pay << '\n';
        std::cout << "Deductions:\n";
        std::cout << "  Federal Withholding (" << std::setprecision(1) << (federal_tax_rate * 100.0) << "%): $"
                  << std::setprecision(2) << federal_tax << '\n';
        std::cout << "  State Withholding (" << std::setprecision(1) << (state_tax_rate * 100.0) << "%): $"
                  << std::setprecision(2) << state_tax << '\n';
        std::cout << "  Total Deduction: $" << std::setprecision(2) << total_tax << '\n';
        std::cout << "Net Pay: $" << std::setprecision(2) << net_pay << '\n';

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}