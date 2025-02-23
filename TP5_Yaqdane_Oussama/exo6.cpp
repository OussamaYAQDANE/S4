#include <regex>
#include <iostream>

using namespace std;

int main(){
    cout << "Enter an email address: ";
    std::regex email_pattern("^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    string mail;

    getline(cin, mail);

    if (regex_match(mail, email_pattern)){
        cout << "Valid email!" << endl;
        cout << endl;
        cout << "====================================================" << endl;
        cout << endl;
        return 0;
    }

    cout << "Invalid email!" << endl;

    cout << endl;
    cout << "====================================================" << endl;
    cout << endl;

}