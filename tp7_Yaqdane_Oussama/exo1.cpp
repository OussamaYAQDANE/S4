#include <iostream>

using namespace std;

class Joueur
{
private:
    string name;
    int score;

public:
    Joueur(string name, int score): name(name), score(score){
        cout << "New player constructed!" << endl;
    };

    string get_name(){
        return name;
    }

    int get_score(){
        return score;
    }

    void add_score(int x){
        score += x;
    }

};

int main(){
    Joueur player1("Oussama", 0);

    cout << "player1's name: "<< player1.get_name()<< ", player1's current score: "<< player1.get_score() << endl;

    cout << "Adding 15 points to player1..." << endl;
    player1.add_score(15);

    cout << "player1's name: "<< player1.get_name()<< ", player1's current score: "<< player1.get_score() << endl;

}