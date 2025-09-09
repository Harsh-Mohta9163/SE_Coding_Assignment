#pragma once
#include "helpers.hpp"
#include "Account.hpp" // Full include here

using namespace std;

class Transaction {
protected:
    // Corrected attribute names
    string transactionId;
    shared_ptr<Account> fromAccount;
    shared_ptr<Account> toAccount;
    double amt;
    string timestamp;

public:
    Transaction(string id, double amount);
    virtual ~Transaction() = default;

    string getTransactionId() const;
    shared_ptr<Account> getFromAccount() const;
    shared_ptr<Account> getToAccount() const;
    double getAmount() const;
    string getTimestamp() const;

    virtual void processTransaction() = 0; // Pure virtual function
};