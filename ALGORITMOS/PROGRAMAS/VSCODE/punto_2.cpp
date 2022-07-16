/*Resolver usando Variables y operadores, mostrar el resultado por pantalla.
Calcula el volumen, de una habitación que tiene 5 m de largo, 4 m de ancho y 2.5 m de alto.
Escribe un programa en C++ que nos diga cuál es el volumen de un cono con un radio de la base de 14,5 y una altura de 26,79. La fórmula que debes usar es: (Pi x (radio)2 / altura) /3, recordar Pi=3.14.
¿Modificar el programa anterior para que usen variables Dobles, qué diferencia nota? ¿Por qué?
*/

#include <iostream>
using namespace std;
int main ()
{
    double largo, ancho, alto;
    largo = 5;
    ancho = 4;
    alto = 2.5;
    cout << "Su habitacion que mide 5 metros de largo, por 4 metros de ancho por 2.5 metros de alto posee un volumen de " << alto * ancho * alto << " metros." << endl;
    //Lineas necesarias para detener el cierre de ventana en Microsoft  Windows
    cin.ignore();
    cin.get();
    return 0;
}