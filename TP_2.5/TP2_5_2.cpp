#include <iostream>
#include <cmath>
using namespace std;
float al_cuadrado(float num);

int main()
{
    float num, elevar;
    cout << "Ingrese un numero:";
    cin >> num;
    elevar = al_cuadrado(num);
    cout << num << "elevado al cuadrado: " << elevar;
    return 0;
}

float al_cuadrado(float num)
{
    float resultado = pow(num,2);
    return resultado;
}