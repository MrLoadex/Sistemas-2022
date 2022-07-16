#include <iostream>
using namespace std;

int main()
{
    int numero, aux=1, impares = 0, pares = 0;
    cout << "Ingrese un numero moyor a 1: ";
    cin >> numero;
    while (aux <= numero)
    {
        if (aux % 2 != 0)
        {
            impares += 1;
        }
        else
        {
            pares += 1;
        }
        aux ++;
    }
    cout << "Entre 1 y " << numero << " hay " << impares <<" impares y " << pares <<" pares.";
    return 0;
}