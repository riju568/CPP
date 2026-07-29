#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>

class Stock {
private:
    std::string symbol;
    std::string name;
    double previousClosingPrice;
    double currentPrice;

public:
    Stock(const std::string& symbol, const std::string& name) {
        if (symbol.empty() || symbol.find_first_not_of(" \t\n\r") == std::string::npos) {
            throw std::invalid_argument("Stock symbol cannot be null or empty.");
        }
        if (name.empty() || name.find_first_not_of(" \t\n\r") == std::string::npos) {
            throw std::invalid_argument("Stock name cannot be null or empty.");
        }
        this->symbol = symbol;
        this->name = name;
        this->previousClosingPrice = 0.0;
        this->currentPrice = 0.0;
    }

    std::string getSymbol() const {
        return symbol;
    }

    std::string getName() const {
        return name;
    }

    double getPreviousClosingPrice() const {
        return previousClosingPrice;
    }

    void setPreviousClosingPrice(double previousClosingPrice) {
        if (previousClosingPrice <= 0) {
            throw std::invalid_argument("Previous closing price must be greater than 0.");
        }
        this->previousClosingPrice = previousClosingPrice;
    }

    double getCurrentPrice() const {
        return currentPrice;
    }

    void setCurrentPrice(double currentPrice) {
        if (currentPrice < 0) {
            throw std::invalid_argument("Current price cannot be negative.");
        }
        this->currentPrice = currentPrice;
    }

    double getChangePercent() const {
        if (previousClosingPrice == 0) {
            return 0.0;
        }
        return ((currentPrice - previousClosingPrice) / previousClosingPrice);
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        Stock testStock("ORCL", "Oracle Corporation");
        testStock.setPreviousClosingPrice(34.5);
        testStock.setCurrentPrice(34.35);

        double percentChange = std::round(testStock.getChangePercent() * 10000.0) / 100.0;

        std::cout << "The price change for " << testStock.getSymbol() << " "
                  << testStock.getName() << " is " << percentChange << "%\n";

        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Error initializing or updating stock: " << e.what() << '\n';
        return EXIT_FAILURE;
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