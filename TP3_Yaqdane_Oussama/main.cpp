#include <iostream>

using namespace std;

#ifndef EXO
    #define EXO 3
#endif


#if EXO == 1
int main(){
    int tab[10] ={0, 1, 2, 3,4,5,6,7,8, 9};
    cout << "The size of tab is: "<<sizeof(tab) <<endl;
    cout << "The size of an element of the tab is: "<<sizeof(*tab) <<endl;
    cout << "The number of elements of tab is: "<< sizeof(tab)/sizeof(*tab) <<endl;
}


#elif EXO == 2
const int small_tariff = 250;
const int big_tariff = 350;
const float tax = 0.06;
const int validity = 30;
int main(){
    int small_num, big_num;
    cout<< "Enter the number of small items, then, separated by a space, the number of big ones: ";
    cin >> small_num >> big_num;
    cout << "Number of small rooms: " << small_num << endl;
    cout << "Number of big rooms: " << big_num << endl;
    cout << "Price per small room: " << small_tariff << endl;
    cout << "Price per big room: " << big_tariff << endl;
    int total = small_num*small_tariff + big_num*big_tariff;
    cout << "Cost: " << total << endl;
    cout << "Tax: " << total*tax << endl;
    cout << "============================================" <<endl;
    float total7 = total*(1+tax);
    cout << "Total estimate: " << total7 <<endl;
    cout << "This estimate is valid for " << validity << " days" <<endl;



}


#elif EXO == 3
constexpr int factorial(int n, int a=1){
    return n <= 1 ? a : factorial(n-1, a*n);
}

int main(){
    constexpr int fact_5 = factorial(5);
    static_assert(fact_5 == 120, "Wrong value.");
    cout << fact_5 << endl;
}

#elif EXO == 4

int value = 5;

int main(){
    int value = 10;
    {
        
    }
    cout << "Local value: "<< value <<endl;
    cout << "Global value: "<<::value <<endl;
}


#elif EXO == 5


int main(){
    const int MONTHS_IN_YEAR = 12;
    cout << "Number of months in a year: " << MONTHS_IN_YEAR << endl;

    constexpr int CIRCLE_RADIUS = 7;
    cout << "Radius of the circle is: " << CIRCLE_RADIUS << endl;

    double circle_area = pow(CIRCLE_RADIUS, 2) * PI;
    cout << "The area of the circle is: " << circle_area << endl;
}


#elif EXO == 6
int safeMultiply(int a,int b){
    if (a == 0 || b == 0) {
        return 0; 
    }
    int minn = std::numeric_limits<int>::min();
    int maxx = std::numeric_limits<int>::max();
    if (a>0 && b>0 && a>maxx/b) return -1;
    if (a>0 && b<0 && b<minn/a) return -1;
    if (a<0 && b>0 && a<minn/b) return -1;
    if (a<0 && b<0 && a<maxx/b) return -1;
    return a*b;
}
int main(){
    int num1 = 30000;
    int num2 = 1000;
    cout << safeMultiply(num1, num2) << endl;
    
    num1 = 300000;
    num2 = 1000000;
    cout << safeMultiply(num1, num2) << endl;
}


#endif
