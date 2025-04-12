#include "Account_Util.hpp"
#include <iostream>

void display(const vector<Account>& accounts) {
    cout << "\n=== Accounts===========================================" << endl;
    for (const auto& account : accounts)
        cout << account << endl;
}

void deposit(vector<Account>& accounts, double amount) {
    cout << "\n=== Depositing to Accounts =================================" << endl;
    for (auto& account : accounts) {
        if (account.deposit(amount))
            cout << "Deposited " << amount << " to " << account << endl;
        else
            cout << "Failed Deposit of " << amount << " to " << account << endl;
    }
}

void withdraw(vector<Account>& accounts, double amount) {
    cout << "\n=== Withdrawing from Accounts ==============================" << endl;
    for (auto& account : accounts) {
        if (account.withdraw(amount))
            cout << "Withdrew " << amount << " from " << account << endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << account << endl;
    }
}

void display(const vector<Savings_Account>& accounts) {
    cout << "\n=== Savings Accounts=====================================" << endl;
    for (const auto& account : accounts)
        cout << account << endl;
}

void deposit(vector<Savings_Account>& accounts, double amount) {
    cout << "\n=== Depositing to Savings Accounts===========================" << endl;
    for (auto& account : accounts) {
        if (account.deposit(amount))
            cout << "Deposited " << amount << " to " << account << endl;
        else
            cout << "Failed Deposit of " << amount << " to " << account << endl;
    }
}

void withdraw(vector<Savings_Account>& accounts, double amount) {
    cout << "\n=== Withdrawing from Savings Accounts=======================" << endl;
    for (auto& account : accounts) {
        if (account.withdraw(amount))
            cout << "Withdrew " << amount << " from " << account << endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << account << endl;
    }
}

void display(const vector<Checking_Account>& accounts) {
    cout << "\n=== Checking Accounts=====================================" << endl;
    for (const auto& account : accounts)
        cout << account << endl;
}

void deposit(vector<Checking_Account>& accounts, double amount) {
    cout << "\n=== Depositing to Checking Accounts===========================" << endl;
    for (auto& account : accounts) {
        if (account.deposit(amount))
            cout << "Deposited " << amount << " to " << account << endl;
        else
            cout << "Failed Deposit of " << amount << " to " << account << endl;
    }
}

void withdraw(vector<Checking_Account>& accounts, double amount) {
    cout << "\n=== Withdrawing from Checking Accounts=======================" << endl;
    for (auto& account : accounts) {
        if (account.withdraw(amount))
            cout << "Withdrew " << amount << " from " << account << endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << account << endl;
    }
}

// Utility functions for Trust_Account class
void display(const vector<Trust_Account>& accounts) {
    cout << "\n=== Trust Accounts=====================================" << endl;
    for (const auto& account : accounts)
        cout << account << endl;
}

void deposit(vector<Trust_Account>& accounts, double amount) {
    cout << "\n=== Depositing to Trust Accounts===========================" << endl;
    for (auto& account : accounts) {
        if (account.deposit(amount))
            cout << "Deposited " << amount << " to " << account << endl;
        else
            cout << "Failed Deposit of " << amount << " to " << account << endl;
    }
}

void withdraw(vector<Trust_Account>& accounts, double amount) {
    cout << "\n=== Withdrawing from Trust Accounts=======================" << endl;
    for (auto& account : accounts) {
        if (account.withdraw(amount))
            cout << "Withdrew " << amount << " from " << account << endl;
        else
            cout << "Failed Withdrawal of " << amount << " from " << account << endl;
    }
}