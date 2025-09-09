#pragma once
#include "helpers.hpp"
#include "Account.hpp"

class Customer {
private:
    std::string username;
    std::string password;
    std::string phone;
    std::string email;
    std::vector<std::shared_ptr<Account>> accounts;

public:
    Customer(std::string user, std::string pass, std::string ph, std::string mail);
    
    std::string getUsername() const;
    void addAccount(std::shared_ptr<Account> account);
    size_t getAccountCount() const;

    void registerUser();
    void login();
    void logout();
    void resetPassword();
};