#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int score;

    

public:
    Person(string name, int score): name(name), score(score){
        cout << "Personne: " << name << " dynamically created." << endl;
    };

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

    cout << "Name: " <<person->get_name() << endl;
    cout << "Score: " <<person->get_score() << endl;

    cout << "Personne dynamically allocated (" << person -> get_name() << ") destroyed." << endl;
    delete person; 
    

}