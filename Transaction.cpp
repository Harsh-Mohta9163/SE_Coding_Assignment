#include "Transaction.hpp"

Transaction::Transaction(std::string id, double amount)
    : transactionId(id), fromAccount(nullptr), toAccount(nullptr), amt(amount) {
    this->timestamp = getCurrentTimestamp();
}

std::string Transaction::getTransactionId() const { return transactionId; }
std::shared_ptr<Account> Transaction::getFromAccount() const { return fromAccount; }
std::shared_ptr<Account> Transaction::getToAccount() const { return toAccount; }
double Transaction::getAmount() const { return amt; }
std::string Transaction::getTimestamp() const { return timestamp; }