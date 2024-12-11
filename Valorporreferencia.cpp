#include <iostream>
using namespace std;

void incrementar(int &valor){
    valor++;
}
int main(){
    int numero = 5;
    std:: cout << "Antes de la función: " << numero << std :: endl;

    incrementar(numero);

    std:: cout <<"Despues de la funcion: " << numero << std :: endl;

    return 0;
} 