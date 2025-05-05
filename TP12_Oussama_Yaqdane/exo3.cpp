#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream filtered_input("filtered_input_by_keyword.txt");

    if (!input || !filtered_input){
        cerr << "Error opening / creating files!" << endl;
        return 1;
    }
    string keyword;
    cout << "Enter your keyword (choose '<mark>' for example): " << endl;
    cin >> keyword;
    string s;
    while (getline(input, s)){
        if(s.find(keyword) != string::npos){
            filtered_input << s << endl;
        }
    }
    input.close();
    filtered_input.close();

}