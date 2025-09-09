#pragma once
#include "Transaction.hpp"

using namespace std;

class Withdrawal : public Transaction {
public:
    Withdrawal(string id, double amount, shared_ptr<Account> account);
    void processTransaction() override;
};