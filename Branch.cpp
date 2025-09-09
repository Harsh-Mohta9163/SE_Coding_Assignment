#include "Branch.hpp"

Branch::Branch(std::string id, std::string loc) : BranchID(id), Location(loc) {}
std::string Branch::getLocation() const { return Location; }

void Branch::OpenAccount(std::shared_ptr<Account> account, std::shared_ptr<Customer> customer) {
    this->accounts.push_back(account);
    customer->addAccount(account);
    std::cout << "New account with A/C No: " << account->getAccountNumber() 
              << " opened for customer " << customer->getUsername() 
              << " at " << this->Location << " branch." << std::endl;
}
void Branch::CloseAccount(std::shared_ptr<Account> account) {
    std::cout << "Account " << account->getAccountNumber() << " closed." << std::endl;
    // Logic to remove account from vector would go here
}