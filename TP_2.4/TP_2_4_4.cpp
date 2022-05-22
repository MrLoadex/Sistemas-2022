#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numero, cantidadDeNumeros=0, total=0;
    string numerosEncadenados;
    cout << "Ingrese tantos numeros como quiera, cuando ponga '99' se detendra" << endl;
    while (numero !=99)
    {
        //CantidadDeNumeros es un contador para hacer el promedio, y total va sumando los numeros
        //ingresados con el mismo proposito
        cantidadDeNumeros ++;
        cin >> numero;
        total += numero;
        //Convertimos el numero en un string para poderlo mostrar despues
        string num_str(to_string(numero));
        //Para darle coherencia a la oracion agregamos un if y luego vamos sumando los numeros ingresados al str
        if (numerosEncadenados != "")
        {
            numerosEncadenados += ", ";
            numerosEncadenados += num_str;
        }
        else
        {
            numerosEncadenados = num_str;
        }
    }
    cout << "Usted ingreso los numeros: " << endl << numerosEncadenados << endl;
    cout << "El promedio es: " << total / cantidadDeNumeros;
    
    return 0;
}