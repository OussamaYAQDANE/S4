#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

int main() {
    ofstream out_file("output.txt");
    if (!out_file) {
    cerr << "File opening error!" << endl;
    return 1;
    }
    double num;
    cout << "Enter some floats, enter a NaN to stop: ";
    while (cin >> num) {
    out_file << fixed << setprecision(1) << setw(15) <<right << num << endl;
    }
    out_file.close();
    cout << "Output.txt file was generated" << endl;
    return 0;
}