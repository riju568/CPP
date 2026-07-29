#ifndef TAX_HPP
#define TAX_HPP
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

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
    double taxableIncome{0.0};
    std::vector<double> rates;
    [[nodiscard]] std::size_t getNumRates() const
    {
        return rates.size();
    }

public:
    Tax() = default;
    Tax(int filingStatus,
        std::vector<std::vector<int>> brackets,
        std::vector<double> rates,
        double taxableIncome)
        : filingStatus(filingStatus),
          brackets(std::move(brackets)),
          taxableIncome(taxableIncome),
          rates(std::move(rates)) {}
    [[nodiscard]] double getTax() const
    {
        if (brackets.empty() || rates.empty() || filingStatus < 0 || static_cast<std::size_t>(filingStatus) >= brackets.size())
        {
            return 0.0;
        }

        const auto &bracket = brackets[filingStatus];

        if (taxableIncome <= bracket[0])
        {
            return taxableIncome * rates[0];
        }

        std::size_t i = 1;
        double tax = bracket[0] * rates[0];

        while (i < bracket.size())
        {
            if (taxableIncome <= bracket[i])
            {
                return tax + (taxableIncome - bracket[i - 1]) * rates[i];
            }
            tax += (bracket[i] - bracket[i - 1]) * rates[i];
            ++i;
        }

        return tax + (taxableIncome - bracket.back()) * rates.back();
    }
    [[nodiscard]] int getFilingStatus() const { return filingStatus; }
    void setFilingStatus(int status) { filingStatus = status; }
    [[nodiscard]] const std::vector<std::vector<int>> &getBrackets() const { return brackets; }
    void setBrackets(std::vector<std::vector<int>> b) { brackets = std::move(b); }
    [[nodiscard]] double getTaxableIncome() const { return taxableIncome; }
    void setTaxableIncome(double income) { taxableIncome = income; }
    [[nodiscard]] const std::vector<double> &getRates() const { return rates; }
    void setRates(std::vector<double> r) { rates = std::move(r); }
    [[nodiscard]] std::string toString() const
    {
        std::ostringstream oss;
        oss << "Tax{filingStatus=" << filingStatus << ", brackets=[";
        if (filingStatus >= 0 && static_cast<std::size_t>(filingStatus) < brackets.size())
        {
            const auto &b = brackets[filingStatus];
            for (std::size_t i = 0; i < b.size(); ++i)
            {
                oss << b[i] << (i + 1 < b.size() ? ", " : "");
            }
        }

        oss << "], taxableIncome=" << taxableIncome << ", rates=[";
        for (std::size_t i = 0; i < rates.size(); ++i)
        {
            oss << rates[i] << (i + 1 < rates.size() ? ", " : "");
        }
        oss << "]}";
        return oss.str();
    }
};

#endif // TAX_HPP