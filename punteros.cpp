#include <iostream>
using namespace std;


int main(){
    int primervalor, segundovalor;
    int *mipuntero;

    mipuntero = &primervalor;
    *mipuntero = 10;

    mipuntero = &segundovalor;
    *mipuntero = 20;
    cout << "Mi primer valor es " << primervalor << endl;
    cout << "Mi segundo valor es " << segundovalor << endl;
    return 0;
}