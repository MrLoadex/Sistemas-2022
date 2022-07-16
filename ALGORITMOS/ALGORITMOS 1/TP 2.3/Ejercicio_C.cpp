#include <iostream>
using namespace std;

int main()
{
    int select;
    double volumen;
    cout << "Superficies" << endl <<"Selecciona 1 para cuadrado, 2 para rectangulo o 3 para triangulo: ";
    cin >> select;
    //volumen del cuadrado:
    if (select ==1){
        cout <<"Ingrese la longitud del lado de su cuadrado, en cm por favor: ";
        double lado;
        cin >> lado;
        volumen = lado * lado * lado;
        cout << "El volumen de su cuadrado es "<< volumen;
    }
    //volumen del cuadrado:
    else if (select ==2){
        double l, w;
        cout <<"Ingrese la longitud, en cm por favor: ";
        cin >> l;
        cout <<"Ingrese el ancho de su rectangulo, en cm por favor: ";
        cin>> w;
        volumen = 2 * l + 2 * w;
        cout << "El volumen de su rectangulo es "<< volumen;
    }
    // Volumen del triangulo:
    else if (select ==3){
        double a, b, c;
        cout <<"Ingrese la longitud de la base, en cm por favor: ";
        cin >> a;
        cout <<"Ingrese la longitud de un lado, en cm por favor: ";
        cin>> b;
        cout <<"Ingrese la longitud del ultimo lado, en cm por favor: ";
        cin >> c;
        volumen = a+b+c;
        cout << "El volumen de su triangulo es "<< volumen;
    }

    //Lineas necesarias para detener el cierre de ventana en Microsoft  Windows
        cin.ignore();
        cin.get();
        return 0;
}