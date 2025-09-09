#pragma once
#include "helpers.hpp"
#include "Account.hpp"

using namespace std;

class Customer {
private:
    string username;
    string password;
    string phone;
    string email;
    vector<shared_ptr<Account>> accounts;

public:
    Customer(string user, string pass, string ph, string mail);
    
    string getUsername() const;
    void addAccount(shared_ptr<Account> account);
    size_t getAccountCount() const;

    void registerUser();
    void login();
    void logout();
    void resetPassword();
};