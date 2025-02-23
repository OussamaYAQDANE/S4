#include <iostream>
#include <unordered_map>
#include <sstream>


using namespace std;

int main(){
    string phrase;
    cout << "Enter a phrase: ";
    getline(cin, phrase);

    stringstream ss;
    
    string::iterator i(phrase.begin());
    string::iterator j(phrase.begin());
    string::iterator end(phrase.end());

    while (j!=end){
        while (*j == *i && j != end){
            j++;
        }
        ss << *i << static_cast<int>(j-i);
        i = j;
    }

    cout << ss.str() << endl ;
    cout << endl;
    cout << "======================EXO4==========================" << endl;
    cout << endl;
}