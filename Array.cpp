int main() {
    // Crear el array
    int numeros[] = {1, 7, 17, 177};
    int sumaTotal = 0;
 
    // Calcular la suma de los elementos
    for (int i = 0; i < 4; i++) {
        sumaTotal += numeros[i];
    }
 
    // Imprimir los resultados
    cout << "Array: ";<<
    for (int i = 0; i < 4; i++) {
        cout << numeros[i];
        if (i < 3) cout << ", ";
    }
    cout << endl;
    cout << "Suma total: " << sumaTotal << endl;
 
    return 0;
}   