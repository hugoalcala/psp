#include <iostream>
using namespace std;

int main() {
    int a = 3 , b = 5, c = 7;
    int resultado;
    resultado =  (c > 0) ?(a*b) : (a + b);
    cout << "El resultado es: " << resultado << endl;
    return 0;
}