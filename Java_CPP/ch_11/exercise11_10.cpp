#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <exception>


// Transaction Class
class Transaction {
private:
    char type{'D'};
    double amount{0.0};
    double balance{0.0};
    std::string description;
    std::chrono::system_clock::time_point transactionDate;

public:
    static constexpr char WITHDRAWAL = 'W';
    static constexpr char DEPOSIT = 'D';

    Transaction() : transactionDate(std::chrono::system_clock::now()) {}

    Transaction(char t, double amt, double bal, std::string desc)
        : type(t), amount(amt), balance(bal), description(std::move(desc)),
          transactionDate(std::chrono::system_clock::now()) {}

    [[nodiscard]] char getType() const noexcept { return type; }
    Transaction& setType(char t) noexcept { type = t; return *this; }
    [[nodiscard]] double getAmount() const noexcept { return amount; }
    Transaction& setAmount(double amt) noexcept { amount = amt; return *this; }
    [[nodiscard]] double getBalance() const noexcept { return balance; }
    Transaction& setBalance(double bal) noexcept { balance = bal; return *this; }
    [[nodiscard]] std::string getDescription() const { return description; }
    Transaction& setDescription(std::string desc) { description = std::move(desc); return *this; }
    [[nodiscard]] std::chrono::system_clock::time_point getTransactionDate() const noexcept {
        return transactionDate;
    }

    [[nodiscard]] std::string toString() const {
        auto timeT = std::chrono::system_clock::to_time_t(transactionDate);
        std::stringstream ss;
        ss << "\nTransaction:\n"
           << "type=" << type
           << ", amount=$" << std::fixed << std::setprecision(2) << amount
           << ", balance=$" << std::fixed << std::setprecision(2) << balance
           << ", description='" << description << '\''
           << ", transactionDate=" << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
};

// Account Class
class Account {
private:
    std::string ownerName;
    int id{0};
    double balance{0.0};
    double annualInterestRate{0.0}; // Stored as percentage e.g. 1.5 = 1.5%
    std::chrono::system_clock::time_point dateCreated;
    std::vector<Transaction> transactions;

public:
    Account() : dateCreated(std::chrono::system_clock::now()) {}
    Account(int newId, double newBalance)
        : id(newId), balance(newBalance), dateCreated(std::chrono::system_clock::now()) {
        if (newBalance < 0.0) {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
    }

    Account(std::string name, int accountId, double initialBalance)
        : ownerName(std::move(name)), id(accountId), balance(initialBalance),
          dateCreated(std::chrono::system_clock::now()) {
        if (initialBalance < 0.0) {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
    }

    virtual ~Account() = default;
    [[nodiscard]] std::string getOwnerName() const { return ownerName; }
    void setOwnerName(std::string name) { ownerName = std::move(name); }
    [[nodiscard]] int getId() const noexcept { return id; }
    void setId(int newId) noexcept { id = newId; }
    [[nodiscard]] double getBalance() const noexcept { return balance; }
    void setBalance(double newBalance) noexcept { balance = newBalance; }
    [[nodiscard]] double getAnnualInterestRate() const noexcept { return annualInterestRate; }
    void setAnnualInterestRate(double rate) noexcept { annualInterestRate = rate; }
    [[nodiscard]] std::chrono::system_clock::time_point getDateCreated() const noexcept {
        return dateCreated;
    }
    [[nodiscard]] const std::vector<Transaction>& getTransactions() const noexcept {
        return transactions;
    }
    [[nodiscard]] double getMonthlyInterestRate() const noexcept {
        return (annualInterestRate / 100.0) / 12.0;
    }

    [[nodiscard]] double getMonthlyInterest() const noexcept {
        return balance * getMonthlyInterestRate();
    }
    virtual void withdraw(double amount, const std::string& description = "Standard") {
        if (amount <= 0.0) {
            throw std::invalid_argument("Withdrawal amount must be greater than zero.");
        }
        if (balance - amount < 0.0) {
            throw std::runtime_error("Insufficient funds for withdrawal.");
        }
        balance -= amount;
        transactions.emplace_back(Transaction::WITHDRAWAL, amount, balance, description);
    }

    virtual void deposit(double amount, const std::string& description = "Standard") {
        if (amount <= 0.0) {
            throw std::invalid_argument("Deposit amount must be greater than zero.");
        }
        balance += amount;
        transactions.emplace_back(Transaction::DEPOSIT, amount, balance, description);
    }

    [[nodiscard]] virtual std::string toString() const {
        std::stringstream ss;
        ss << "Account Summary: \n"
           << "ownerName=" << ownerName
           << ", annualInterestRate=" << std::fixed << std::setprecision(2) << annualInterestRate << "%"
           << ", balance=$" << std::fixed << std::setprecision(2) << balance << "\n"
           << "Transactions:";

        for (const auto& tx : transactions) {
            ss << tx.toString();
        }
        return ss.str();
    }
};


// Main Driver Function
int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        Account testAccount("George", 1122, 1000.00);
        testAccount.setAnnualInterestRate(1.5);
        testAccount.deposit(30.00);
        testAccount.deposit(40.00);
        testAccount.deposit(50.00);
        testAccount.withdraw(5.00);
        testAccount.withdraw(4.00);
        testAccount.withdraw(2.00);
        std::cout << testAccount.toString() << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}