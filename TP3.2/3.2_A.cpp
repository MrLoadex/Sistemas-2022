#include <iostream>
using namespace std;
//centímetros a pulgadas Celsius a Farenheit y libras a kilogramos
float Centimetros_a_Pulgadas(float cm);
float Celsius_a_Farenheit(float celsius);
float Libras_a_Kg(float libras);
int Seleccionar (int select);

int main ()
{
    int opcion = 1;
    while (opcion != 0){
        cout << "Seleccione una opcion: \n" <<
        "1 Para convertir Centimetros a Pulgadas.\n"<<
        "2 Para convertir Celcius a Farenheit.\n"<<
        "3 Para convertir Libras a Kilogramos.\n"<<
        "0 Para salir.\n";
        cin >> opcion;
        Seleccionar(opcion);
    }
    return 0;
}

float Centimetros_a_Pulgadas(float cm){//divide el valor de longitud entre 2.54
    float pulgadas;
    pulgadas = cm / 2.54;
    return  pulgadas;
}

float Celsius_a_Farenheit(float celsius){//( °C × 9/5) + 32 = F
    float farenheit;
    farenheit = (celsius*9/5)+32;
    return farenheit;
}

float Libras_a_Kg(float libras){//divide el valor de masa entre 2.205
    float kilogramos;
    kilogramos = libras / 2.205;
    return kilogramos;
}

int Seleccionar(int select){
    if (select == 1){
        float centimetros, pulgadas;
        cout << "Centimetros: ";
        cin >> centimetros;
        pulgadas = Centimetros_a_Pulgadas(centimetros);
        cout << centimetros <<" centimetros son " << pulgadas << "pulgadas.\n \n";
    }
    else if (select == 2){
        float celsius, farenheit;
        cout << "Celsius: ";
        cin >> celsius;
        farenheit = Celsius_a_Farenheit(celsius);
        cout << celsius <<" grados celsius son " << farenheit << "grados farenheit.\n \n";
    }
    else if (select == 3){
        float libras, kg;
        cout << "Libras: ";
        cin >> libras;
        kg = Libras_a_Kg(libras);
        cout << libras <<" libras son " << kg << " Kilogramos.\n \n";
    }
    return 0;
}