#pragma once
#include "Account.hpp"

class FD : public Account {
private:
    // Changed MinBalance from String to double for practical use
    double MinBalance;

public:
    FD(std::string accountNumber, double minBalance);
    double getMinBalance() const;
    void withdraw(double amount) override;
};