#include "Account.hpp"
#include "Transaction.hpp" // Full include here

using namespace std;

Account::Account(string accNumber, double initialBalance)
    : accountNumber(accNumber), balance(initialBalance) {}

string Account::getAccountNumber() const {
    return this->accountNumber;
}

double Account::getBalance() {
    cout << "Balance for A/C " << this->accountNumber << ": Rs." 
              << fixed << setprecision(2) << this->balance << endl;
    return this->balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        this->balance += amount;
        cout << "Deposited Rs." << fixed << setprecision(2) << amount
                  << " to A/C " << this->accountNumber << ". New Balance: Rs." 
                  << this->balance << endl;
    } else {
        cout << "Deposit amount must be positive." << endl;
    }
}

void Account::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Withdrawal amount must be positive." << endl;
    } else if (this->balance >= amount) {
        this->balance -= amount;
        cout << "Withdrew Rs." << fixed << setprecision(2) << amount
                  << " from A/C " << this->accountNumber << ". New Balance: Rs." 
                  << this->balance << endl;
    } else {
        cout << "Insufficient funds for withdrawal from A/C " << this->accountNumber << endl;
    }
}

void Account::transferFunds(shared_ptr<Account> toAccount, double amount) {
    if (this->balance >= amount) {
        // Here we call the virtual withdraw/deposit methods
        this->withdraw(amount);
        toAccount->deposit(amount);
        cout << "Successfully transferred Rs." << fixed << setprecision(2) << amount
                  << " from A/C " << this->accountNumber << " to A/C " << toAccount->getAccountNumber() << endl;
    } else {
        cout << "Transfer failed due to insufficient funds in A/C " << this->accountNumber << endl;
    }
}

void Account::addTransaction(shared_ptr<Transaction> t) {
    this->transactions.push_back(t);
}