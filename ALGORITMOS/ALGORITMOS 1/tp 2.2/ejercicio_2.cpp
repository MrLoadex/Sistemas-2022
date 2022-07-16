#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
int main ()
{//Solicita fecha de nacimiento e imprime edad.
    int year, old;
    cout <<"Año de nacimiento: ";
    cin >> year;
    old = 2022 - year;    
    cout <<"Usted tiene " << old << " años de edad." << endl; 

    //Solicita tres numeros e imprime el promedio.
    double d1,d2,d3, average;
    cout << "Ingrese el dato 1: ";
    cin >> d1;
    cout << "Ingrese el dato 2: ";
    cin >> d2;
    cout << "Ingrese el dato 3: ";
    cin >> d3;
    average = (d1+d2+d3) / 3;
    cout << "El promedio es " << average <<"." << endl;

    //Multiplica 4 numeros.
    int d4, resultado;
    cout << "Ingrese el primer numero: ";
    cin >> d1;
    cout << "Ingrese el segundo numero: ";
    cin >> d2;
    cout << "Ingrese el tercer numero: ";
    cin >> d3;
    cout << "Ingrese elcuarto numero: ";
    cin >> d4;
    resultado = d1*d2*d3*d4;
    cout << "El producto de sus cuatro numeros es: "<< resultado << endl;

    //Calcula la superficie de un cono utilizando PI * Radio al cuadrado * altura)/3.
    double radio = 14.5, altura = 26.79, volumen;
    volumen = (3.141592* pow(radio,2)*altura)/3;
    cout << 'La superficie de un cono con una base de 14.5cm de radio y una altura de 26.79cm es: ' << volumen << endl;

    //Lee grados en Fahrenheit y los pasa a Celsius utilizando esta formula ºC = 5 / 9 x (ºF ‐ 32)

    double fharenheit, celsius;
    cout << "Ingrese su temperatura en grados fharenheit: ";
    cin >> fharenheit;
    celsius = 5/9*(fharenheit-32);
    cout << fharenheit <<"en grados Celsius es "<< celsius << endl;
    
    //Pide algunos numeros y luego da una hora.
    int segundos, minutos, horas;
    cout << 'Horas: ';
    cin >> horas;
    cout << 'Minutos: ';
    cin >> minutos;
    cout << 'Segundos: ';
    cin >> segundos;
    cout <<'La hora ingresada es: '<< horas << ':' << minutos << ':' << segundos << endl;

    //Lineas necesarias para detener el cierre de ventana en Microsoft  Windows
    cin.ignore();
    cin.get();
    return 0;
}