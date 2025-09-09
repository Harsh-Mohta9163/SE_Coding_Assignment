#include "Withdrawal.hpp"

using namespace std;

Withdrawal::Withdrawal(string id, double amount, shared_ptr<Account> account)
    : Transaction(id, amount) {
    this->fromAccount = account; // A withdrawal comes "from" an account
}
void Withdrawal::processTransaction() {
    fromAccount->withdraw(amt);
}