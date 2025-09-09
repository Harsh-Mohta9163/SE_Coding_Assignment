#pragma once
#include "helpers.hpp"
#include "Branch.hpp"

class Bank {
private:
    std::string bankName;
    std::vector<std::shared_ptr<Branch>> branches;
public:
    Bank(std::string name);
    void addBranch(std::shared_ptr<Branch> branch);
    std::string getBankName() const;
};