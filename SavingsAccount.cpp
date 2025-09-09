#include "SavingsAccount.hpp"

using namespace std;

SavingsAccount::SavingsAccount(string accountNumber, double initialBalance, double rate)
    : Account(accountNumber, initialBalance), interestRate(rate) {}

double SavingsAccount::getInterestRate() const {
    return this->interestRate;
}

void SavingsAccount::applyInterest() {
    double interest = balance * interestRate / 100.0;
    deposit(interest);
    cout << "Applied interest of Rs." << fixed << setprecision(2) << interest 
              << " to Savings Account " << getAccountNumber() << endl;
}