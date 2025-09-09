#include "Deposit.hpp"
Deposit::Deposit(std::string id, double amount, std::shared_ptr<Account> account)
    : Transaction(id, amount) {
    this->toAccount = account; // A deposit "goes to" an account
}
void Deposit::processTransaction() {
    toAccount->deposit(amt);
    // In a real system, we'd pass `shared_from_this()` but for this demo, this is simpler.
    // toAccount->addTransaction(std::make_shared<Deposit>(*this));
}