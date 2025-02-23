#include <iostream>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string phrase;
    int n =3; // TOP n frequent words
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

    vector<pair<string, int>> vect;
    vect.resize(map.size());

    for_each(map.begin(), map.end(), [&vect](const pair<string, int>& x){
        vect.push_back({x.first, x.second});
    });

    sort(vect.begin(), vect.end(), [](const pair<string, int>& x, const pair<string, int>& y){
        return x.second > y.second;
    });
    
    for_each(vect.begin(), vect.begin() + n, [](const pair<string, int>& x){
        cout << x.first << "-->" << x.second << endl;
    });

    cout << endl;
    cout << "======================EXO5==========================" << endl;
    cout << endl;

    return 0;
}