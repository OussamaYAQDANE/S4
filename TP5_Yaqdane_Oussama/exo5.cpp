#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    string phrase;
    cout << "Enter a phrase: ";
    getline(cin, phrase);
    
    istringstream str(phrase);
    stringstream ss;

    multimap<int, string> len_str;

    while (str >> phrase){
        len_str.insert({phrase.size(), phrase});
    }

    for_each(len_str.cbegin(), len_str.cend(), [&ss](pair<int, string> p){
        ss << p.second << " ";
    });

    cout << "Trie par longuer: "<< ss.str() << endl;

    cout << endl;
    cout << "======================EXO6==========================" << endl;
    cout << endl;

}