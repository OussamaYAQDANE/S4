#include <string>
#include "./Account.hpp"


using namespace std;

Account::Account(string name, double balance):name(name), balance(balance){}

bool Account::deposit(double amount){
    if(amount <= 0){
        return false;
    }
    balance += amount;
    return true;
}
bool Account::withdraw(double amount){
    if (balance >= amount){
        balance -= amount;
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Account& acc) {
    out << "Account[ " << acc.name << ": " << acc.balance << " ]";
    return out;
}