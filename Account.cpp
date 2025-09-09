#include "Account.hpp"
#include "Transaction.hpp" // Full include here

Account::Account(std::string accNumber, double initialBalance)
    : accountNumber(accNumber), balance(initialBalance) {}

std::string Account::getAccountNumber() const {
    return this->accountNumber;
}

double Account::getBalance() {
    std::cout << "Balance for A/C " << this->accountNumber << ": $" 
              << std::fixed << std::setprecision(2) << this->balance << std::endl;
    return this->balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        this->balance += amount;
        std::cout << "Deposited $" << std::fixed << std::setprecision(2) << amount
                  << " to A/C " << this->accountNumber << ". New Balance: $" 
                  << this->balance << std::endl;
    } else {
        std::cout << "Deposit amount must be positive." << std::endl;
    }
}

void Account::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Withdrawal amount must be positive." << std::endl;
    } else if (this->balance >= amount) {
        this->balance -= amount;
        std::cout << "Withdrew $" << std::fixed << std::setprecision(2) << amount
                  << " from A/C " << this->accountNumber << ". New Balance: $" 
                  << this->balance << std::endl;
    } else {
        std::cout << "Insufficient funds for withdrawal from A/C " << this->accountNumber << std::endl;
    }
}

void Account::transferFunds(std::shared_ptr<Account> toAccount, double amount) {
    if (this->balance >= amount) {
        // Here we call the virtual withdraw/deposit methods
        this->withdraw(amount);
        toAccount->deposit(amount);
        std::cout << "Successfully transferred $" << std::fixed << std::setprecision(2) << amount
                  << " from A/C " << this->accountNumber << " to A/C " << toAccount->getAccountNumber() << std::endl;
    } else {
        std::cout << "Transfer failed due to insufficient funds in A/C " << this->accountNumber << std::endl;
    }
}

void Account::addTransaction(std::shared_ptr<Transaction> t) {
    this->transactions.push_back(t);
}