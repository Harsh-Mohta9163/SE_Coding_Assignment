#include "Customer.hpp"

Customer::Customer(std::string user, std::string pass, std::string ph, std::string mail)
    : username(user), password(pass), phone(ph), email(mail) {}

std::string Customer::getUsername() const { return username; }
void Customer::addAccount(std::shared_ptr<Account> account) { accounts.push_back(account); }
size_t Customer::getAccountCount() const { return accounts.size(); }

void Customer::registerUser() { std::cout << "Customer " << username << " registered successfully." << std::endl; }
void Customer::login() { std::cout << "Customer " << username << " logged in." << std::endl; }
void Customer::logout() { std::cout << "Customer " << username << " logged out." << std::endl; }
void Customer::resetPassword() { std::cout << "Password reset instructions sent to " << email << std::endl; }