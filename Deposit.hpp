#pragma once
#include "Transaction.hpp"

class Deposit : public Transaction {
public:
    Deposit(std::string id, double amount, std::shared_ptr<Account> account);
    void processTransaction() override;
};