#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
    cout << endl;
    cout << "======================EXO1==========================" << endl;
    cout << endl;
    string pal;
    cout << "Enter a phrase: ";
    getline(cin, pal);
    string original_str = pal;
    pal.erase(std::remove_if(pal.begin(), pal.end(), [](char& c){c = tolower(c); return isspace(c);}), pal.end());
    string pal2 = pal;
    
    reverse(pal2.begin(), pal2.end());
    if (pal2 == pal){
        cout << '"' << original_str << '"' << " is " << "a palindrom!" << endl;
    } else{
        cout << '"' << original_str << '"' << " is not " << "a palindrom!" << endl;
    }
    cout << endl;
    cout << "======================EXO2==========================" << endl;
    cout << endl;
}