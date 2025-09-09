#pragma once
#include "helpers.hpp"

using namespace std;

// Forward declaration to resolve circular dependency
class Transaction; 
class Account; // Self-declaration for shared_ptr
class Customer; // Forward declaration for Customer

class Account {
protected:
    string accountNumber; // Renamed for clarity from "account"
    double balance;
    vector<shared_ptr<Transaction>> transactions;
    vector<shared_ptr<Customer>> accountHolders; // Multiple customers for joint accounts

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
    
    // Joint account functionality
    void addAccountHolder(shared_ptr<Customer> customer);
    vector<shared_ptr<Customer>> getAccountHolders() const;
    bool isJointAccount() const;
    string getAccountHolderNames() const;
};
