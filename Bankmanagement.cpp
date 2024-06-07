
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
public:
    Account(int accNumber, string accHolder, double balance)
        : accountNumber(accNumber), accountHolder(accHolder), balance(balance) {}

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << "\nAccount Holder: " << accountHolder
             << "\nBalance: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

private:
    int accountNumber;
    string accountHolder;
    double balance;
};

class Bank {
public:
    void addAccount(const Account& account) {
        accounts.push_back(account);
        cout << "Account added successfully." << endl;
    }

    void displayAllAccounts() const {
        for (const auto& account : accounts) {
            account.displayAccountInfo();
            cout << "------------------------\n";
        }
    }

private:
    vector<Account> accounts;
};

int main() {
    Bank bank;

    // Example: Creating and adding accounts
    Account account1(1001, "John Doe", 5000.0);
    Account account2(1002, "Jane Smith", 7500.0);

    bank.addAccount(account1);
    bank.addAccount(account2);

    // Example: Displaying all accounts
    cout << "All Accounts:\n";
    bank.displayAllAccounts();

    // Example: Making a deposit and a withdrawal
    account1.deposit(1000.0);
    account2.withdraw(2000.0);

    // Display updated account information
    cout << "\nUpdated Account Information:\n";
    bank.displayAllAccounts();

    return 0;
}

