#include "Withdrawal.hpp"
Withdrawal::Withdrawal(std::string id, double amount, std::shared_ptr<Account> account)
    : Transaction(id, amount) {
    this->fromAccount = account; // A withdrawal comes "from" an account
}
void Withdrawal::processTransaction() {
    fromAccount->withdraw(amt);
}