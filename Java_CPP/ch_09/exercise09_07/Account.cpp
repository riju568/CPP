#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <exception>


//__________________________UML DIAGRAM_____________________________*
/*																	|
 * 							  Account								|
 *-------------------------------------------------------------------|
 * 	-id : int														|
 * 																	|
 *  -balance : double												|
 * 																	|
 * 	-annualInterestRate : double									|
 * 																	|
 * 	-dateCreated : Date												|
 *-------------------------------------------------------------------|
 * 	 +Account()														|
 * 	 																|
 * 	 +Account(ID:int,balance: double)								|
 * 																	|
 * 	+getID() : int													|
 * 	 																|
 * 	+setID() : void													|
 * 																	|
 * 	+getBalance() : double											|
 * 																	|
 * 	+setBalance(balance:double) : void								|
 * 																	|
 * 	+getAnnualInterestRate() : double								|
 * 																	|
 * 	+setAnnualInterestRate(double: newInterestRate) : void 			|
 * 																	|
 * 	+getDateCreated() : Date										|
 * 																	|
 * 	+getMonthlyInterestRate(interestRatePerYear: double)		    |
 * 																	|
 * +getMonthlyInterest(InterestRatePerMonth:double,balance:double)   |
 * 																	|
 * 	+withdraw(amount: double, balance: double)						|
 * 																	|
 * 	+deposit(amount: double, balance: double)						|
 *___________________________________________________________________|  */


/**
 * Exercise 9.7 (The Account class) Design a class named Account that contains:
 * <p>
 * A private int data field named id for the account (default 0).
 * <p>
 * A private double data field named balance for the account (default 0).
 * <p>
 * A private double data field named annualInterestRate that stores the current interest rate
 * <p>
 * (default 0). Assume all accounts have the same interest rate.
 * <p>
 * A private Date data field named dateCreated that stores the date when the account was created.
 * <p>
 * A no-arg constructor that creates a default account.
 * <p>
 * A constructor that creates an account with the specified id and initial balance.
 * <p>
 * The accessor and mutator methods for id, balance, and annualInterestRate.
 * <p>
 * The accessor method for dateCreated.
 * <p>
 * A method named getMonthlyInterestRate() that returns the monthly interest rate.
 * <p>
 * A method named getMonthlyInterest() that returns the monthly interest.
 * <p>
 * A method named withdraw that withdraws a specified amount from the account.
 * <p>
 * A method named deposit that deposits a specified amount to the account.
 * <p>
 * Draw the UML diagram for the class and then implement the class.
 * (Hint: The method getMonthlyInterest() is to return monthly interest, not the interest rate.
 * Monthly interest is balance * monthlyInterestRate. monthlyInterestRate is annualInterestRate / 12.
 * Note that annualInterestRate is a percentage, e.g., like 4.5%. You need to divide it by 100.)
 * <p>
 * Write a test program that creates an Account object with an account ID of 1122, a balance of
 * $20,000, and an annual interest rate of 4.5%. Use the withdraw method to withdraw $2,500, use
 * the deposit method to deposit $3,000, and print the balance, the monthly interest, and the
 * date when this account was created.
 */


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
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        Account account(1122, 20000.0);
        account.setAnnualInterestRate(4.5);

        account.withdraw(2500.0);
        account.deposit(3000.0);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Balance: $" << account.getBalance() << '\n';
        std::cout << "Monthly interest: $" << account.getMonthlyInterest() << '\n';
        std::cout << "Date when this account was created: " << account.getDateCreated() << '\n';

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
