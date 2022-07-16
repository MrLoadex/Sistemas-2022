#include <iostream>
using namespace std;
#include <cmath>
int main ()
{
    double radio= 14.5, altura = 26.79, pi = 3.14;
    double volumen = (pi*pow(radio, 2)/altura)/3;
    cout << "El volumen del cono, con radio de base 14,5 y una altura de 26,79 es de " << volumen << endl;
    //Lineas necesarias para detener el cierre de ventana en Microsoft  Windows
    cin.ignore();
    cin.get();
    return 0;
}