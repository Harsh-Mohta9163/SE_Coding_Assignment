#include "CheckingAccount.hpp"

using namespace std;

CheckingAccount::CheckingAccount(string accountNumber, double initialBalance, double limit)
    : Account(accountNumber, initialBalance), overdraftLimit(limit) {}

double CheckingAccount::getOverdraftLimit() const {
    return this->overdraftLimit;
}

void CheckingAccount::withdraw(double amount) {
    if (amount > 0 && (balance + overdraftLimit) >= amount) {
        balance -= amount;
        cout << "Withdrew Rs." << fixed << setprecision(2) << amount 
                  << " from Checking A/C " << getAccountNumber() << ". New Balance: Rs." 
                  << balance << endl;
    } else {
        cout << "Withdrawal failed. Amount exceeds funds and overdraft limit for A/C " 
                  << getAccountNumber() << endl;
    }
}
