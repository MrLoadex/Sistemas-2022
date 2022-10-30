#include <iostream>
#include "../figura/figura.h"
#include "../circulo/circulo.h"
#include "../rectangulo/rectangulo.h"
#include "../triangulo/triangulo.h"
using namespace std;

int main()
{

    figura *vectorf[5];
    int option = 1;

    for(int i = 0 ; i < 5 ; i ++)
    {
        cout << "Seleccione el primer elemento:"<< endl;
        cout << " 1. Circulo \n 2. Rectangulo \n 3. Triangulo" << endl;
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 1:
            vectorf[i] = new circulo;
            break;
        case 2:
            vectorf[i] = new rectangulo;
            break;
        case 3:
            vectorf[i] = new triangulo;
            break;
        default:
            break;
        }
    }

    cout << "Procederemos a dibujarlos:" << endl;
    for(int i = 0 ; i < 5 ; i ++)
    {
        cout << "la figura uno es un ";
        cout << vectorf[i]->dibujar();
        cout << endl;
        delete vectorf[i];
    }

    system("pause");
    return 0;
}
