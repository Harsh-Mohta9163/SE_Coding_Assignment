#include "CheckingAccount.hpp"

CheckingAccount::CheckingAccount(std::string accountNumber, double initialBalance, double limit)
    : Account(accountNumber, initialBalance), overdraftLimit(limit) {}

double CheckingAccount::getOverdraftLimit() const {
    return this->overdraftLimit;
}

void CheckingAccount::withdraw(double amount) {
    if (amount > 0 && (balance + overdraftLimit) >= amount) {
        balance -= amount;
        std::cout << "Withdrew $" << std::fixed << std::setprecision(2) << amount 
                  << " from Checking A/C " << getAccountNumber() << ". New Balance: $" 
                  << balance << std::endl;
    } else {
        std::cout << "Withdrawal failed. Amount exceeds funds and overdraft limit for A/C " 
                  << getAccountNumber() << std::endl;
    }
}
