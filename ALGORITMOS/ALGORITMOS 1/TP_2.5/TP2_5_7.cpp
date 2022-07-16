#include <iostream>
using namespace std;
double cambio(int pesos);

int main()
{
    int pesos;
    double dolares;
    cout << "Ingrese valor entero, en pesos: " << endl;
    cin >> pesos;
    dolares =cambio(pesos);
    cout << "Al cambio de 203.5 le quedan USD " << dolares << endl;
    return 0;
}

double cambio(int pesos)
{
    double dolares;
    dolares = pesos / 203.5;
    return dolares;
}