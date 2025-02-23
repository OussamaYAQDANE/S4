#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main(){
    string phrase;
    cout << "Enter a phrase: ";
    getline(cin, phrase);
    
    istringstream str(phrase);

    unordered_map<string, int> map;

    while (str >> phrase){
        if (map.count(phrase)){
            map[phrase] += 1;
        } else {
            map[phrase] = 1;
        }
    }

    for (pair<string, int> kv : map){
        cout << kv.first << "-->" << kv.second << endl;
    }
    cout << endl;
    cout << "======================EXO3==========================" << endl;
    cout << endl;
    
    return 0;
}