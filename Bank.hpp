#pragma once
#include "helpers.hpp"
#include "Branch.hpp"

using namespace std;

class Bank {
private:
    string bankName;
    vector<shared_ptr<Branch>> branches;
public:
    Bank(string name);
    void addBranch(shared_ptr<Branch> branch);
    string getBankName() const;
};