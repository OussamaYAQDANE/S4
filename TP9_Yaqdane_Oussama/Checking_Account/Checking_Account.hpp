#pragma once

#include <iostream>
#include <string>

#include "../Account/Account.hpp"

class Checking_Account : public Account{
    public:
    static constexpr double per_check_fee = 1.50;

    Checking_Account(string name, double balance);
    bool withdraw(double amount);
    friend ostream& operator<<(ostream &os, const Checking_Account &account);
    Checking_Account();
    Checking_Account(string name);


};

