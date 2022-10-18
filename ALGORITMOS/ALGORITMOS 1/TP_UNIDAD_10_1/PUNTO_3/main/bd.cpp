#include <iostream>
#include "../cuadrilatero/cuadrilatero.h"
using namespace std;

void OptionSelector();

int main()
{
    cuadrilatero rectangulo;
    rectangulo.SetAltura(10);
    rectangulo.SetBase(5.5);
    
    cout << "su rectangulo de: " << rectangulo.GetAltura() << " de altura y " << rectangulo.GetBase() << "de base." << endl;
    cout << "Tiene una area de: " << rectangulo.area() << endl;
    cout << "Tiene un perimetro de: " << rectangulo.perimetro() << endl;

    system("pause");
    system("cls");
    return 0;
}
