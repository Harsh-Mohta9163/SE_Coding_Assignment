#include "FD.hpp"

FD::FD(std::string accountNumber, double minBalance)
    : Account(accountNumber, minBalance), MinBalance(minBalance) {}

double FD::getMinBalance() const {
    return this->MinBalance;
}

void FD::withdraw(double amount) {
    std::cout << "Withdrawals are not allowed from a Fixed Deposit account." << std::endl;
}