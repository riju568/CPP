#include <iostream>
#include <array>
#include <iomanip>
#include <limits>
#include <exception>
#include <cstdlib>

/**
 * 10.7 (Game: ATM machine) Use the Account class created in
 * Programming Exercise 9.7 to simulate an ATM machine.
 * Create ten accounts in an array with id 0, 1, . . . , 9,
 * and initial balance $100. The system prompts the user to
 * enter an id. If the id is entered incorrectly, ask the user
 * to enter a correct id. Once an id is accepted, the main menu
 * is displayed as shown in the sample run. You can enter a choice
 * 1 for viewing the current balance, 2 for withdrawing money, 3 for
 * depositing money, and 4 for exiting the main menu. Once you exit,
 * the system will prompt for an id again. Thus, once the system
 * starts, it will not stop. */
class Account
{
private:
    int id;
    double balance;

public:
    Account() noexcept : id(0), balance(0.0) {}
    Account(int id, double balance) noexcept : id(id), balance(balance) {}

    [[nodiscard]] int get_id() const noexcept { return id; }
    [[nodiscard]] double get_balance() const noexcept { return balance; }

    void withdraw(double amount) noexcept
    {
        if (amount > 0 && amount <= balance) balance -= amount;
    }

    void deposit(double amount) noexcept
    {
        if (amount > 0) balance += amount;
    }
};

// Helper function to safely read integer input
static bool read_int(int &value)
{
    if (std::cin >> value) return true;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}
static void execute_command(int command, int acc_id, std::array<Account, 10> &accounts)
{
    switch (command)
    {
    case 1:
        std::cout << "The balance in account " << acc_id 
                  << " is $" << std::fixed << std::setprecision(2) 
                  << accounts[acc_id].get_balance() << "\n\n";
        break;

    case 2:
    {
        std::cout << "Enter the amount you want to withdraw: ";
        double amount;
        if (std::cin >> amount) accounts[acc_id].withdraw(amount);
        std::cout << '\n';
        break;
    }

    case 3:
    {
        std::cout << "Enter the amount you want to deposit: ";
        double amount;
        if (std::cin >> amount) accounts[acc_id].deposit(amount);
        std::cout << '\n';
        break;
    }

    default:
        break;
    }
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::array<Account, 10> atm_accounts;
        for (int i = 0; i < 10; ++i)
        {
            atm_accounts[i] = Account(i, 100.00);
        }

        while (true)
        {
            std::cout << "Please enter an account ID#: ";
            int id_of_acc;

            if (!read_int(id_of_acc)) continue;
            if (id_of_acc == 1234) break; // Exit system code

            while (id_of_acc < 0 || id_of_acc > 9)
            {
                std::cout << "Incorrect ID#, please enter a correct ID#: ";
                if (!read_int(id_of_acc)) continue;
                if (id_of_acc == 1234) goto exit_system;
            }

            int user_input = 0;
            while (user_input != 4)
            {
                std::cout << "\nMain Menu\n"
                          << "1: Check Balance\n"
                          << "2: Withdraw\n"
                          << "3: Deposit\n"
                          << "4: Exit\n"
                          << "Enter a choice now: ";

                if (!read_int(user_input)) continue;

                if (user_input >= 1 && user_input <= 3)
                {
                    execute_command(user_input, id_of_acc, atm_accounts);
                }
            }
            std::cout << '\n';
        }

    exit_system:
        std::cout << "ATM System Shutdown.\n";
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}