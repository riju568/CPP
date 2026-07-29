#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <exception>
#include <cstdlib>


class Tax
{
public:
    static constexpr int SINGLE_FILER = 0;
    static constexpr int MARRIED_JOINTLY_OR_QUALIFYING_WIDOW_ER = 1;
    static constexpr int MARRIED_SEPARATELY = 2;
    static constexpr int HEAD_OF_HOUSEHOLD = 3;

private:
    int filingStatus{SINGLE_FILER};
    std::vector<std::vector<int>> brackets;
    std::vector<double> rates;
    double taxableIncome{0.0};

public:
    Tax() = default;

    Tax(int status,
        std::vector<std::vector<int>> b,
        std::vector<double> r,
        double income)
        : filingStatus(status),
          brackets(std::move(b)),
          rates(std::move(r)),
          taxableIncome(income) {}
    [[nodiscard]] int getFilingStatus() const { return filingStatus; }
    void setFilingStatus(int status) { filingStatus = status; }
    [[nodiscard]] const std::vector<std::vector<int>>& getBrackets() const { return brackets; }
    void setBrackets(std::vector<std::vector<int>> b) { brackets = std::move(b); }
    [[nodiscard]] const std::vector<double>& getRates() const { return rates; }
    void setRates(std::vector<double> r) { rates = std::move(r); }
    [[nodiscard]] double getTaxableIncome() const { return taxableIncome; }
    void setTaxableIncome(double income) { taxableIncome = income; }
    [[nodiscard]] double getTax() const
    {
        if (brackets.empty() || rates.empty() || filingStatus < 0 || static_cast<std::size_t>(filingStatus) >= brackets.size())
        {
            return 0.0;
        }
        const auto& currentBrackets = brackets[filingStatus];
        double totalTax = 0.0;
        if (taxableIncome <= currentBrackets[0])
        {
            return taxableIncome * rates[0];
        }

        totalTax += currentBrackets[0] * rates[0];
        for (std::size_t i = 1; i < currentBrackets.size(); ++i)
        {
            if (taxableIncome > currentBrackets[i])
            {
                totalTax += (currentBrackets[i] - currentBrackets[i - 1]) * rates[i];
            }
            else
            {
                totalTax += (taxableIncome - currentBrackets[i - 1]) * rates[i];
                return totalTax;
            }
        }
        if (taxableIncome > currentBrackets.back())
        {
            totalTax += (taxableIncome - currentBrackets.back()) * rates.back();
        }

        return totalTax;
    }
};

void printTaxTable(const std::string& yearTitle,
                   const std::vector<double>& rates,
                   const std::vector<std::vector<int>>& brackets)
{
    std::cout << "\n=========================================================================================\n"
              << "                                 Tax Tables for " << yearTitle << "\n"
              << "=========================================================================================\n";

    std::cout << std::right 
              << std::setw(15) << "Taxable Income"
              << std::setw(18) << "Single Filer"
              << std::setw(20) << "Married Jointly"
              << std::setw(21) << "Married Separately"
              << std::setw(20) << "Head of House\n";
    std::cout << "-----------------------------------------------------------------------------------------\n";

    Tax taxCalculator(Tax::SINGLE_FILER, brackets, rates, 0.0);

    for (int income = 50000; income <= 60000; income += 1000)
    {
        taxCalculator.setTaxableIncome(income);
        std::cout << std::right << std::setw(15) << income << std::fixed << std::setprecision(2);
        taxCalculator.setFilingStatus(Tax::SINGLE_FILER);
        std::cout << std::setw(18) << taxCalculator.getTax();
        taxCalculator.setFilingStatus(Tax::MARRIED_JOINTLY_OR_QUALIFYING_WIDOW_ER);
        std::cout << std::setw(20) << taxCalculator.getTax();
        taxCalculator.setFilingStatus(Tax::MARRIED_SEPARATELY);
        std::cout << std::setw(21) << taxCalculator.getTax();
        taxCalculator.setFilingStatus(Tax::HEAD_OF_HOUSEHOLD);
        std::cout << std::setw(20) << taxCalculator.getTax() << "\n";
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        // --- 2001 Tax Configuration ---
        std::vector<double> rates2001 = {0.15, 0.275, 0.305, 0.355, 0.391};
        std::vector<std::vector<int>> brackets2001 = {
            {27050, 65550, 136750, 297350}, // Single
            {45200, 109250, 166500, 297350}, // Married Jointly
            {22600, 54625,  83250,  148675}, // Married Separately (corrected typo 54620 -> 54625)
            {36250, 93650,  151650, 297350}  // Head of Household
        };

        // --- 2009 Tax Configuration ---
        std::vector<double> rates2009 = {0.10, 0.15, 0.25, 0.28, 0.33, 0.35};
        std::vector<std::vector<int>> brackets2009 = {
            {8350,  33950, 82250,  171550, 372950}, // Single
            {16700, 67900, 137050, 208850, 372950}, // Married Jointly (corrected typo 20885 -> 208850)
            {8350,  33950, 68525,  104425, 186475}, // Married Separately
            {11950, 45500, 117450, 190200, 372950}  // Head of Household
        };
        printTaxTable("2001", rates2001, brackets2001);
        printTaxTable("2009", rates2009, brackets2009);
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