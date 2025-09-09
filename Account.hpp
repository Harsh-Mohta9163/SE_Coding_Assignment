#pragma once
#include "helpers.hpp"

using namespace std;

// Forward declaration to resolve circular dependency
class Transaction; 
class Account; // Self-declaration for shared_ptr

class Account {
protected:
    string accountNumber; // Renamed for clarity from "account"
    double balance;
    vector<shared_ptr<Transaction>> transactions;

public:
    // Using a raw pointer for toAccount because ownership is not transferred here
    Account(string accNumber, double initialBalance);
    virtual ~Account() = default; // Virtual destructor for base class

    string getAccountNumber() const;
    double getBalance();
    
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    void transferFunds(shared_ptr<Account> toAccount, double amount);

    void addTransaction(shared_ptr<Transaction> t);
};
