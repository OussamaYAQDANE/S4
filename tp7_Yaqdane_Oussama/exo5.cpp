#include <iostream>
#include <vector>
using namespace std;

class Etudiant {
    string nom;
    vector<int> notes;
public:
    Etudiant(string n, vector<int> ns) : nom(n), notes(ns) {}
    double calculerMoyenne() {
        int somme = 0;
        for (int note : notes) somme += note;
        return static_cast<double>(somme) / notes.size();
    }
    void afficher() {
        cout << "Nom: " << nom << "\nNotes: ";
        for (int note : notes) cout << note << " ";
        cout << "\nMoyenne: " << calculerMoyenne() << endl;
    }
};

int main() {
    Etudiant etudiant("Karim", {15, 18, 12});
    etudiant.afficher();
    return 0;
}