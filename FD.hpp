#pragma once
#include "Account.hpp"

using namespace std;

class FD : public Account {
private:
    // Changed MinBalance from String to double for practical use
    double MinBalance;

public:
    FD(string accountNumber, double minBalance);
    double getMinBalance() const;
    void withdraw(double amount) override;
};