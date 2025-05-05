#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){


    vector<int> numbers = {10,20,30,40,50};
    cout << "For values = [10,20,30,40,50]" << endl;
    transform(numbers.begin(),numbers.end(),numbers.begin(),[](int x){return x+5;});
    for (int x : numbers) {
        std::cout << x << " ";
    }
    cout << endl;

    return 0;
}