#pragma once

#include "../Savings_Account/Savings_Account.hpp"
#include <iostream>
#include <string>

class Trust_Account : public Savings_Account {
private:
    // Attributs static constexpr
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;

    // Attribut d'instance
    int num_withdrawals;

public:
    // Constructeur
    Trust_Account();
    Trust_Account(std::string name);
    Trust_Account(std::string name, double balance);

    Trust_Account(std::string name, double balance, double int_rate);

    // Méthodes
    bool deposit(double amount);
    bool withdraw(double amount);

    // Fonction amie pour l'affichage
    friend std::ostream& operator<<(std::ostream& os, const Trust_Account& account);
};
