#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(std::string accountNumber, double initialBalance, double rate)
    : Account(accountNumber, initialBalance), interestRate(rate) {}

double SavingsAccount::getInterestRate() const {
    return this->interestRate;
}

void SavingsAccount::applyInterest() {
    double interest = balance * interestRate / 100.0;
    deposit(interest);
    std::cout << "Applied interest of $" << std::fixed << std::setprecision(2) << interest 
              << " to Savings Account " << getAccountNumber() << std::endl;
}