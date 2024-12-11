#include <iostream> // Include the iostream library for input and output 
#define PI 3.14

using namespace std;

int main() {
    float r;
    cout << "Ingrese el radio del circulo: ";
    cin >> r;
    cout << "El area del circulo es: " << PI * r * r << endl;
    return 0;
}