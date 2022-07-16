#include <iostream>
using namespace std;
int main ()
{
    int edad;
    char sexo;
    double altura;
    cout << "Que edad tienes? ";
    cin >> edad;
    cout << "Cual es tu sexo (M= Masculino, F= Femenino)? ";
    cin >> sexo;
    cout << "Cual es su altura?(en metros) ";
    cin >> altura;
    if (sexo == 'f' or sexo == 'F'){
        cout << cout << "Usted tiene "<< edad << " años de edad, es de sexo femenino, y mide " << altura << " metros.";
    }
    else{
        cout << "Usted tiene "<< edad << " años de edad, es de sexo masculino, y mide " << altura << " metros.";
    }
        //Lineas necesarias para detener el cierre de ventana en Microsoft  Windows
    cin.ignore();
    cin.get();
    return 0;
}