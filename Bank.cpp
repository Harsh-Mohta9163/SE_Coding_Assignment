#include "Bank.hpp"
Bank::Bank(std::string name) : bankName(name) {}
std::string Bank::getBankName() const { return bankName; }
void Bank::addBranch(std::shared_ptr<Branch> branch) {
    branches.push_back(branch);
    std::cout << "New branch added at " << branch->getLocation() << std::endl;
}