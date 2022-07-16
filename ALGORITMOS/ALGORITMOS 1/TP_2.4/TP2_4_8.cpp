#include <iostream>
using namespace std;

int main()
{
    int numero, total;
    while (numero >= 0)
    {
        cout << "Ingrese un numero positivo: ";
        cin >> numero;
        total += numero;
    }
    cout << "La suma de los numeros ingresados (contando el negativo) es: " << total;
    return 0;
}