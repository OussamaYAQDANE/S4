#include <iostream>

#ifndef EXO
    #define EXO 1
#endif


#if EXO == 1
int main(){
    std::cout << "Hello, World!" << std::endl <<"Bienvenue en C++" << std::endl;
}
#elif EXO == 2
int main(){
    int x;
    std::cout << "Entrer un nombre: ";
    std::cin >> x;
    std::cout << std::endl << "Vous avez entré: "<<x;
}
#elif EXO == 3
int main(){
    int x, y;
    std::cout << "Entrer deux nombres: ";
    std::cin >> x >> y;
    std::cout << x << y;
    std::cout << "Somme: " << x+y << std::endl;
    std::cout << "Difference: " << x-y << std::endl;
    std::cout << "Produit: " << x*y << std::endl;
    if (y != 0){
        std::cout << "Quotient: " << x/y << std::endl;

    }
    else{
        std::cout << "Erreur: Division par 0" << std::endl;
    }
}
#elif EXO == 4
int main(){
    std::cout << "Entrez un nombre:";
    int nombre;
    std::cin >> nombre;
    std::cout << "Vous avez entré: " << nombre << std::endl;
    return 0;
}
#elif EXO == 5
int main(){
    int C;
    std::cout << "Entrer la température en Celisius: ";
    std::cin >> C;
    std::cout << "La température en Fahrenheit: " << 9*C/5 + 32;
     
}
#endif
