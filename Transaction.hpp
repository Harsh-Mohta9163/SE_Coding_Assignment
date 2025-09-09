#pragma once
#include "helpers.hpp"
#include "Account.hpp" // Full include here

class Transaction {
protected:
    // Corrected attribute names
    std::string transactionId;
    std::shared_ptr<Account> fromAccount;
    std::shared_ptr<Account> toAccount;
    double amt;
    std::string timestamp;

public:
    Transaction(std::string id, double amount);
    virtual ~Transaction() = default;

    std::string getTransactionId() const;
    std::shared_ptr<Account> getFromAccount() const;
    std::shared_ptr<Account> getToAccount() const;
    double getAmount() const;
    std::string getTimestamp() const;

    virtual void processTransaction() = 0; // Pure virtual function
};