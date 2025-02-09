#ifndef EXO
    #define EXO 1
#endif


#if EXO == 1
#include <iostream>
#define PI 3.1415

int main(){
    #ifdef DEBUG
    std::cout << "Debug mode is on" << std::endl;
    #endif
}

#elif EXO == 2
#include <iostream>

int main(int argc, char* argv[]){
    for (int i = 1; i<argc; i++) std::cout << "Argument " << i << " : "<< *(argv+i) << std::endl;
}
#elif EXO == 3
#include <iostream>
namespace matt{
    float pi = 3.1415;
}
int main(){
    std::cout << matt::pi << std::endl;
}
#elif EXO == 4
#include <iostream>
using namespace std;
int main(){
    int x;
    float y;

    cout << "Entrer un entier: "; cin >> x;
    cout << "Entrer un nombre à virgule: "; cin >> y;
    cout << "Les nombres entrés sont: "<< x << " et " << y;
}
#endif