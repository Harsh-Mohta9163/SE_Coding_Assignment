#pragma once
#include "Transaction.hpp"

class Transfer : public Transaction {
public:
    Transfer(std::string id, double amount, std::shared_ptr<Account> from, std::shared_ptr<Account> to);
    void processTransaction() override;
};