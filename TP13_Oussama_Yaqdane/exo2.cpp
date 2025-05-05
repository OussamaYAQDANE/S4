#include <iostream>
#include <vector>
#include<functional>
using namespace std;

void filter(vector<int>& vect, function<bool(int)> filter){
    for (auto it = vect.begin(); it != vect.end(); it++){
        if (filter(*it)){
            cout << *it << " ";
        }
    }
    cout << endl;
}
int main() {
    vector<int> numbers = {10, 15, 20, 25, 30, 50, 75};

    cout << "Filter: x > 20 " << endl;
    filter(numbers, [](int x) { return x > 20; });

    cout << endl << "Filter: x % 2 == 0 " << endl;
    filter(numbers, [](int x) { return x % 2 == 0; });

    return 0;
}
