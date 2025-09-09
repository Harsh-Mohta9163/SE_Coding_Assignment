#pragma once
#include "helpers.hpp"

// Forward declaration to resolve circular dependency
class Transaction; 
class Account; // Self-declaration for shared_ptr

class Account {
protected:
    std::string accountNumber; // Renamed for clarity from "account"
    double balance;
    std::vector<std::shared_ptr<Transaction>> transactions;

public:
    // Using a raw pointer for toAccount because ownership is not transferred here
    Account(std::string accNumber, double initialBalance);
    virtual ~Account() = default; // Virtual destructor for base class

    std::string getAccountNumber() const;
    double getBalance();
    
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    void transferFunds(std::shared_ptr<Account> toAccount, double amount);

    void addTransaction(std::shared_ptr<Transaction> t);
};
