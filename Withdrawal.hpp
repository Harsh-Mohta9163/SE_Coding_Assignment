#pragma once
#include "Transaction.hpp"

class Withdrawal : public Transaction {
public:
    Withdrawal(std::string id, double amount, std::shared_ptr<Account> account);
    void processTransaction() override;
};