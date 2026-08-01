#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <exception>


// Base Class: Account

class Account {
private:
    int id{0};
    double balance{0.0};
    double annualInterestRate{0.0}; // Percentage, e.g., 4.5 = 4.5%
    std::chrono::system_clock::time_point dateCreated;

public:
    Account() : dateCreated(std::chrono::system_clock::now()) {}

    Account(int accountId, double initialBalance)
        : id(accountId), balance(initialBalance), dateCreated(std::chrono::system_clock::now()) {
        if (initialBalance < 0.0) {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
    }

    virtual ~Account() = default;

    // Getters and Setters
    [[nodiscard]] int getId() const noexcept { return id; }
    void setId(int accountId) noexcept { id = accountId; }

    [[nodiscard]] double getBalance() const noexcept { return balance; }
    void setBalance(double newBalance) noexcept { balance = newBalance; }

    [[nodiscard]] double getAnnualInterestRate() const noexcept { return annualInterestRate; }
    void setAnnualInterestRate(double rate) noexcept { annualInterestRate = rate; }

    [[nodiscard]] std::chrono::system_clock::time_point getDateCreated() const noexcept { return dateCreated; }

    [[nodiscard]] double getMonthlyInterestRate() const noexcept {
        return (annualInterestRate / 100.0) / 12.0;
    }

    [[nodiscard]] double getMonthlyInterest() const noexcept {
        return balance * getMonthlyInterestRate();
    }

    virtual void withdraw(double amount) {
        if (amount <= 0.0) {
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }
        if (balance - amount < 0.0) {
            throw std::runtime_error("Insufficient funds for withdrawal.");
        }
        balance -= amount;
    }

    virtual void deposit(double amount) {
        if (amount <= 0.0) {
            throw std::invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
    }

    [[nodiscard]] virtual std::string toString() const {
        auto timeT = std::chrono::system_clock::to_time_t(dateCreated);
        std::stringstream ss;
        ss << "Account ID: " << id << "\nBalance: $" << std::fixed << std::setprecision(2) << balance
           << "\nCreated on: " << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
};


// Derived Class: SavingsAccount

class SavingsAccount : public Account {
private:
    double minBalance{0.0}; // Cannot be overdrawn

public:
    SavingsAccount() : Account() {}

    SavingsAccount(int accountId, double initialBalance)
        : Account(accountId, initialBalance) {}

    void withdraw(double amount) override {
        if (amount <= 0.0) {
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }
        if (getBalance() - amount < minBalance) {
            throw std::runtime_error("Transaction rejected: Savings account cannot be overdrawn.");
        }
        setBalance(getBalance() - amount);
    }

    [[nodiscard]] std::string toString() const override {
        return Account::toString() + "\nOverdraft protection not included";
    }
};


// Derived Class: CheckingAccount

class CheckingAccount : public Account {
private:
    double overdraftLimit{-50.0}; // Negative boundary allowed

public:
    CheckingAccount() : Account() {}

    CheckingAccount(int accountId, double initialBalance, double limit = -50.0)
        : Account(accountId, initialBalance), overdraftLimit(limit) {}

    [[nodiscard]] double getOverdraftLimit() const noexcept { return overdraftLimit; }
    void setOverdraftLimit(double limit) noexcept { overdraftLimit = limit; }

    void withdraw(double amount) override {
        if (amount <= 0.0) {
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }
        if (getBalance() - amount < overdraftLimit) {
            throw std::runtime_error("Transaction rejected: Withdrawal exceeds overdraft limit.");
        }
        setBalance(getBalance() - amount);
    }

    [[nodiscard]] std::string toString() const override {
        std::stringstream ss;
        ss << Account::toString() << "\nOverdraft limit: $" 
           << std::fixed << std::setprecision(2) << overdraftLimit;
        return ss.str();
    }
};


// Main Function & Application Logic

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try {
        Account testAcct(1, 100.00);
        SavingsAccount testSaves(2, 500.00);
        CheckingAccount testCheck(3, 1000.00);
        std::cout << testAcct.toString() << "\n\n";
        std::cout << testSaves.toString() << "\n\n";
        std::cout << testCheck.toString() << "\n\n";
        std::cout << "--- Testing Withdrawal Guard Checks ---\n";
        
        try {
            std::cout << "Attempting to withdraw $600 from SavingsAccount (Balance $500)...\n";
            testSaves.withdraw(600.00);
        } catch (const std::exception& e) {
            std::cerr << "Caught Expected Error: " << e.what() << "\n\n";
        }

        try {
            std::cout << "Attempting to withdraw $1040 from CheckingAccount (Balance $1000, Limit -$50)...\n";
            testCheck.withdraw(1040.00);
            std::cout << "Transaction Success! New Balance: $" << testCheck.getBalance() << "\n\n";
        } catch (const std::exception& e) {
            std::cerr << "Caught Error: " << e.what() << "\n\n";
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Fatal Standard Exception: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}