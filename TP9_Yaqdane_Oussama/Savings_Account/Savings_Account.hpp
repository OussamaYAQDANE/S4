#pragma once

#include <iostream>
#include "../Account/Account.hpp"
#include <string>


class Savings_Account: public Account{
private:
    static constexpr double def_int_rate = 0.1;
public:
    double int_rate;

    Savings_Account(std::string name, double balance, double int_rate);
    Savings_Account(std::string name, double balance);
    Savings_Account(std::string name);
    Savings_Account();
    bool deposit(double amount);
    friend std::ostream& operator<<(std::ostream& out,const Savings_Account& other);
};