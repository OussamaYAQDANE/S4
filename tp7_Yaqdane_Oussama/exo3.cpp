#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int score;

    

public:
    Person(string name, int score): name(name), score(score){
        cout << "New person was born!" << endl << "Nom: " << name << ", Score: " << score<<endl;

    };
    ~Person(){
        cout << name << " died :(" << endl;
    }

    string get_name(){
        return this->name;
    }

    int get_score(){
        return (*this).score;
    }

    void add_score(int x){
        score += x;
    }


};

int main(){
    Person* person = new Person("Oussama", 0);
    delete person;

}