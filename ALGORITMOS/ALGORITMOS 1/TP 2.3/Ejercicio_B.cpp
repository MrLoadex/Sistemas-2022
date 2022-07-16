#include <iostream>
using namespace std;

int main()
{
double laboratorio,teoria,practica,promedio; //30% 60% 10%
cout << "Introduzca la primer nota: ";
cin >> laboratorio;
cout << "Introduzca la segunda nota: ";
cin >> teoria;
cout << "Introduzca la tercer nota: ";
cin >> practica;
promedio = (0.30 * laboratorio) + (0.60 * teoria) + (0.10 * promedio);
cout <<"El promedio de sus calificaciones es " << promedio;
 //Lineas necesarias para detener el cierre de ventana en Microsoft  Windows
    cin.ignore();
    cin.get();
    return 0;
}
