#include "Transaction.hpp"

using namespace std;

Transaction::Transaction(string id, double amount)
    : transactionId(id), fromAccount(nullptr), toAccount(nullptr), amt(amount) {
    this->timestamp = getCurrentTimestamp();
}

string Transaction::getTransactionId() const { return transactionId; }
shared_ptr<Account> Transaction::getFromAccount() const { return fromAccount; }
shared_ptr<Account> Transaction::getToAccount() const { return toAccount; }
double Transaction::getAmount() const { return amt; }
string Transaction::getTimestamp() const { return timestamp; }