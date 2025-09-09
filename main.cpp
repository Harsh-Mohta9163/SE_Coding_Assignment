#include "helpers.hpp"
#include "Bank.hpp"
#include "Customer.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"
#include "Deposit.hpp"
#include "Withdrawal.hpp"
#include "Transfer.hpp"

using namespace std;

int main() {
    cout << "--- Banking System Demo Start ---" << endl;

    // 1. Create a Bank
    auto myBank = make_shared<Bank>("HDFC Bank");
    cout << "Welcome to " << myBank->getBankName() << endl;

    // 2. Create multiple Branches (1:N Bank-Branch relationship)
    auto branch1 = make_shared<Branch>("B001", "Electronic City");
    auto branch2 = make_shared<Branch>("B002", "Silk Board");
    myBank->addBranch(branch1);
    myBank->addBranch(branch2);
    cout << "\n----------------------------------\n" << endl;

    // 3. Create Customers
    auto customer1 = make_shared<Customer>("Harsh", "pass123", "9163729901", "harsh@email.com");
    customer1->registerUser();
    customer1->login();
    
    // Create a second customer
    auto customer2 = make_shared<Customer>("Priya", "pass456", "9876543210", "priya@email.com");
    customer2->registerUser();
    customer2->login();
    cout << "\n----------------------------------\n" << endl;

    // 4. Open multiple accounts for customer1 (1:N Customer-Account relationship)
    auto sa1 = make_shared<SavingsAccount>("SA1001", 5000.0, 2.5);
    auto ca1 = make_shared<CheckingAccount>("CA2001", 1000.0, 500.0);
    
    branch1->OpenAccount(sa1, customer1);
    branch1->OpenAccount(ca1, customer1);
    
    // Open accounts for customer2
    auto sa2 = make_shared<SavingsAccount>("SA2001", 3000.0, 2.5);
    auto ca2 = make_shared<CheckingAccount>("CA3001", 800.0, 300.0);
    
    branch2->OpenAccount(sa2, customer2);
    branch2->OpenAccount(ca2, customer2);
    
    cout << customer1->getUsername() << " has " << customer1->getAccountCount() << " accounts." << endl;
    cout << customer2->getUsername() << " has " << customer2->getAccountCount() << " accounts." << endl;
    cout << "\n----------------------------------\n" << endl;

    // 5. Demonstrate method calls and transactions (for Customer 1 only)
    cout << "--- Performing Transactions for " << customer1->getUsername() << " ---" << endl;
    
    // a. Deposit into Savings Account
    auto deposit1 = make_shared<Deposit>("TXN001", 1500.0, sa1);
    cout << "\nProcessing Deposit Txn: " << deposit1->getTransactionId() << " at " << deposit1->getTimestamp() << endl;
    deposit1->processTransaction();
    sa1->getBalance();

    // b. Withdraw from Checking Account
    auto withdrawal1 = make_shared<Withdrawal>("TXN002", 200.0, ca1);
    cout << "\nProcessing Withdrawal Txn: " << withdrawal1->getTransactionId() << " at " << withdrawal1->getTimestamp() << endl;
    withdrawal1->processTransaction();
    ca1->getBalance();
    
    // c. Transfer funds from Savings to Checking
    auto transfer1 = make_shared<Transfer>("TXN003", 1000.0, sa1, ca1);
    cout << "\nProcessing Transfer Txn: " << transfer1->getTransactionId() << " at " << transfer1->getTimestamp() << endl;
    transfer1->processTransaction();
    sa1->getBalance();
    ca1->getBalance();
    
    // d. Attempt to withdraw more than balance + overdraft
    cout << "\nAttempting to overdraw from checking account..." << endl;
    ca1->withdraw(2500.0);
    ca1->getBalance();
    
    // e. Call a subclass-specific method
    cout << "\nApplying interest to savings account..." << endl;
    cout << "Interest rate is: " << sa1->getInterestRate() << "%" << endl;
    // applyInterest already calls deposit, so we call it directly.
    sa1->applyInterest(); 
    sa1->getBalance();

    // f. Transfer funds from Customer 1 to Customer 2 (Inter-customer transfer)
    cout << "\nTransferring funds from " << customer1->getUsername() << " to " << customer2->getUsername() << "..." << endl;
    cout << "Before transfer - " << customer2->getUsername() << "'s savings account balance:" << endl;
    sa2->getBalance();
    
    auto interCustomerTransfer = make_shared<Transfer>("TXN004", 500.0, sa1, sa2);
    cout << "\nProcessing Inter-Customer Transfer Txn: " << interCustomerTransfer->getTransactionId() << " at " << interCustomerTransfer->getTimestamp() << endl;
    interCustomerTransfer->processTransaction();
    
    cout << "\nAfter transfer - Updated balances:" << endl;
    cout << customer1->getUsername() << "'s savings account:" << endl;
    sa1->getBalance();
    cout << customer2->getUsername() << "'s savings account:" << endl;
    sa2->getBalance();

    cout << "\n----------------------------------\n" << endl;
    customer1->logout();
    customer2->logout();
    cout << "--- Banking System Demo End ---" << endl;

    return 0;
}