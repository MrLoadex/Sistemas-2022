#include <iostream>
using namespace std;
float mult(float num1, float num2);

int main()
{   
    float num1,num2;
    cout <<"Ingrese el primer numero: ";
    cin >> num1;
    cout <<"Ingrese el segundo numero: ";
    cin >> num2;
    float multiplicacion =mult(num1,num2);
    cout << num1 << "X" << num2 << "=" << multiplicacion;
    return 0;
}

float mult(float num1,float num2)
{
    float total = num1 * num2;
    return total;
}