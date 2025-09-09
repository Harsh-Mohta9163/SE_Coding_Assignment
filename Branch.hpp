#pragma once
#include "helpers.hpp"
#include "Account.hpp"
#include "Customer.hpp"

using namespace std;

class Branch {
private:
    string BranchID;
    string Location;
    vector<shared_ptr<Account>> accounts;

public:
    Branch(string id, string loc);
    string getLocation() const;
    void OpenAccount(shared_ptr<Account> account, shared_ptr<Customer> customer);
    void OpenJointAccount(shared_ptr<Account> account, vector<shared_ptr<Customer>> customers);
    void CloseAccount(shared_ptr<Account> account);
};