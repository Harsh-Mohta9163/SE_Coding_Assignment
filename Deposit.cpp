#include "Deposit.hpp"

using namespace std;

Deposit::Deposit(string id, double amount, shared_ptr<Account> account)
    : Transaction(id, amount) {
    this->toAccount = account; // A deposit "goes to" an account
}
void Deposit::processTransaction() {
    toAccount->deposit(amt);
    // In a real system, we'd pass `shared_from_this()` but for this demo, this is simpler.
    // toAccount->addTransaction(make_shared<Deposit>(*this));
}