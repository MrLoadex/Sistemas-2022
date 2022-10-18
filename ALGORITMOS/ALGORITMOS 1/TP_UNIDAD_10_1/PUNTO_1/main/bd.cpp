#include <iostream>
#include "../articulo/articulo.h"
using namespace std;

void OptionSelector();

int main()
{
    articulo articulo1;
    articulo1.SetCostoBase(123.3);
    articulo1.~articulo();
    
    cout << "Su producto tiene un costo base de " << articulo1.GetCostoBase()<<
    " un precio a por mayor de " << articulo1.PVPMayor() <<
    " y un precio al por menor de " <<articulo1.PVPDetal() << endl;

    system("pause");
    system("cls");
    return 0;
}
