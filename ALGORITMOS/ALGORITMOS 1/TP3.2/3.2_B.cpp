#include <iostream>
using namespace std;

int main ()
{
    int salario;
    cout << "Ingrese su salario: ";
    cin >> salario;

    if (salario <= 9000){
        salario = salario * 120 / 100;
    }
    else if (salario > 9000 && salario < 15000){
        salario = salario * 110 / 100;
    }
    else if (salario > 15000 && salario < 20000){
        salario = salario * 105 / 100;
    }
    else{
        salario = salario * 103 / 100;
    }
    cout << "Su actual salario es " << salario;
    return 0;
}