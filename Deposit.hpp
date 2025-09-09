#pragma once
#include "Transaction.hpp"

using namespace std;

class Deposit : public Transaction {
public:
    Deposit(string id, double amount, shared_ptr<Account> account);
    void processTransaction() override;
};