#pragma once
#include "Transaction.hpp"

using namespace std;

class Transfer : public Transaction {
public:
    Transfer(string id, double amount, shared_ptr<Account> from, shared_ptr<Account> to);
    void processTransaction() override;
};