#pragma once
#include "helpers.hpp"
#include "Account.hpp"
#include "Customer.hpp"

class Branch {
private:
    std::string BranchID;
    std::string Location;
    std::vector<std::shared_ptr<Account>> accounts;

public:
    Branch(std::string id, std::string loc);
    std::string getLocation() const;
    void OpenAccount(std::shared_ptr<Account> account, std::shared_ptr<Customer> customer);
    void CloseAccount(std::shared_ptr<Account> account);
};