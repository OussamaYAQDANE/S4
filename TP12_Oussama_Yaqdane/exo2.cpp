#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream data("data.txt");
    ofstream output("good_looking_table.txt");

    if (!data || !output){
        cerr<< "Error when opening files" << endl;
        return 1;
    }
    string s;
    output << setw(15) << left << "Name"<< setw(10) << left << "Age"<< setw(15) << right << "Salary" << endl;
    while (getline(data, s))
    {
        istringstream ss(s);
        string name, age;
        double salary;
        ss >> name >> age >> salary;
        output << 
         setw(15) <<left << name <<
        setw(10) <<left << age <<
        right << fixed<< setprecision(2) << setw(15) << salary << endl;
    }
    data.close();
    output.close();
}