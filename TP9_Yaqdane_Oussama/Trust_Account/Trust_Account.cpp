#include "Trust_Account.hpp"

// Constructeur
Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, num_withdrawals{0} {}

    Trust_Account::Trust_Account()
    : Savings_Account{} {};

Trust_Account::Trust_Account(string name) 
    : Savings_Account{name} {};

Trust_Account::Trust_Account(string name, double balance) 
    : Savings_Account{name, balance} {};


// Méthode deposit
bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold) {
        amount += bonus_amount; // Ajoute un bonus de 50 si le dépôt est >= 5000
    }
    return Savings_Account::deposit(amount); // Appelle la méthode de la classe de base
}

// Méthode withdraw
bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= max_withdrawals || amount > max_withdraw_percent * balance) {
        return false; // Échec si limite de retraits atteinte ou montant > 20% du solde
    }
    bool success = Savings_Account::withdraw(amount); // Tente le retrait via la classe de base
    if (success) {
        num_withdrawals++; // Incrémente le compteur si le retrait réussit
    }
    return success;
}

// Opérateur d'affichage
std::ostream& operator<<(std::ostream& os, const Trust_Account& account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance
       << ", " << account.int_rate << "%, Retraits: " << account.num_withdrawals << "]";
    return os;
}