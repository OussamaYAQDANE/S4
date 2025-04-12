#include "./Savings_Account.hpp"

Savings_Account::Savings_Account(std::string n, double b, double ir){
    name = n;
    balance = b;
    int_rate = ir;
}

Savings_Account::Savings_Account()
    : Account {}, int_rate{def_int_rate} {
};
Savings_Account::Savings_Account(string name)
    : Account {name}, int_rate{def_int_rate} {
};

Savings_Account::Savings_Account(string name, double balance)
    : Account {name,balance}, int_rate{def_int_rate} {
};

bool Savings_Account::deposit(double amount){
    if(amount <= 0){
        return false;
    }
    balance += amount*(1-int_rate);
    return true;
}

std::ostream& operator<<(std::ostream& out, const Savings_Account& acc) {
    out << "Account[ " << acc.name << ": " << acc.balance << " ]";
    return out;
}