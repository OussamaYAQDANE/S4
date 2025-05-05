#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Adder
{
private:
    int value;
public:
    Adder(int value): value(value){}
    void operator()(const int& a){
        cout << a + value << endl;
    }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    Adder add(10);
    for_each(numbers.begin(), numbers.end(), add);
    
    return 0;
}
