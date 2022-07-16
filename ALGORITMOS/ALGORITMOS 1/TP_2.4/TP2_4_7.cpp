#include <iostream>
using namespace std;

int main()
{
    int num1,num2;
    cout << "Ingrese un numero entero:";
    cin >> num1;
    cout << "Ingrese otro numero entnero:";
    cin >> num2;
    while (num2<=num1)
    {
        cout << "El segundo numero debe ser mayor al primero.\nIngrerselo nuevamente:" << endl;
        cin >> num2;
    }
    cout << "Los numeros ingresados son " << num1 << " y " << num2;
    return 0;
}