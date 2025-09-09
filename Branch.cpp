#include "Branch.hpp"

using namespace std;

Branch::Branch(string id, string loc) : BranchID(id), Location(loc) {}
string Branch::getLocation() const { return Location; }

void Branch::OpenAccount(shared_ptr<Account> account, shared_ptr<Customer> customer) {
    this->accounts.push_back(account);
    customer->addAccount(account);
    account->addAccountHolder(customer);
    cout << "New account with A/C No: " << account->getAccountNumber() 
              << " opened for customer " << customer->getUsername() 
              << " at " << this->Location << " branch." << endl;
}

void Branch::OpenJointAccount(shared_ptr<Account> account, vector<shared_ptr<Customer>> customers) {
    this->accounts.push_back(account);
    
    // Add account to all customers and add all customers as account holders
    for (auto customer : customers) {
        customer->addAccount(account);
        account->addAccountHolder(customer);
    }
    
    cout << "New joint account with A/C No: " << account->getAccountNumber() 
              << " opened for customers " << account->getAccountHolderNames()
              << " at " << this->Location << " branch." << endl;
}
void Branch::CloseAccount(shared_ptr<Account> account) {
    cout << "Account " << account->getAccountNumber() << " closed." << endl;
    // Logic to remove account from vector would go here
}