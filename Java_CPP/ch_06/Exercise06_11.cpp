#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>

/**
 * 6.11 (Financial application: compute commissions) Write a method that computes the
 * commission, using the scheme in Programming Exercise 5.39.
 * <p><br>
 * {@code 5.39 (Financial application: find the sales amount) You have just started a sales job
 * in a department store. Your pay consists of a base salary and a commission. The
 * base salary is $5,000. The scheme shown below is used to determine the commission rate.
 * <p>
 * Sales Amount --------- Commission Rate
 * <p>
 * $0.01–$5,000 --------------- 8 percent
 * <p>
 * $5,000.01–$10,000 ---------- 10 percent
 * <p>
 * $10,000.01 and above ------- 12 percent
 * <p>
 * <p>
 * Note that this is a graduated rate. The rate for the first $5,000 is at 8%, the next
 * $5000 is at 10%, and the rest is at 12%. If the sales amount is 25,000, the commission is 5,000 * 8% + 5,000 * 10% + 15,000 * 12% = 2,700.
 * <p><br>}
 * <p>
 * <p>
 * The header of the
 * method is as follows:
 * public static double computeCommission(double salesAmount)
 * <p>
 * Write a test program that displays the following table:
 * Sales Amount Commission
 * 10000 900.0
 * 15000 1500.0
 * ...
 * 95000 11100.0
 * 100000 11700.0
 */

constexpr double compute_commission(double sales_amount)
{
    double commission = 0.0;
    if (sales_amount <= 5000.0)
    {
        commission = sales_amount * 0.08;
    }
    else if (sales_amount <= 10000.0)
    {
        double remaining_sales = sales_amount - 5000.0;
        commission = (5000.0 * 0.08) + (remaining_sales * 0.10);
    }
    else
    {
        commission = (5000.0 * 0.08) + (5000.0 * 0.10);
        double remaining_sales = sales_amount - 10000.0;
        commission += remaining_sales * 0.12;
    }
    return commission;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Sales   Commission Amount\n";
        for (int sales = 10000; sales <= 100000; sales += 5000)
        {
            std::cout << sales << "   "
                      << std::fixed << std::setprecision(1)
                      << compute_commission(static_cast<double>(sales)) << '\n';
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