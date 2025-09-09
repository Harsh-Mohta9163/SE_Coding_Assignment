#include "Transfer.hpp"

using namespace std;

Transfer::Transfer(string id, double amount, shared_ptr<Account> from, shared_ptr<Account> to)
    : Transaction(id, amount) {
    this->fromAccount = from;
    this->toAccount = to;
}
void Transfer::processTransaction() {
    fromAccount->transferFunds(toAccount, amt);
}