#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>

/**
 * ***8.17 (Financial tsunami) Banks lend money to each other. In tough economic times,
 * if a bank goes bankrupt, it may not be able to pay back the loan. A bank’s
 * total assets are its current balance plus its loans to other banks. The diagram in
 * Figure 8.8 shows five banks. The banks’ current balances are 25, 125, 175, 75,
 * and 181 million dollars, respectively. The directed edge from node 1 to node 2
 * indicates that bank 1 lends 40 million dollars to bank 2.
 * <p>
 * If a bank’s total assets are under a certain limit, the bank is unsafe. The money it
 * borrowed cannot be returned to the lender, and the lender cannot count the loan in
 * its total assets. Consequently, the lender may also be unsafe, if its total assets are
 * under the limit.
 * <p>
 * Write a program to find all the unsafe banks. Your program reads
 * the input as follows. It first reads two integers n and limit, where n indicates the
 * number of banks and limit is the minimum total assets for keeping a bank safe. It
 * then reads n lines that describe the information for n banks with IDs from 0 to n-1.
 * <p>
 * The first number in the line is the bank’s balance, the second number indicates
 * the number of banks that borrowed money from the bank, and the rest are pairs
 * of two numbers. Each pair describes a borrower. The first number in the pair
 * is the borrower’s ID and the second is the amount borrowed. For example, the
 * input for the five banks in Figure 8.8 is as follows (note that the limit is 201):
 * <p>
 * 5 201                            -> n, limit
 * 25 2 1 100.5 4 320.5          -> bank 0's balance, number of loans, loan to bank 1, $100.5, loan to bank 4, $320.5
 * 125 2 2 40 3 85
 * 175 2 0 125 3 75
 * 75 1 0 125
 * 181 1 2 125
 * <p>
 * The total assets of bank 3 are (75 + 125), which is under 201, so bank 3 is
 * unsafe. After bank 3 becomes unsafe, the total assets of bank 1 fall below
 * (125 + 40). Thus, bank 1 is also unsafe.
 * <p>
 * The output of the program should be
 * Unsafe banks are 3 1
 * <p>
 * (Hint: Use a two-dimensional array borrowers to represent loans.
 * borrowers[i][j] indicates the loan that bank i loans to bank j. Once bank j
 * becomes unsafe, borrowers[i][j] should be set to 0.)
 * FIGURE 8.8 Banks lend money to each other.
 */


/**
 * Robust implementation of Exercise 08.17 (Financial Tsunami) with resource management,
 * corrected iterative safety evaluation loops, and input validation.
 */



void handleUnsafeBank(std::vector<std::vector<double>>& borrowers, int unsafeBankId) {
    for (size_t i = 0; i < borrowers.size(); ++i) {
        borrowers[i][unsafeBankId] = 0.0;
    }
}
std::vector<int> evaluateSafety(const std::vector<std::vector<double>>& banks, 
                               std::vector<std::vector<double>>& borrowers, 
                               double limit) {
    size_t n = banks.size();
    std::vector<int> unsafeBanks(n, 0);
    bool statusChanged;

    do {
        statusChanged = false;

        for (size_t i = 0; i < n; ++i) {
            if (unsafeBanks[i] == 1) {
                continue;
            }
            double assets = banks[i][0];
            for (size_t j = 0; j < borrowers[i].size(); ++j) {
                assets += borrowers[i][j];
            }
            if (assets < limit) {
                unsafeBanks[i] = 1;
                statusChanged = true;
                handleUnsafeBank(borrowers, static_cast<int>(i));
            }
        }
    } while (statusChanged); 

    return unsafeBanks;
}
std::vector<std::vector<double>> getBorrowers(const std::vector<std::vector<double>>& banks) {
    size_t n = banks.size();
    std::vector<std::vector<double>> borrowers(n, std::vector<double>(n, 0.0));

    for (size_t i = 0; i < n; ++i) {
        if (banks[i].size() < 2) continue;
        int numBorrowers = static_cast<int>(banks[i][1]);
        for (size_t x = 2; x < 2 + (numBorrowers * 2); x += 2) {
            if (x + 1 < banks[i].size()) {
                int borrowerId = static_cast<int>(banks[i][x]);
                double loanAmount = banks[i][x + 1];
                if (borrowerId >= 0 && static_cast<size_t>(borrowerId) < n) {
                    borrowers[i][borrowerId] = loanAmount;
                }
            }
        }
    }
    return borrowers;
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::cout << "Enter n (number of banks) and limit (asset threshold):\n";
        int n = 0;
        double limit = 0.0;
        if (!(std::cin >> n >> limit)) {
            std::cerr << "Error: Invalid integer/limit input format.\n";
            return EXIT_FAILURE;
        }

        if (n <= 0) {
            std::cerr << "Error: Number of banks must be greater than zero.\n";
            return EXIT_FAILURE;
        }

        std::cin.ignore(); 

        std::vector<std::vector<double>> banks(n);
        std::cout << "Enter information for the " << n << " banks:\n";

        for (int i = 0; i < n; ++i) {
            std::string line;
            if (!std::getline(std::cin, line)) {
                std::cerr << "Error: Failed to read bank line input.\n";
                return EXIT_FAILURE;
            }

            std::stringstream ss(line);
            double val = 0.0;
            std::vector<double> bankData;
            while (ss >> val) {
                bankData.push_back(val);
            }
            banks[i] = bankData;
        }

        std::vector<std::vector<double>> borrowers = getBorrowers(banks);
        std::vector<int> unsafeBanks = evaluateSafety(banks, borrowers, limit);

        std::cout << "Unsafe banks: ";
        bool foundUnsafe = false;
        for (size_t i = 0; i < unsafeBanks.size(); ++i) {
            if (unsafeBanks[i] == 1) {
                std::cout << i << " ";
                foundUnsafe = true;
            }
        }
        if (!foundUnsafe) {
            std::cout << "None";
        }
        std::cout << '\n';

        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Validation Error: " << e.what() << '\n';
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