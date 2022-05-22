#include <iostream>
using namespace std;

int main()
{
    double num, resultado;
    int aux;
    cout <<"Ingrese un numero fraccionario: ";
    cin >> num;
    aux = num;
    resultado = num - aux;
    cout << "La parte fraccionaria de su numero es: " << resultado << endl;
    return 0;
}