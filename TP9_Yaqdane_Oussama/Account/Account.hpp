#pragma once

#include <string>
#include <iostream>
using namespace std;
class Account
{
private:
    static constexpr char def_name[] = "Oussama";
    static constexpr double def_balance = 100;
protected:
    string name;
    double balance;
public:
    Account(string name = def_name, double balance = def_balance);
    bool deposit(double amount);

    bool withdraw(double amount);

    friend ostream& operator<<(ostream&, const Account&);

};
