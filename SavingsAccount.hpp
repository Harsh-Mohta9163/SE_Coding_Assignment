#pragma once
#include "Account.hpp"

using namespace std;

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string accountNumber, double initialBalance, double interestRate);
    double getInterestRate() const;
    void applyInterest();
};