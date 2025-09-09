#include "Transfer.hpp"
Transfer::Transfer(std::string id, double amount, std::shared_ptr<Account> from, std::shared_ptr<Account> to)
    : Transaction(id, amount) {
    this->fromAccount = from;
    this->toAccount = to;
}
void Transfer::processTransaction() {
    fromAccount->transferFunds(toAccount, amt);
}