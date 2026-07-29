#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <exception>

class Date {
private:
    std::time_t rawTime;

public:
    Date() {
        rawTime = std::time(nullptr);
    }

    std::string toString() const {
        std::tm* timeInfo = std::localtime(&rawTime);
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%c", timeInfo);
        return std::string(buffer);
    }
};

class Account {
private:
    int id;
    double balance;
    double annualInterestRate;
    Date dateCreated;

public:
    Account() {
        id = 0;
        balance = 0.0;
        annualInterestRate = 0.0;
    }

    Account(int newId, double newBalance) {
        this->id = newId;
        this->balance = newBalance;
        this->annualInterestRate = 0.0;
    }

    int getID() const {
        return id;
    }

    void setID(int newID) {
        this->id = newID;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double newBalance) {
        this->balance = newBalance;
    }

    double getAnnualInterestRate() const {
        return annualInterestRate;
    }

    void setAnnualInterestRate(double newInterestRate) {
        this->annualInterestRate = newInterestRate;
    }

    std::string getDateCreated() const {
        return dateCreated.toString();
    }

    double getMonthlyInterestRate() const {
        return (annualInterestRate / 12.0);
    }

    double getMonthlyInterest() const {
        return balance * (this->getMonthlyInterestRate() / 100.0);
    }

    void withdraw(double amount) {
        balance -= amount;
    }

    void deposit(double amountDeposit) {
        balance += amountDeposit;
    }

    std::string toString() const {
        return "\nAccount ID: " + std::to_string(getID()) + 
               "\nBalance: " + std::to_string(getBalance()) +
               "\nDate created " + getDateCreated();
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        Account obj(1122, 20000.0);
        obj.setAnnualInterestRate(4.5);
        obj.withdraw(2500.0);
        obj.deposit(3000.0);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "The balance in account " << obj.getID() << " is now: $" << obj.getBalance() << '\n';
        std::cout << "The total interest, at a rate of " << obj.getMonthlyInterestRate() << "%"
                  << " per month is " << obj.getMonthlyInterest() << '\n';
        std::cout << "And your account was created on " << obj.getDateCreated() << '\n';

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