#pragma once
#include "Account.hpp"

using namespace std;

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accountNumber, double initialBalance, double overdraftLimit);
    double getOverdraftLimit() const;
    void withdraw(double amount) override;
};