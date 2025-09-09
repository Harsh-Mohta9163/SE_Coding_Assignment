#include "FD.hpp"

using namespace std;

FD::FD(string accountNumber, double minBalance)
    : Account(accountNumber, minBalance), MinBalance(minBalance) {}

double FD::getMinBalance() const {
    return this->MinBalance;
}

void FD::withdraw(double amount) {
    cout << "Withdrawals are not allowed from a Fixed Deposit account." << endl;
}