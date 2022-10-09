#include "listdin.h"
#ifndef iostream
    #include <iostream>
    #include <fstream>
    #include <string>
#endif
using namespace std;

int n = 10;
int *p = new int[n];

void FillDinamicVector()
{
    int entered_number;
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el numero " << i + 1 << " de " << n << endl;
        cout << "Numero: ";
        cin >> entered_number;
        p[i] = entered_number;
    }
}
void OrderDinamicVector()
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        //Comprueba que el dato de la ubicacion mas chica sea mayor al de la ubicacion mas grande
        for (int pos = i; pos < n; pos ++)
        {
            if (p[i] > p[pos]) // pi4 pos ppos 3
            {
                aux = p[i];
                p[i] = p[pos];
                p[pos] = aux; 
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << ", ";
    }
    cout << endl;
    
}


void DeletedinamicArray()
{
    delete p;
    cout << "Lista dinamica eliminada." << endl;
}
