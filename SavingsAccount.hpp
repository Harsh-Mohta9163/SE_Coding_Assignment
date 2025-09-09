#pragma once
#include "Account.hpp"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(std::string accountNumber, double initialBalance, double interestRate);
    double getInterestRate() const;
    void applyInterest();
};