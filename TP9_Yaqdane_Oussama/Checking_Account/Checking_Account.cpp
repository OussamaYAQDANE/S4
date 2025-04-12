#include "./Checking_Account.hpp"

Checking_Account::Checking_Account(string name, double balance)
    :Account{name,balance} {};
Checking_Account::Checking_Account()
    :Account{} {};
Checking_Account::Checking_Account(string name)
    :Account{name} {};

bool Checking_Account::withdraw(double amount){
    amount+= per_check_fee;
    return Account::withdraw(amount);
}
ostream &operator<<(ostream &os, const Checking_Account &account){
    os << "[Checking Account: " << account.name << ": " << account.balance <<" ]";
    return os;
};