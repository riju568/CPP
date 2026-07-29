#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <cstdlib>


/**
 * 9.2 (The Stock class) Following the example of the Circle class in Section 9.2,
 * design a class named Stock that contains:
 * ■ A string data field named symbol for the stock’s symbol.
 * ■ A string data field named name for the stock’s name.
 * ■ A double data field named previousClosingPrice that stores the stock
 * price for the previous day.
 * ■ A double data field named currentPrice that stores the stock price for the
 * current time.
 * ■ A constructor that creates a stock with the specified symbol and name.
 * ■ A method named getChangePercent() that returns the percentage changed
 * from previousClosingPrice to currentPrice.
 * Draw the UML diagram for the class and then implement the class.
 * <p>
 * Write a test
 * program that creates a Stock object with the stock symbol ORCL, the name
 * Oracle Corporation, and the previous closing price of 34.5. Set a new current
 * price to 34.35 and display the price-change percentage.
 */

class Stock {
private:
    std::string symbol;
    std::string name;
    double previousClosingPrice;
    double currentPrice;

public:
    Stock() : previousClosingPrice(0.0), currentPrice(0.0) {}

    Stock(const std::string& symbol, const std::string& name) 
        : symbol(symbol), name(name), previousClosingPrice(0.0), currentPrice(0.0) {}

    std::string getSymbol() const {
        return symbol;
    }

    void setSymbol(const std::string& symbol) {
        this->symbol = symbol;
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    double getPreviousClosingPrice() const {
        return previousClosingPrice;
    }

    void setPreviousClosingPrice(double previousClosingPrice) {
        this->previousClosingPrice = previousClosingPrice;
    }

    double getCurrentPrice() const {
        return currentPrice;
    }

    void setCurrentPrice(double currentPrice) {
        this->currentPrice = currentPrice;
    }

    double getChangePercent() const {
        if (currentPrice == 0.0) {
            return 0.0;
        }
        return (currentPrice - previousClosingPrice) / currentPrice;
    }

    std::string toString() const {
        return "Stock{}";
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        Stock stock("ORCL", "Oracle Corporation");
        stock.setPreviousClosingPrice(34.5);
        stock.setCurrentPrice(34.35);

        double percentChange = std::round(stock.getChangePercent() * 10000.0) / 100.0;

        std::cout << "The price change for " << stock.getSymbol() << " "
                  << stock.getName() << " is " << percentChange << "%\n";

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