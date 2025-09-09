#include "Customer.hpp"

using namespace std;

Customer::Customer(string user, string pass, string ph, string mail)
    : username(user), password(pass), phone(ph), email(mail) {}

string Customer::getUsername() const { return username; }
void Customer::addAccount(shared_ptr<Account> account) { accounts.push_back(account); }
size_t Customer::getAccountCount() const { return accounts.size(); }

void Customer::registerUser() { cout << "Customer " << username << " registered successfully." << endl; }
void Customer::login() { cout << "Customer " << username << " logged in." << endl; }
void Customer::logout() { cout << "Customer " << username << " logged out." << endl; }
void Customer::resetPassword() { cout << "Password reset instructions sent to " << email << endl; }