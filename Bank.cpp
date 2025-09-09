#include "Bank.hpp"

using namespace std;

Bank::Bank(string name) : bankName(name) {}
string Bank::getBankName() const { return bankName; }
void Bank::addBranch(shared_ptr<Branch> branch) {
    branches.push_back(branch);
    cout << "New branch added at " << branch->getLocation() << endl;
}