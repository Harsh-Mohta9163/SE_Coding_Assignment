#include "helpers.hpp"
#include "Bank.hpp"
#include "Customer.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"
#include "Deposit.hpp"
#include "Withdrawal.hpp"
#include "Transfer.hpp"

int main() {
    std::cout << "--- Banking System Demo Start ---" << std::endl;

    // 1. Create a Bank
    auto myBank = std::make_shared<Bank>("HDFC Bank");
    std::cout << "Welcome to " << myBank->getBankName() << std::endl;

    // 2. Create multiple Branches (1:N Bank-Branch relationship)
    auto branch1 = std::make_shared<Branch>("B001", "Electronic City");
    auto branch2 = std::make_shared<Branch>("B002", "Silk Board");
    myBank->addBranch(branch1);
    myBank->addBranch(branch2);
    std::cout << "\n----------------------------------\n" << std::endl;

    // 3. Create a Customer
    auto customer1 = std::make_shared<Customer>("Harsh", "pass123", "9163729901", "harsh@email.com");
    customer1->registerUser();
    customer1->login();
    std::cout << "\n----------------------------------\n" << std::endl;

    // 4. Open multiple accounts for the customer (1:N Customer-Account relationship)
    auto sa1 = std::make_shared<SavingsAccount>("SA1001", 5000.0, 2.5);
    auto ca1 = std::make_shared<CheckingAccount>("CA2001", 1000.0, 500.0);
    
    branch1->OpenAccount(sa1, customer1);
    branch1->OpenAccount(ca1, customer1);
    
    std::cout << customer1->getUsername() << " has " << customer1->getAccountCount() << " accounts." << std::endl;
    std::cout << "\n----------------------------------\n" << std::endl;

    // 5. Demonstrate method calls and transactions
    std::cout << "--- Performing Transactions ---" << std::endl;
    
    // a. Deposit into Savings Account
    auto deposit1 = std::make_shared<Deposit>("TXN001", 1500.0, sa1);
    std::cout << "\nProcessing Deposit Txn: " << deposit1->getTransactionId() << " at " << deposit1->getTimestamp() << std::endl;
    deposit1->processTransaction();
    sa1->getBalance();

    // b. Withdraw from Checking Account
    auto withdrawal1 = std::make_shared<Withdrawal>("TXN002", 200.0, ca1);
    std::cout << "\nProcessing Withdrawal Txn: " << withdrawal1->getTransactionId() << " at " << withdrawal1->getTimestamp() << std::endl;
    withdrawal1->processTransaction();
    ca1->getBalance();
    
    // c. Transfer funds from Savings to Checking
    auto transfer1 = std::make_shared<Transfer>("TXN003", 1000.0, sa1, ca1);
    std::cout << "\nProcessing Transfer Txn: " << transfer1->getTransactionId() << " at " << transfer1->getTimestamp() << std::endl;
    transfer1->processTransaction();
    sa1->getBalance();
    ca1->getBalance();
    
    // d. Attempt to withdraw more than balance + overdraft
    std::cout << "\nAttempting to overdraw from checking account..." << std::endl;
    ca1->withdraw(2500.0);
    ca1->getBalance();
    
    // e. Call a subclass-specific method
    std::cout << "\nApplying interest to savings account..." << std::endl;
    std::cout << "Interest rate is: " << sa1->getInterestRate() << "%" << std::endl;
    // applyInterest already calls deposit, so we call it directly.
    sa1->applyInterest(); 
    sa1->getBalance();

    std::cout << "\n----------------------------------\n" << std::endl;
    customer1->logout();
    std::cout << "--- Banking System Demo End ---" << std::endl;

    return 0;
}