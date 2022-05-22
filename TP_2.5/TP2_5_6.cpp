#include <iostream>
using namespace std;

int main()
{
    int n1,n2,aux;
    cout <<"Introduzca un entero: ";
    cin >> n1;
    cout <<"Introduzca otro entero: ";
    cin >> n2;
    aux = n1;
    n1 = n2;
    n2 = aux;
    cout << n1 << n2 << endl;
    return 0;
}