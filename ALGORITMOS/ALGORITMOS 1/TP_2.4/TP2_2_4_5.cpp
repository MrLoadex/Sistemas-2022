#include <iostream>
using namespace std;

int main()
{
    int numero, aux;
    cout << "Ingrese un numero: ";
    cin >> numero;
    while (aux <= numero)
    {
        if (aux != numero)
        {
            cout << aux << ", ";
        }
        else
        {
            cout << aux;
        }
        aux ++;
    }

    return 0;
}