#pragma once
#include "Account.hpp"

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(std::string accountNumber, double initialBalance, double overdraftLimit);
    double getOverdraftLimit() const;
    void withdraw(double amount) override;
};